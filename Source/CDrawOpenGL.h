#pragma once
#include <windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <math.h>
#include <stdio.h>
#include "DrawElements.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

using namespace System::Windows::Forms;

public ref class CDrawOpenGL : public System::Windows::Forms::NativeWindow
{
private:
    HDC m_hDC;
	HGLRC m_hglrc;

	GLsizei iWidth;
	GLsizei iHeight;

	CreateParams^ cp;

public:
	int startPosgroupBoxWidth;
	int startPosgroupBoxHeight;
	float offset_x, offset_y;
	float oldposx, oldposy;
	float posx, posy;

    void SwapBuffersOGL();
    bool InitGL();

public:
	CDrawOpenGL(System::Windows::Forms::Form^ parentForm, int width, int height);
    ~CDrawOpenGL();
    void Render();

	void InitTexture();
	void Calc_Screen_Offsets();
	void DrawCell(float x, float dx, float y, float dy);
	void DrawArrow(float x, float y, float width, float height, float angle);
	void DrawArc(float x, float y, float r, float start_angle, float end_angle, float angle_increment);
	void DrawScale(float x, float y, float r, float start_angle, float end_angle, float angle_increment, float scalelength);
	void DrawLinePointer(float x, float y, float value, float maximum);
	void DrawTexture(Texture* img);
	void InitTexture(const char* fileName, unsigned int &texture);
	void ShowTexture(Texture* img, unsigned int& texture);
	void DrawValue(float x, float y, float fontSize, float value, const char* format);
	void DrawText(float x, float y, float fontSize, const char* text);
	void InitText(unsigned int& text_texture);
	void ShowText(float x, float y, float size, unsigned int& text_texture, const char* text);
	void MoveTextureY(Texture* texture);
	void LimitationY(Texture* texture);
    GLvoid ReSizeGLScene(GLsizei width, GLsizei height);

protected:
	GLint MySetPixelFormat(HDC hdc)
	{
		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
			1,                                // version number 
			PFD_DRAW_TO_WINDOW |              // support window 
			PFD_SUPPORT_OPENGL |              // support OpenGL 
			PFD_DOUBLEBUFFER,                 // double buffered 
			PFD_TYPE_RGBA,                    // RGBA type 
			24,                               // 24-bit color depth 
			0, 0, 0, 0, 0, 0,                 // color bits ignored 
			0,                                // no alpha buffer 
			0,                                // shift bit ignored 
			0,                                // no accumulation buffer 
			0, 0, 0, 0,                       // accum bits ignored 
			32,								  // 32-bit z-buffer     
			0,                                // no stencil buffer 
			0,                                // no auxiliary buffer 
			PFD_MAIN_PLANE,                   // main layer 
			0,                                // reserved 
			0, 0, 0                           // layer masks ignored 
		};

		GLint  iPixelFormat;

		// get the device context's best, available pixel format match 
		if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
		{
			MessageBox::Show("ChoosePixelFormat Failed");
			return 0;
		}

		// make that match the device context's current pixel format 
		if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
		{
			MessageBox::Show("SetPixelFormat Failed");
			return 0;
		}

		if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)
		{
			MessageBox::Show("wglCreateContext Failed");
			return 0;
		}

		if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}


		return 1;
	}

};