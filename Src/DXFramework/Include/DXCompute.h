#pragma once

#include <d3dcommon.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <vector>
#include <string>

#include "SmartPointer.h"
#include "DXException.h"
#include "GraphicBaseDevice.h"

using namespace std;

namespace GLEO
{
	COMPtr(ID3D11Device);
	COMPtr(ID3D11DeviceContext);
	COMPtr(ID3D11ComputeShader);
	COMPtr(ID3D11Buffer);
	COMPtr(ID3D11ShaderResourceView);
	COMPtr(ID3D11UnorderedAccessView);
	COMPtr(ID3D11Query);

	class DXCompute;

	class __declspec(dllexport) ResultBuffer 
	{
		friend class DXCompute;

	private:
		class __declspec(dllexport) BufferPack
		{
		private:
			ID3D11DeviceContextPtr Context;
			ID3D11BufferPtr Buffer;

			void* Data;

		public:
			BufferPack(ID3D11DeviceContextPtr context, ID3D11BufferPtr buffer);	
			~BufferPack();

			void* GetData();
		};

		SmartPointer<BufferPack> ShareBuffer;

		ResultBuffer(ID3D11DeviceContextPtr context, ID3D11BufferPtr buffer);		

	public:
		ResultBuffer();		

		void* GetData();
	};

	class __declspec(dllexport) DXCompute : public GraphicBaseDevice
	{
		enum BufferType
		{
			Constant,
			Input,
			Output
		};

		struct InputBufferPackage
		{
			int ElementSize;
			int ElementCount;
			ID3D11BufferPtr Buffer;
			ID3D11ShaderResourceViewPtr View;
		};

		struct OutputBufferPackage
		{
			int ElementSize;
			int ElementCount;
			ID3D11BufferPtr Buffer;
			ID3D11UnorderedAccessViewPtr View;
		};

		struct ShaderPackage
		{
			ID3D11ComputeShaderPtr Shader;
			int GroupNumber[3];
		};

	private:
		ID3D11QueryPtr Query;

		vector<ShaderPackage> ShaderCollection;
		vector<InputBufferPackage> InputBuffers;
		vector<OutputBufferPackage> OutputBuffers;
		vector<ID3D11BufferPtr> ConstantBuffers;

		void CreateQuery();

		ID3D11ComputeShaderPtr CreateShader(wstring file);
		ID3D11BufferPtr CreateBuffer(BufferType type, void* data, int ElementsSize, int ElementCount);

		ID3D11UnorderedAccessViewPtr CreateView(BufferType type, ID3D11Buffer* pBuffer, int ElementsSize, int ElementCount);
		ID3D11ShaderResourceViewPtr CreateInputView(ID3D11Buffer*, int ElementsSize, int ElementCount);
		ID3D11UnorderedAccessViewPtr CreateOutputView(ID3D11Buffer* pBuffer, int ElementsSize, int ElementCount);

		void BindAllBuffer();
		void UnbindAllBuffer();

	public:
		DXCompute();
		DXCompute(int index);
		~DXCompute(void);

		void SetGroup(int index, int x, int y, int z);

		void LoadShader(wstring file, int x, int y, int z);

		void SetParameter(wstring& key, wstring& value);
		int AddInputBuffer(void* data, int ElementsSize, int ElementCount);
		int AddOutputBuffer(int ElementsSize, int ElementCount);
		void UpdateBuffer(int index, void* data);

		ResultBuffer CopyResult(int index);

		void Run(int index);
		void Wait();
	};
}
