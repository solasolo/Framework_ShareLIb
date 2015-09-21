#include "stdafx.h"

#include "GraphicBase.h"

using namespace GLEO;

BaseGraphicObject::BaseGraphicObject()
{
	this->Reset();
}

void BaseGraphicObject::Reset()
{
	this->Position = XMFLOAT4(0.0, 0.0, 0.0, 1.0);
	this->Direction = XMFLOAT4(0.0, 0.0, 1.0, 0.0);
	this->Up = XMFLOAT4(0.0, 1.0, 0.0, 0.0);
	this->Right = XMFLOAT4(1.0, 0.0, 0.0, 0.0);

	D3DXMatrixIdentity(&this->WorldMatrix);
}

void BaseGraphicObject::SetPosition(D3DXVECTOR3 pos)
{
	this->Position.x = pos.x;
	this->Position.y = pos.y;
	this->Position.z = pos.z;
	this->Position.w = 1.0;

	this->UpdateWorldMatrix();
}

void BaseGraphicObject::Move(float x, float y, float z)
{
	this->Position.x = x;
	this->Position.y = y;
	this->Position.z = z;
	this->Position.w = 1.0;

	this->UpdateWorldMatrix();
}

void BaseGraphicObject::Step(float dx, float dy, float dz)
{
	this->Position.x += dx;
	this->Position.y += dy;
	this->Position.z += dz;
	this->Position.w = 1.0;
		
	this->UpdateWorldMatrix();
}

void BaseGraphicObject::UpdateWorldMatrix()
{
	D3DXMatrixIdentity(&this->WorldMatrix);
	D3DXMatrixTranslation(&this->WorldMatrix, this->Position.x, this->Position.y, this->Position.z);
}

D3DXVECTOR3 BaseGraphicObject::getPosition()
{
	D3DXVECTOR3 Result;

	Result.x = this->Position.x;
	Result.y = this->Position.y;
	Result.z = this->Position.z;

	return Result;
}

D3DXVECTOR3 BaseGraphicObject::getDirection()
{
	D3DXVECTOR3 Result;

	Result.x = this->Direction.x;
	Result.y = this->Direction.y;
	Result.z = this->Direction.z;

	return Result;
}

D3DXVECTOR3 BaseGraphicObject::getRight()
{
	D3DXVECTOR3 Result;

	Result.x = this->Right.x;
	Result.y = this->Right.y;
	Result.z = this->Right.z;

	return Result;
}

D3DXVECTOR3 BaseGraphicObject::getUp()
{
	D3DXVECTOR3 Result;

	Result.x = this->Up.x;
	Result.y = this->Up.y;
	Result.z = this->Up.z;

	return Result;
}
