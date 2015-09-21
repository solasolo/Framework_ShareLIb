#include "stdafx.h"

#include "DXCompute.h"
#include "CommonFuncs.h"
#include "DXGraphic.h"

#include <D3DX11async.h>

namespace GLEO
{
	ResultBuffer::BufferPack::BufferPack(ID3D11DeviceContextPtr context, ID3D11BufferPtr buffer)
	{
		this->Context = context;
		this->Buffer = buffer;
		this->Data = NULL;
	}

	ResultBuffer::BufferPack::~BufferPack()
	{
		if(this->Context && this->Buffer && this->Data)
		{
			this->Context->Unmap(&this->Buffer, 0);
		}
	}

	void* ResultBuffer::BufferPack::GetData()
	{
		HRESULT hr;
		D3D11_MAPPED_SUBRESOURCE mappedResource;

		if(this->Context && this->Buffer)
		{
			hr = this->Context->Map(&this->Buffer, 0, D3D11_MAP_READ, 0, &mappedResource);
			DXException::Check(hr, L"Map Resourse");

			this->Data = mappedResource.pData;
		}

		return this->Data;
	}

	ResultBuffer::ResultBuffer()
	{
	}

	ResultBuffer::ResultBuffer(ID3D11DeviceContextPtr context, ID3D11BufferPtr buffer)
	{
		this->ShareBuffer = new BufferPack(context ,buffer);
	}

	void* ResultBuffer::GetData()
	{
		return this->ShareBuffer->GetData();
	}
}

namespace GLEO
{

	const IUnknown* NULLInterfaceArray[]  = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

	DXCompute::DXCompute()
	{
		this->CreateDevice(0);
		this->CreateQuery();
	}

	DXCompute::DXCompute(int index)
	{
		this->CreateDevice(index);
		this->CreateQuery();
	}

	DXCompute::~DXCompute(void)
	{
		this->UnbindAllBuffer();
	}

	void DXCompute::CreateQuery()
	{
		HRESULT hr;

		D3D11_QUERY_DESC query_desc;
		query_desc.Query = D3D11_QUERY_EVENT;
		query_desc.MiscFlags = 0;

		ID3D11Query* pQuery = NULL;
		hr = this->Device->CreateQuery(&query_desc, &pQuery);
		DXException::Check(hr, L"Create Query");

		this->Query << pQuery;
	}

	ID3D11ComputeShaderPtr DXCompute::CreateShader(wstring file)
	{
		HRESULT hr;
		ID3D11ComputeShaderPtr Result;

		string Entery = "main";

		ID3DBlobPtr ShaderBinary = this->ComplieShader(file, Entery, ShaderType::CS);

		ID3D11ComputeShader* pShader = NULL;
		hr = this->Device->CreateComputeShader(ShaderBinary->GetBufferPointer(), ShaderBinary->GetBufferSize(), NULL, &pShader );
		DXException::Check(hr, L"Create Shader");

		Result << pShader;

		return Result;
	}

	ID3D11BufferPtr DXCompute::CreateBuffer(BufferType type, void* data, int width, int count)
	{
		HRESULT hr;
		ID3D11BufferPtr Result;

		ID3D11Buffer* pBuffer = NULL;

		D3D11_BUFFER_DESC buf_desc;
		ZeroMemory(&buf_desc, sizeof(buf_desc));

		switch(type)
		{
		case BufferType::Input:
		case BufferType::Output:
			buf_desc.BindFlags = D3D11_BIND_UNORDERED_ACCESS | D3D11_BIND_SHADER_RESOURCE;
			buf_desc.MiscFlags = D3D11_RESOURCE_MISC_BUFFER_STRUCTURED;
			buf_desc.ByteWidth = width * count;
			buf_desc.StructureByteStride = width;

			Result = this->GraphicBaseDevice::CreateBuffer(buf_desc, data);
			break;

		case BufferType::Constant:
			Result = this->GraphicBaseDevice::CreateConstBuffer(data, width);
		}

		return Result;
	}

