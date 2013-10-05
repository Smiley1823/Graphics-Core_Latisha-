

#ifndef MATERIAL_H
#define MATERIAL_H

#include "settings.h"
#include <d3d9.h>
#include <d3dx9.h>

// Some preset colors for easy access and test purposes.
#define BLACK D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f)
#define WHITE D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)
#define GRAY D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f)
#define RED D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f)
#define GREEN D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f)
#define BLUE D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f)

class Material
{
	public:

	//Constructors & Deconstructor
	Material();
	Material(D3DXCOLOR diff, D3DXCOLOR amb, D3DXCOLOR spec, D3DXCOLOR em, float pow);
	~Material();

	// Color paramaters.
	D3DXCOLOR m_diffuse;
	D3DXCOLOR m_ambient;
	D3DXCOLOR m_specular;
	D3DXCOLOR m_emissive;
	// Specular power.
	float	 m_power;
	
	// Texture object to be applied to material surface.
	
	IDirect3DTexture9* m_texture;
	
	// Accessors and mutators for material paramaters.
	D3DXCOLOR getDiffuse();
	void	 setDiffuse(D3DXCOLOR diff);
	D3DXCOLOR getAmbient();
	void	 setAmbient(D3DXCOLOR amb);
	D3DXCOLOR getSpecular();
	void	 setSpecular(D3DXCOLOR spec);
	D3DXCOLOR getEmissive();
	void	 setEmissive(D3DXCOLOR em);
	float	 getPower();
	void	 setPower(float pow);
	void	 setMaterialAttributes(D3DXCOLOR diff, D3DXCOLOR amb, D3DXCOLOR spec, D3DXCOLOR em, float pow);
	IDirect3DTexture9* getTexture();
	//void	 setTexture(string tex);
	
	// Load texture from file.
	void 	 loadTextureFromFile(LPDIRECT3DDEVICE9 device, LPCSTR tex);
	
	// Operators
	Material operator=(const D3DMATERIAL9 &mat); // Assigns type D3DMATERIAL9 to type Material.
	D3DMATERIAL9 operator=(const Material &mat); // Assigns type Material to type D3DMATERIAL9.
	
	// Releases COM objects and frees up memory.
	void 	 release();
};

#endif