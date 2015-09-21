#pragma once

//#include "common.h"

#include "DxGraphic.h"

using namespace GLEO;

class ModelTarget : public BaseGraphicObject
{

protected:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	public:
		VertexType()
		{

		}
		VertexType(FLOAT x, FLOAT y, FLOAT z, FLOAT u, FLOAT v )
			: position(x, y, z), texture(u, v)
		{

		}
	};

public:
	ModelTarget(BasicPipeline* piple);
	~ModelTarget(void);

	void Initial();

	void InitialBuffer();

	void InitialShader();

	void Render();

private:
	wstring ResPath;

	BasicPipeline* Piple;
	BasicPipelineResource* Resource;
};