	ID3D11ShaderResourceViewPtr DXCompute::CreateInputView(ID3D11Buffer* pBuffer, int ElementsSize, int ElementCount)
	{
		HRESULT hr;

		ID3D11ShaderResourceView* pView = NULL;

		D3D11_SHADER_RESOURCE_VIEW_DESC view_desc;
		ZeroMemory(&view_desc, sizeof(view_desc));
		view_desc.ViewDimension = D3D11_SRV_DIMENSION_BUFFEREX;
		view_desc.Format = DXGI_FORMAT_UNKNOWN;
		view_desc.BufferEx.FirstElement = 0;
		view_desc.BufferEx.NumElements = ElementCount;

		hr = this->Device->CreateShaderResourceView(pBuffer, &view_desc, &pView);
		DXException::Check(hr, L"Create SRV");

		ID3D11ShaderResourceViewPtr View = pView;
		SafeRelease(pView);

		return View;
	}

	ID3D11UnorderedAccessViewPtr DXCompute::CreateOutputView(ID3D11Buffer* pBuffer, int ElementsSize, int ElementCount)
	{
		HRESULT hr;

		ID3D11UnorderedAccessView* pView = NULL;

		D3D11_UNORDERED_ACCESS_VIEW_DESC view_desc;
		ZeroMemory(&view_desc, sizeof(view_desc));
		view_desc.ViewDimension = D3D11_UAV_DIMENSION_BUFFER;
		view_desc.Format = DXGI_FORMAT_UNKNOWN;
		view_desc.Buffer.FirstElement = 0;
		view_desc.Buffer.NumElements = ElementCount;

		hr = this->Device->CreateUnorderedAccessView(pBuffer, &view_desc, &pView);
		DXException::Check(hr, L"Create UAV");

		ID3D11UnorderedAccessViewPtr View = pView;
		SafeRelease(pView);

		return View;
	}

	ResultBuffer DXCompute::CopyResult(int index = 0)
	{
		HRESULT hr;
		ID3D11BufferPtr DataBuffer;

		int OutCount = this->OutputBuffers.size();

		if(index < OutCount)
		{
			OutputBufferPackage& item = this->OutputBuffers[index];
			ID3D11BufferPtr src = item.Buffer;

			D3D11_BUFFER_DESC desc;
			ZeroMemory(&desc, sizeof(desc));
			src->GetDesc( &desc );

			unsigned int byteSize = desc.ByteWidth;

			desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
			desc.Usage = D3D11_USAGE_STAGING;
			desc.BindFlags = 0;
			desc.MiscFlags = 0;

			ID3D11Buffer* pBuffer = NULL;

			hr = this->Device->CreateBuffer(&desc, NULL, &pBuffer);
			DXException::Check(hr, L"Create Buffer");

			this->Context->CopyResource(pBuffer, &src);
			DataBuffer = pBuffer;

			SafeRelease(pBuffer);
		}
		else
		{
			// TODO:
		}

		return ResultBuffer(this->Context, DataBuffer);
	}

	void DXCompute::BindAllBuffer()
	{
		HRESULT hr;

		int InCount = this->InputBuffers.size();

		for(int i = 0; i < this->InputBuffers.size(); i++)
		{
			ID3D11ShaderResourceView* view = &(this->InputBuffers[i].View);
			this->Context->CSSetShaderResources( i, 1, &view);
		}

		for(int i = 0; i < this->OutputBuffers.size(); i++)
		{
			ID3D11UnorderedAccessView* view = &(this->OutputBuffers[i].View);
			this->Context->CSSetUnorderedAccessViews( i, 1, &view, NULL);
		}

		for(int i = 0; i < this->ConstantBuffers.size(); i++)
		{
			ID3D11Buffer* buf = &(this->ConstantBuffers[i]);
			this->Context->CSSetConstantBuffers( i, 1, &buf);
		}
	}

