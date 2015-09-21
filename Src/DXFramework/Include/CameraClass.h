#pragma once

#include <d3d11.h>
#include <d3dx10math.h>

#include "GraphicBase.h"

namespace GLEO
{
	class _declspec(dllexport) BaseCamera : public BaseGraphicObject
	{
	protected:
		float FieldOfView;
		float ScreenAspect;
		float ScreenNear;
		float ScreenDepth;
		float ScreenWidth;
		float ScreenHeight;
		float XScale;
		float YScale;

		D3DXVECTOR4 _right;

		D3DXMATRIX ProjectionMatrix;
		D3DXMATRIX ViewMatrix;
		D3DXMATRIX OrthoMatrix;

		void Normalize();

	public:
		BaseCamera();

		D3DXMATRIX& GetProjectionMatrix();
		D3DXMATRIX& GetViewMatrix(); 

		void SetFieldOfView(float field_view);
		void SetScreen(float width, float height);

		D3DXVECTOR3 getLook();
		
		void Reset();

		POINTF PointOnScreen(float x, float y, float z);
		D3DXVECTOR3 ScreenPointAt(POINTF point, float z);

		void Walk(float dx, float dy, float dz);
		void WalkTo(float x, float y, float z);
	};

	class _declspec(dllexport)AircraftCamera : public BaseCamera
	{
	public:
		AircraftCamera();
		~AircraftCamera();

		void strafe(float units); // l左右
		void fly(float units);    // 上下
		void walk(float units);   // 前后

		void pitch(float angle); // 旋转view坐标系right向量
		void yaw(float angle);   // 旋转up向量
		void roll(float angle);  // 旋转look向量
	};

	class _declspec(dllexport)LandObjectCamera : public BaseCamera
	{
	public:
		LandObjectCamera();
		~LandObjectCamera();

		void strafe(float units); // l左右
		void fly(float units);    // 上下
		void walk(float units);   // 前后

		void pitch(float angle); // 旋转view坐标系right向量
		void yaw(float angle);   // 旋转up向量
		void roll(float angle);  // 旋转look向量
	};

	class _declspec(dllexport)ProjectCamera : public BaseCamera
	{
	private:
		float ProjectHeight;
		float ProjectWidth;
		float ScreenDistance;

	public:
		ProjectCamera(float width, float height, float distance);
		~ProjectCamera();

	};
}
