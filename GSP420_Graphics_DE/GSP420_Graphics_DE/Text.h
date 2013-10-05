#ifndef TEXT_H
#define TEXT_H

#include "settings.h"
#include <d3d9.h>
#include <d3dx9.h>
//#include <string.h>


class Text 
{
private:

	ID3DXFont* m_font;
	DWORD m_size;

public:

	Text(); 
	~Text();

	void Init(DWORD size, LPDIRECT3DDEVICE9 device);

	void DisplayText(char* text, int x, int y, int width, int height, D3DXCOLOR color); //draw a text string


};

#endif