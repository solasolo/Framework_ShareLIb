#include "stdafx.h"

#include "CameraClass.h"

using namespace DirectX;
using namespace GLEO;

BaseCamera::BaseCamera()
	: BaseGraphicObject()
{
	this->FieldOfView = (float)D3DX_PI / 4.0;
	this->ScreenNear = 0.1;
	this->ScreenDepth = 1000;
	this->ScreenWidth = 1024;
	this->ScreenHeight = 768;

	this->Normalize();
}

void BaseCamera::Normalize()
{
	this->ScreenAspect = this->ScreenHeight / this->ScreenWidth;

	this->YScale = 1 / tan(this->FieldOfView / 2);
	this->XScale = this->YScale / this->ScreenAspect;

	// ����͸��ͶӰ����.
	D3DXMatrixPerspectiveFovLH(&ProjectionMatrix, FieldOfView, ScreenAspect, ScreenNear, ScreenDepth);

	XMVECTOR _Position = XMLoadFloat4(&this->Position);
	XMVECTOR _Direction = XMLoadFloat4(&this->Direction);
	XMVECTOR _Up = XMLoadFloat4(&this->Up);

	XMMATRIX mat = XMMatrixLookToLH(_Position, _Direction, _Up);

	this->ViewMatrix = *(D3DXMATRIX*)&mat;
}

D3DXMATRIX& BaseCamera::GetProjectionMatrix()
{
	return this->ProjectionMatrix;
}

D3DXMATRIX& BaseCamera::GetViewMatrix()
{
	return this->ViewMatrix;
}

void BaseCamera::SetFieldOfView(float field_view)
{
	this->FieldOfView = field_view;

	this->Normalize();
}

void BaseCamera::SetScreen(float height, float width)
{
	this->ScreenWidth = width;
	this->ScreenHeight = height;

	this->Normalize();
}

void BaseCamera::Walk(float dx, float dy, float dz)
{
	this->Step(dx, dy, dz);

	this->Normalize();
}

void BaseCamera::WalkTo(float x, float y, float z)
{
	this->Move(x, y, z);

	this->Normalize();
}

POINTF BaseCamera::PointOnScreen(float x, float y, float z)
{
	POINTF Result;

	Result.x = this->XScale * (x - this->Position.x) * this->ScreenWidth / z;
	Result.y = this->YScale * (y - this->Position.y) * this->ScreenHeight / z;

	return Result;
}

D3DXVECTOR3 BaseCamera::ScreenPointAt(POINTF point, float z)
{
	D3DXVECTOR3 Result;

	Result.x = point.x / this->ScreenWidth * z / this->XScale + this->Position.x; 
	Result.y = point.y / this->ScreenHeight * z / this->YScale + this->Position.y; 

	Result.z = z;

	return Result;
}

D3DXVECTOR3 BaseCamera::getLook()
{
	D3DXVECTOR3 Result;

	Result.x = this->Direction.x;
	Result.y = this->Direction.y;
	Result.z = this->Direction.z;

	return Result;
}

//
//
//

AircraftCamera::AircraftCamera()
	: BaseCamera()
{
}

AircraftCamera::~AircraftCamera()
{
}
/*
//���ߣ�����������۲췽����ƶ�
void AircraftCamera::walk(float units)
{
	_pos += _look * units;
}

//ɨ�ӣ���ָ���ֹ۲췽�򲻱䣬������right�����һ��ƽ�Ƶ���һ��
void AircraftCamera::strafe(float units)
{
	_pos += _right * units;
}
//����ģʽ��������ָ��������up������ƶ�
void AircraftCamera::fly(float units)
{
	_pos += _up * units;
}

void AircraftCamera::pitch(float angle)
{
	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &_right, angle);

	// ����right��������תup��look
	D3DXVec3TransformCoord(&_up,&_up, &T);
	D3DXVec3TransformCoord(&_look,&_look, &T);
}

void AircraftCamera::yaw(float angle)
{
	D3DXMATRIX T;

	D3DXMatrixRotationAxis(&T, &_up, angle);

	// ����up����y�ᣬ��תright��look
	D3DXVec3TransformCoord(&_right,&_right, &T);
	D3DXVec3TransformCoord(&_look,&_look, &T);
}

void AircraftCamera::roll(float angle)
{
	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &_look, angle);

	// ����look��������תup��right
	D3DXVec3TransformCoord(&_right,&_right, &T);
	D3DXVec3TransformCoord(&_up,&_up, &T);
}
*/

//
//
//

LandObjectCamera::LandObjectCamera()
	: BaseCamera()
{
}

LandObjectCamera::~LandObjectCamera()
{
}
/*
//���ߣ�����������۲췽����ƶ�
void LandObjectCamera::walk(float units)
{
	// ����x,zƽ���ƶ�
	_pos += D3DXVECTOR3(_look.x, 0.0f, _look.z) * units;
}

//ɨ�ӣ���ָ���ֹ۲췽�򲻱䣬������right�����һ��ƽ�Ƶ���һ��
void LandObjectCamera::strafe(float units)
{
	// ����x,zƽ���ƶ�
	_pos += D3DXVECTOR3(_right.x, 0.0f, _right.z) * units;
}
//����ģʽ��������ָ��������up������ƶ�
void LandObjectCamera::fly(float units)
{
	// ����y���ƶ�
	_pos.y += units;

}

void LandObjectCamera::pitch(float angle)
{
	D3DXMATRIX T;
	D3DXMatrixRotationAxis(&T, &_right, angle);

	// ����right��������תup��look
	D3DXVec3TransformCoord(&_up,&_up, &T);
	D3DXVec3TransformCoord(&_look,&_look, &T);
}

void LandObjectCamera::yaw(float angle)
{
	D3DXMATRIX T;

	D3DXMatrixRotationY(&T, angle);

	// ����up����y�ᣬ��תright��look
	D3DXVec3TransformCoord(&_right,&_right, &T);
	D3DXVec3TransformCoord(&_look,&_look, &T);
}

void LandObjectCamera::roll(float angle)
{
}
*/

//
//
//

ProjectCamera::ProjectCamera(float width, float height, float distance)
	: BaseCamera()
{
	this->ScreenDistance = distance;
	this->ProjectWidth = width;
	this->ProjectHeight = height;
	this->FieldOfView = atan(this->ProjectHeight / 2 / this->ScreenDistance) * 2;
	 
	this->Normalize();
}
