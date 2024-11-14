#include "CDrawOpenGL.h"
#include "EWD.h"
#include "Indication.h"

#define M_PI 3.14159265358979323846

Texture thrlpanel;
Texture thrl1;
Texture thrl2;

extern Indication eng_ind[2];

#define TEXTURE_THR_PANEL "Textures\\Thrust_Panel.gif"
#define TEXTURE_THR_LEVELER1 "Textures\\Leveler-1.gif"
#define TEXTURE_THR_LEVELER2 "Textures\\Leveler-2.gif"


void CDrawOpenGL::SwapBuffersOGL()
{
    SwapBuffers(m_hDC);
}

bool CDrawOpenGL::InitGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    return TRUE;
}

void CDrawOpenGL::InitTexture() {

    thrlpanel.Set(0.0f, iHeight, 250.0f, 0.0f, TEXTURE_THR_PANEL);

    thrl1.Set(50.0f, 543.0f, 135.0f, 462.0f, TEXTURE_THR_LEVELER1);
    thrl1.SetMinMaxValues(183.0f, 543.0f);

    thrl2.Set(145.0f, 543.0f, 230.0f, 462.0f, TEXTURE_THR_LEVELER2);
    thrl2.SetMinMaxValues(183.0f, 543.0f);
}

CDrawOpenGL::CDrawOpenGL(System::Windows::Forms::Form^ parentForm, int wd, int ht)
{
    startPosgroupBoxWidth = wd;
    startPosgroupBoxHeight = ht;

    iWidth = parentForm->Size.Width - startPosgroupBoxWidth;
    iHeight = parentForm->Size.Height;

    cp = gcnew CreateParams;

    cp->X = startPosgroupBoxWidth;
    cp->Y = 0;

    cp->Width = iWidth;
    cp->Height = iHeight;

    // Specify the form as the parent.
    cp->Parent = parentForm->Handle;

    // Create as a child of the specified parent
       // and make OpenGL compliant (no clipping)
    cp->Style = WS_CHILD | WS_VISIBLE |
        WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    // Create the actual window
    this->CreateHandle(cp);

    m_hDC = GetDC((HWND)this->Handle.ToPointer());

    if (m_hDC)
        MySetPixelFormat(m_hDC);


    if (m_hDC)
    {
        m_hglrc = wglCreateContext(m_hDC);
        wglMakeCurrent(m_hDC, m_hglrc);
        ReSizeGLScene(iWidth, iHeight);
        InitGL();
    }

    InitTexture();

}


CDrawOpenGL::~CDrawOpenGL()
{
    wglMakeCurrent(0, 0);
    wglDeleteContext(m_hglrc);
    DeleteDC(m_hDC);
}


