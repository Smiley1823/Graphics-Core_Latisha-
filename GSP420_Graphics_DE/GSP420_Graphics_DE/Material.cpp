
#include "Material.h"

Material::Material()  
{
	m_diffuse = GRAY;
	m_ambient = GRAY;
	m_specular = GRAY;
	m_emissive = GRAY;
	m_power = 0.0f;
	m_texture = 0;
}

Material::Material(D3DXCOLOR diff, D3DXCOLOR amb, D3DXCOLOR spec, D3DXCOLOR em, float pow)
{
	m_diffuse = diff;
	m_ambient = amb;
	m_specular = spec;
	m_emissive = em;
	m_power = pow;
	m_texture = 0;
}

Material::~Material()
{
	// Calls release function in case it was not called.
	release();
}

D3DXCOLOR Material::getDiffuse()
{
	return m_diffuse;
}

void	 Material::setDiffuse(D3DXCOLOR diff)
{
	m_diffuse = diff;
}

D3DXCOLOR Material::getAmbient()
{
	return m_ambient;
}

void	 Material::setAmbient(D3DXCOLOR amb)
{
	m_ambient = amb;
}

D3DXCOLOR Material::getSpecular()
{
	return m_specular;
}

void	 Material::setSpecular(D3DXCOLOR spec)
{
	m_specular = spec;
}

D3DXCOLOR Material::getEmissive()
{
	return m_emissive;
}

void	 Material::setEmissive(D3DXCOLOR em)
{
	m_emissive = em;
}

float	 Material::getPower()
{
	return m_power;
}

void	 Material::setPower(float pow)
{
	m_power = pow;
}

void	 Material::setMaterialAttributes(D3DXCOLOR diff, D3DXCOLOR amb, 
										 D3DXCOLOR spec, D3DXCOLOR em, float pow)
{
	m_diffuse = diff;
	m_ambient = amb;
	m_specular = spec;
	m_emissive = em;
	m_power = pow;
}

IDirect3DTexture9* Material::getTexture()
{
	return m_texture;
}

void 	 Material::loadTextureFromFile(LPDIRECT3DDEVICE9 device, LPCSTR tex)
{
	D3DXCreateTextureFromFile(device, tex, &m_texture);
}

/* Material operator=(const D3DMATERIAL9 *mat)
{
	m_diffuse = mat->Diffuse;
	m_ambient = mat->Ambient;
	m_specular = mat->Specular;
	m_emissive = mat->Emissive;
	m_power = mat->Power;
	
	return *this;
}
*/

/*D3DMATERIAL9 operator=(const Material *mat)
{
	D3DMATERIAL9 temp;
	temp.Diffuse = mat->getDiffuse();
	temp.Ambient = mat->getAmbient();
	temp.Specular = mat->getSpecular();
	temp.Emissive = mat->getEmissive();
	temp.Power = mat->getPower();
	
	return &temp;
}
*/

void 	 Material::release()
{
	m_texture->Release();
}

