
#include "Meshes.h"


void Meshes::load_meshes(LPCSTR pFilename, LPDIRECT3DDEVICE9 pD3DDevice)
{
	ID3DXBuffer* buff_Material = NULL;
	ID3DXBuffer* buff_Adjacency = NULL;

	D3DXLoadMeshFromX(pFilename, D3DXMESH_MANAGED, pD3DDevice, &buff_Adjacency, &buff_Material, NULL, &numMaterials, &Model); 


	D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)buff_Material->GetBufferPointer();


	material = new D3DMATERIAL9[numMaterials];
	texture = new LPDIRECT3DTEXTURE9[numMaterials];

	for(DWORD i = 0; i < numMaterials; i++) 
	{
		material[i] = tempMaterials[i].MatD3D; 
		material[i].Ambient = material[i].Diffuse; 

		if(FAILED(D3DXCreateTextureFromFileA(pD3DDevice,tempMaterials[i].pTextureFilename,&texture[i])))
			texture[i] = NULL; 
	}


	return;
}


void Meshes::set_meshes(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale)
{

	pos = _pos;

	rot = _rot;

	scale = _scale;  

	return;
}


Meshes::Meshes()
{
	pos  = D3DXVECTOR3(0, 5, 0);
	rot = D3DXVECTOR3(1, 1, 1);
	scale = D3DXVECTOR3(3, 3, 3);

	return;
}


void Meshes::draw_meshes(LPDIRECT3DDEVICE9 pD3DDevice)
{ 
	D3DXMatrixRotationYawPitchRoll(&matRotate, D3DXToRadian(rot.y), D3DXToRadian(rot.x), D3DXToRadian(rot.z));
	D3DXMatrixScaling(&matScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&matTranslate, pos.x, pos.y, pos.z);

	pD3DDevice->SetTransform(D3DTS_WORLD, &(matRotate* matScale * matTranslate));


	for(DWORD i = 0; i < numMaterials; i++) 
	{
		pD3DDevice->SetMaterial(&material[i]);
		pD3DDevice->SetTexture(0,texture[i]);
		Model->DrawSubset(i);
		//return;
	}
}

void Meshes::clear_meshes()
{
	Model->Release();
	return;
} 