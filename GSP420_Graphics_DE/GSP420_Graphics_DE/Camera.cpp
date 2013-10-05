
#include "Camera.h"


Camera::Camera()
{
		pos  = D3DXVECTOR3(0, 10, -20);
		look = D3DXVECTOR3(0, 5, 0);
		up   = D3DXVECTOR3(0, 1, 0);
}
Camera::~Camera()
{
}

void Camera::Init()
{
		pos = D3DXVECTOR3(0, 10, 0);
		look = D3DXVECTOR3(0, 10, 1);
		up = D3DXVECTOR3(0, 1, 0);

		fov = 50;

		ar = 1.0;				// needs to be reset!

		nearClip = 1.0;
		farClip = 1000.0;
}

void Camera::SetAR(int wd, int ht)
{

	ar = (float)wd / (float)ht;
}

void Camera::dxGetProjection(D3DXMATRIX* pm)
{
	//Here we specify the field of view, aspect ratio and near and far clipping planes.
		D3DXMatrixPerspectiveFovLH(
			pm,
			fov * D3DX_PI/180.0, 
			ar, 
			nearClip,
			farClip);
}

void Camera::dxSetProjection(LPDIRECT3DDEVICE9 pd3dDevice) 
{
		D3DXMATRIX p;
		
		//Here we specify the field of view, aspect ratio and near and far clipping planes.
		D3DXMatrixPerspectiveFovLH(
			&p, 
			fov * D3DX_PI/180.0, 
			ar, 
			nearClip,
			farClip);

		pd3dDevice->SetTransform(D3DTS_PROJECTION, &p);

}

void Camera::dxSetView(LPDIRECT3DDEVICE9 pd3dDevice)
{

		D3DXMATRIX v;

		D3DXMatrixLookAtLH(
			&v, 
			&pos,
			&look, 
			&up  );
			

		pd3dDevice->SetTransform(D3DTS_VIEW, &v);
}

void Camera::dxGetView(D3DXMATRIX* pm) 
{

		D3DXMatrixLookAtLH(
			pm, 
			&pos,
			&look, 
			&up  );
			
}

void Camera::MoveForward(float distance) 
{
		D3DXVECTOR3 fwd = look - pos;
		D3DXVec3Normalize(&fwd, &fwd);

		pos = pos + fwd * distance;
		look = look + fwd * distance;
}

void Camera::MoveRight(float distance) 
{
		D3DXVECTOR3 fwd = look - pos;

		D3DXVECTOR3 right;

		D3DXVec3Cross(&right, &up, &fwd);

		D3DXVec3Normalize(&right, &right);

		pos = pos + right * distance;
		look = look + right * distance;
}

void Camera::Rotate(float angle) {
		D3DXMATRIX c, tin, r, tout;

		D3DXMatrixTranslation(&tin,  -pos.x, -pos.y, -pos.z);
		D3DXMatrixTranslation(&tout,  pos.x,  pos.y,  pos.z);
		D3DXMatrixRotationY(&r, D3DXToRadian(angle));

		c = tin * r * tout;

		// look = look * c
		D3DXVec3TransformCoord(&look, &look, &c);
	}