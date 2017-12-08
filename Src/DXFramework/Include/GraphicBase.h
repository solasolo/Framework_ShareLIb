#pragma once

#include <d3d11.h>
#include <d3dcommon.h>
#include <D3DX10Math.h>

#ifdef _WIN32_WINNT_WIN10
#include <DirectXMath.h>
#endif

using namespace DirectX;

namespace GLEO
{
	class __declspec(dllexport) BaseGraphicObject
	{
	protected:
		XMFLOAT4 Position;
		XMFLOAT4 Direction;
		XMFLOAT4 Up;
		XMFLOAT4 Right;

		D3DXMATRIX WorldMatrix;

		void UpdateWorldMatrix();

	public:
		BaseGraphicObject();

		void SetPosition(D3DXVECTOR3 pos);

		void Move(float x, float y, float z);
		void Step(float dx, float dy, float dz);

		void Reset();

		D3DXVECTOR3 getPosition(); 
		D3DXVECTOR3 getDirection(); 
		D3DXVECTOR3 getRight();
		D3DXVECTOR3 getUp();
	};
}