	void DXCompute::UnbindAllBuffer()
	{
		HRESULT hr;

		int InCount = this->InputBuffers.size();
		int OutCount = this->OutputBuffers.size();


		if(OutCount > 0)
		{
			this->Context->CSSetUnorderedAccessViews( 0, OutCount, (ID3D11UnorderedAccessView**)NULLInterfaceArray, NULL );
		}

		if(InCount > 0)
		{
			this->Context->CSSetShaderResources( 0, InCount, (ID3D11ShaderResourceView**)NULLInterfaceArray );
		}
	}

	void DXCompute::LoadShader(wstring file, int x, int y, int z)
	{
		ShaderPackage shader;

		shader.Shader =	this->CreateShader(file);
		shader.GroupNumber[0] = x;
		shader.GroupNumber[1] = y;
		shader.GroupNumber[2] = z;

		this->ShaderCollection.push_back(shader);
	}

	int DXCompute::AddInputBuffer(void* data, int ElementSize, int ElementCount)
	{
		ID3D11BufferPtr buffer = this->CreateBuffer(BufferType::Input, data, ElementSize, ElementCount);
		ID3D11ShaderResourceViewPtr view = this->CreateInputView(&buffer, ElementSize, ElementCount);

		InputBufferPackage item;
		item.ElementSize = ElementSize;
		item.ElementCount = ElementCount;
		item.Buffer = buffer;
		item.View = view;

		this->InputBuffers.push_back(item);

		return this->InputBuffers.size() - 1;
	}

	int DXCompute::AddOutputBuffer(int ElementSize, int ElementCount)
	{
		ID3D11BufferPtr buffer = this->CreateBuffer(BufferType::Output, NULL, ElementSize, ElementCount);
		ID3D11UnorderedAccessViewPtr view = this->CreateOutputView(&buffer, ElementSize, ElementCount);

		OutputBufferPackage item;
		item.ElementSize = ElementSize;
		item.ElementCount = ElementCount;
		item.Buffer = buffer;
		item.View = view;

		this->OutputBuffers.push_back(item);

		return this->OutputBuffers.size() - 1;
	}

	void DXCompute::UpdateBuffer(int index, void* data)
	{
		if(index < this->InputBuffers.size())
		{
			InputBufferPackage item = this->InputBuffers[index];

			item.Buffer = this->CreateBuffer(BufferType::Input, data, item.ElementSize, item.ElementCount);
			item.View = this->CreateInputView(&item.Buffer, item.ElementSize, item.ElementCount);

			this->InputBuffers[index] = item;
		}
		else
		{
			// TODO:
		}
	}

	void DXCompute::SetParameter(wstring& key, wstring& value)
	{
	}

	void DXCompute::SetGroup(int index, int x, int y, int z)
	{
		ShaderPackage shader;

		if(index < this->ShaderCollection.size())
		{
			shader = this->ShaderCollection[index];

			shader.GroupNumber[0] = x;
			shader.GroupNumber[1] = y;
			shader.GroupNumber[2] = z;

			this->ShaderCollection[index] = shader;
		}
	}

	void DXCompute::Run(int index)
	{
		if(index < this->ShaderCollection.size())
		{
			ShaderPackage shader = this->ShaderCollection[index];

			Wait();

			this->Context->CSSetShader(&shader.Shader, NULL, 0);
			this->BindAllBuffer();
			this->Context->Dispatch(shader.GroupNumber[0], shader.GroupNumber[1], shader.GroupNumber[2]);
		}
	}

	void DXCompute::Wait()
	{
		HRESULT hr;
		bool Result = false;

		this->Context->End(&this->Query);
		while(!Result)
		{
			hr = this->Context->GetData(&this->Query, NULL, 0, 0);
			Result = (hr == S_OK);

			if(hr != S_OK && hr != S_FALSE)
			{
				DXException::Check(hr, L"Get Query");
			}
		}
	}
}