void CDrawOpenGL::Render()
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    
    //N1, Eng1
    //Engine rotation speed cell
    DrawCell(370., 95., 157.40f, 30.);

    //Pointer of engine rotation speed
    DrawArrow(364., 157.40606255504582f, 5., 35., (eng_ind[0].n1 * 2.f));

    //Arc of the engine speed rotation indicator scale
    DrawArc(360.f, 120.f, 0.05f, 1.5f, 6.17f, (M_PI / 1000.f));

    //Engine speed rotation indicator scale
    DrawScale(360., 120., 0.05f, 1.5f, 6.17f, 0.355f, 0.01f);


    //N1, Eng2
    //Engine rotation speed cell
    DrawCell(610., 95., 157.40f, 30.);

    //Pointer of engine rotation speed
    DrawArrow(604., 157.40606255504582f, 5., 35., (eng_ind[1].n1 * 2.f));

    //Arc of the engine speed rotation indicator scale
    DrawArc(600.f, 120.f, 0.05f, 1.5f, 6.17f, (M_PI / 1000.f));

    //Engine speed rotation indicator scale
    DrawScale(600., 120., 0.05f, 1.5f, 6.17f, 0.355f, 0.01f);


    //N2, Eng1
    //Engine rotation speed cell
    DrawCell(370., 95., 307.40f, 30.);

    //Pointer of engine rotation speed
    DrawArrow(364.f, 307.40606255504582f, 5.f, 35.f, (eng_ind[0].n2 * 2.f));

    //Arc of the engine speed rotation indicator scale
    DrawArc(360., 270., 0.05f, 1.5f, 6.17f, (M_PI / 1000.f));

    //Engine speed rotation indicator scale
    DrawScale(360., 270., 0.05f, 1.5f, 6.17f, 0.355f, 0.01f);


    //N2, Eng2
    //Engine rotation speed cell
    DrawCell(610., 95., 307.40f, 30.);

    //Pointer of engine rotation speed
    DrawArrow(604.f, 307.40606255504582f, 5.f, 35.f, (eng_ind[1].n2 * 2.f));

    //Arc of the engine speed rotation indicator scale
    DrawArc(600.f, 270.f, 0.05f, 1.5f, 6.17f, (M_PI / 1000.f));

    //Engine speed rotation indicator scale
    DrawScale(600., 270., 0.05f, 1.5f, 6.17f, 0.355f, 0.01f);



    //Engine parameter indicator, ENG1
    DrawLinePointer(275.0f, 400.0f, eng_ind[0].egt_temperature, eng_ind[0].egt_max);//egt_temperature
    DrawLinePointer(275.0f, 475.0f, eng_ind[0].fuel_flow, eng_ind[0].fuel_flow_max);//fuel flow
    DrawLinePointer(275.0f, 550.0f, eng_ind[0].thrust, eng_ind[0].thrust_max);//thrust
    DrawLinePointer(275.0f, 625.0f, eng_ind[0].gv, eng_ind[0].gv_max);//gv


    //Engine parameter indicator, ENG2
    DrawLinePointer(515.0f, 400.0f, eng_ind[1].egt_temperature, eng_ind[1].egt_max);//egt_temperature
    DrawLinePointer(515.0f, 475.0f, eng_ind[1].fuel_flow, eng_ind[1].fuel_flow_max);//fuel flow
    DrawLinePointer(515.0f, 550.0f, eng_ind[1].thrust, eng_ind[1].thrust_max);//thrust
    DrawLinePointer(515.0f, 625.0f, eng_ind[1].gv, eng_ind[1].gv_max);//gv



    //Thrust-Leveler panel
    DrawTexture(&thrlpanel);
    
    //Thrust-Leveler #1
    DrawTexture(&thrl1);
    
    //Thrust-Leveler #2
    DrawTexture(&thrl2);

    //Text, N1
    DrawText(470.0f, 107.40f, 21.0f, "N1");

    //Text, N2
    DrawText(470.0f, 257.40f, 21.0f, "N2");

    //Roation speed, N1L%
    DrawValue(372.5f, 153.40f, 18.0f, eng_ind[0].n1, "%3.1f");

    //Roation speed, N2L%
    DrawValue(372.5f, 303.40f, 18.0f, eng_ind[0].n2, "%3.1f");

    //Roation speed, N1R%
    DrawValue(612.5f, 153.40f, 18.0f, eng_ind[1].n1, "%3.1f");

    //Roation speed, N2R%
    DrawValue(612.5f, 303.40f, 18.0f, eng_ind[1].n2, "%3.1f");



    //Left engine parameter templates
    DrawText(275.0f, 390.0f, 16.0f, "EGT");
    DrawText(275.0f, 465.0f, 16.0f, "FF");
    DrawText(275.0f, 540.0f, 16.0f, "thrust");
    DrawText(275.0f, 615.0f, 16.0f, "gv");


    //Right engine parameter templates
    DrawText(515.0f, 390.0f, 16.0f, "EGT");
    DrawText(515.0f, 465.0f, 16.0f, "FF");
    DrawText(515.0f, 540.0f, 16.0f, "thrust");
    DrawText(515.0f, 615.0f, 16.0f, "gv");



    //Left engine parameter value
    DrawValue(410.0f, 390.0f, 16.0f, eng_ind[0].egt_temperature, "%4.0f");
    DrawValue(410.0f, 465.0f, 16.0f, eng_ind[0].fuel_flow, "%4.0f");
    DrawValue(410.0f, 540.0f, 16.0f, eng_ind[0].thrust, "%5.0f");
    DrawValue(410.0f, 615.0f, 16.0f, eng_ind[0].gv, "%3.0f");


    //Right engine parameter value
    DrawValue(650.0f, 390.0f, 16.0f, eng_ind[1].egt_temperature, "%4.0f");
    DrawValue(650.0f, 465.0f, 16.0f, eng_ind[1].fuel_flow, "%4.0f");
    DrawValue(650.0f, 540.0f, 16.0f, eng_ind[1].thrust, "%5.0f");
    DrawValue(650.0f, 615.0f, 16.0f, eng_ind[1].gv, "%3.0f");



    MoveTextureY(&thrl1);

    MoveTextureY(&thrl2);

    glPopMatrix();
    
    SwapBuffers(m_hDC);
    
    Sleep(1);
}

GLvoid CDrawOpenGL::ReSizeGLScene(GLsizei width, GLsizei height)
{
    glViewport(0., 0., width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0., width, height, 0., -1., 1.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    return GLvoid();
}

