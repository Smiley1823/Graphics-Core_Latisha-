#ifndef MESHES_H
#define MESHES_H

#include <d3d9.h>
#include <d3dx9.h>
#include "Material.h"
#include "settings.h"

class Meshes
{
public:
	Meshes();
	ID3DXMesh* Model; 
	D3DMATERIAL9* material; 
	LPDIRECT3DTEXTURE9* texture;
	Material* material2;
	DWORD numMaterials; 

	D3DXMATRIX matRotate;
	D3DXMATRIX matScale;
	D3DXMATRIX matTranslate;


	D3DXVECTOR3 pos;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 scale;

	void load_meshes(LPCSTR pFilename, LPDIRECT3DDEVICE9 pD3DDevice);
	void set_meshes(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale);
	void draw_meshes(LPDIRECT3DDEVICE9 pD3DDevice);
	void clear_meshes();
	
	
	bool active;



	};


#endif