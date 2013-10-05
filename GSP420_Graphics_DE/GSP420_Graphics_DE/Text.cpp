#include "Text.h"

Text::Text()
{
	m_font = NULL; //the font object
}

//--------------------
//	text deconstructor
//--------------------
Text::~Text(void)
{
	
	m_font->Release();
		
}

//-----------------------------------------------------
//	initializes the text to screen
//-----------------------------------------------------
void Text::Init(DWORD size, LPDIRECT3DDEVICE9 device)
{
	//create a font
	D3DXCreateFont(device,							//D3D device
					size,							//font height
					0,								//font width
					FW_NORMAL,						//font weight
					1,								//MipLevels
					false,							//Italic
					DEFAULT_CHARSET,				//CharSet
					OUT_DEFAULT_PRECIS,				//OutputPrecision
					DEFAULT_QUALITY,			//Quality
					DEFAULT_PITCH|FF_DONTCARE,		//PitchAndfamily
					TEXT("Times New Roman"),					//pFacename
					&m_font);						//ppFont

	
	return;
}

//---------------------------------------------------------------------------------------
//		Draws the text to the screen
//---------------------------------------------------------------------------------------
void Text::DisplayText(char* text, int x, int y, 
					   int width, int height, D3DXCOLOR color)
{
	RECT m_rect = {0,0,width,height};   //sets the size of the font surface rect

	//set the destination for the text, by moving the font rect
	SetRect(&m_rect,		//the font rect
					x,		//left
					y,		//top
					width,	//width
					height	//height
					);

	//draw the text
	m_font->DrawText(NULL,		//pSprite
		text,					//pString
		-1,						//count
		&m_rect,				//Rectpointer
		DT_LEFT|DT_NOCLIP,		//format
		color);	//color 

}