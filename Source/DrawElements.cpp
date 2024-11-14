#include "DrawElements.h"
#include "CDrawOpenGL.h"
#include "EWD.h"

#define STB_IMAGE_IMPLEMENTATION // Library for textures loading
#include "../_STB_IMAGE_/stb_image.h" // Functions of texture loading

#define TEXTURE_TEXT "Textures//Verdana.png"


void CDrawOpenGL::Calc_Screen_Offsets()
{
    POINT cur;

    int w, h;                 // Screen resolution
    float diff_w, diff_h;     // Difference between client window and monitor resolutions

    GetCursorPos(&cur); // Global mouse cursor position

    w = System::Windows::Forms::SystemInformation::PrimaryMonitorSize.Width;
    h = System::Windows::Forms::SystemInformation::PrimaryMonitorSize.Height;

    diff_w = (w / 2.f) - ((iWidth + startPosgroupBoxWidth) / 2.f) + startPosgroupBoxWidth;
    offset_x = cur.x - diff_w;

    diff_h = (h / 2.f) - (iHeight / 2.f);
    offset_y = cur.y - diff_h;

}

void CDrawOpenGL::DrawCell(float x, float dx, float y, float dy)
{
    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(x, y);
    glVertex2f(x + dx, y);

    glVertex2f(x, y - dy);
    glVertex2f(x + dx, y - dy);

    glVertex2f(x, y);
    glVertex2f(x, y - dy);

    glVertex2f(x + dx, y);
    glVertex2f(x + dx, y - dy);

    glEnd();
}

void CDrawOpenGL::DrawArrow(float x, float y, float width, float height, float angle)
{
    glPushMatrix();
    glTranslatef(x - (width / 2), (y - height), 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-(x - (width / 2)), -(y - height), 0.0f);
    glBegin(GL_TRIANGLES);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x, y - height);
    glVertex2f(x - width, y - height);
    glVertex2f(x - (width / 2), y);

    glEnd();

    glPopMatrix();
}

void CDrawOpenGL::DrawArc(float x, float y, float r, float start_angle, float end_angle, float angle_increment)
{
    float posx, posy;

    glLineWidth(1);
    glBegin(GL_LINE_STRIP);

    glColor3f(1.0f, 1.0f, 1.0f);

    for (double theta = start_angle; theta < end_angle; theta += angle_increment)
    {

        posx = x + ((r * cos(theta)) * iWidth);
        posy = y + ((r * sin(theta)) * iHeight);
        glVertex2f(posx, posy);
    }

    glEnd();
}

void CDrawOpenGL::DrawScale(float x, float y, float r, float start_angle, float end_angle, float angle_increment, float scalelength)
{
    float posx, posy, dx, dy;
    int i = 0;

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    for (double theta = start_angle; theta < end_angle; theta += angle_increment)
    {
        posx = x + ((r * cos(theta)) * iWidth);
        posy = y + ((r * sin(theta)) * iHeight);
        glVertex2f(posx, posy);

        dx = x + (((r - scalelength) * cos(theta)) * iWidth);
        dy = y + (((r - scalelength) * sin(theta)) * iHeight);
        glVertex2f(dx, dy);

        i++;
    }

    glEnd();
}

void CDrawOpenGL::DrawLinePointer(float x, float y, float value, float maximum)
{
    float val;

    val = maximum / value;
    glLineWidth(12);
    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, y);
    glVertex2f(x + (200.f/val), y);

    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(x, (y + 7.f));
    glVertex2f((x + 200.f), (y + 7.f));

    glEnd();
}

void CDrawOpenGL::DrawTexture(Texture* img)
{
    unsigned int texture;

    InitTexture(img->fileName, texture);
    ShowTexture(img, texture);

    glDeleteTextures(1, &texture);
}

void CDrawOpenGL::InitTexture(const char* fileName, unsigned int &texture)
{
    int width, height, cnt;
    unsigned char* data = stbi_load(fileName, &width, &height, &cnt, 0); // stbi_load - �������� �������� � ������, 2,3 - ������ ������, 4 - ����� ����������� �� �������

    glGenTextures(1, &texture); // ���������� ��������(1 - ���������� �������, ������ �� ���������� ��� ����� ��������)
    glBindTexture(GL_TEXTURE_2D, texture); // ������ �������� � ���������� (1 - ��� ��������, 2 - ������ �� ��������), GL_REPEAT - �������� ����� �����������

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // 1 - ��� ��������, 2 - ��� ��������� ��������, 3 - ��� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);// GL_TEXTURE_WRAP_S - ������ ���������� �������� �� �����������, GL_CLAMP - ������������ �� �������� �������� ����������� ������ ������� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL-TEXTURE_MIN_FILTER - ������� ���������� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL-TEXTURE_MAX_FILTER - ������� ���������� ��������
    // GL_NEAREST - ����� ����� ����������! �� ��������� �����, GL_LINEAR - ����� ����� ������ ����������������� �� ����� ����� � ������

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
        0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data); // (1 - ��� ��������, 3 - ��� ���������� �������� �� ���������� (4��������� rgba), 4,5 - ������ � ������ ������� ��������,
    // (7 - ��� ���������� ���������� �� ������� �������, 8 - ��� ���������� ������ �������� (0-255), 9 - ������ � ���������)

    glBindTexture(GL_TEXTURE_2D, 0); // ����� ��������� �������� ���������� ��������� �������� ��������

    stbi_image_free(data); // ����������� ������ �� ��������

}

void CDrawOpenGL::ShowTexture(Texture *img, unsigned int& texture)
{
    
    float vertex[] = { img->x, img->y, 0,  img->dx, img->y, 0,  img->dx, img->dy ,0,  img->x, img->dy, 0 };
    float texCoord[] = { 0,1,  1,1,  1,0,  0,0 }; // ���������� ����������. ������ � ���� ������ �������� ����� ������������� �� �������

    glEnable(GL_TEXTURE_2D); // ��������� ������������� ��������
    glBindTexture(GL_TEXTURE_2D, texture); // ������ ���� �������� ��������

    glColor3f(1, 1, 1); // ��� ����,����� � �������� ������������ ��� ����� - ����� ������� ����� ����
    glPushMatrix();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY); // ������ � �������� ���������� ���������

    glVertexPointer(3, GL_FLOAT, 0, vertex);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoord); // ����� �������, ������ ����� ���������� ���������� (1 - ���������� ���������� ��������� �� ������ �������, 2 - ��� ���������, 4 - ����� �������)
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D); // ����� ��������� �������� ���������� ��������� �������� ��������
    glPopMatrix();
}

void CDrawOpenGL::DrawValue(float x, float y, float size, float value, const char* format)
{
    unsigned int text_texture;
    char text[15] = "";

    InitText(text_texture);
    sprintf(text, format, value);

    ShowText(x, y, size, text_texture, text);

    glDeleteTextures(1, &text_texture);
}

void CDrawOpenGL::DrawText(float x, float y, float size, const char* text)
{
    unsigned int text_texture;

    InitText(text_texture);
    ShowText(x, y, size, text_texture, text);

    glDeleteTextures(1, &text_texture);
}

void CDrawOpenGL::InitText(unsigned int& text_texture)
{
    int width, height, cnt;
    unsigned char* data = stbi_load(TEXTURE_TEXT, &width, &height, &cnt, 0); // stbi_load - �������� �������� � ������, 2,3 - ������ ������, 4 - ����� ����������� �� �������

    glGenTextures(1, &text_texture); // ���������� ��������(1 - ���������� �������, ������ �� ���������� ��� ����� ��������)
    glBindTexture(GL_TEXTURE_2D, text_texture); // ������ �������� � ���������� (1 - ��� ��������, 2 - ������ �� ��������), GL_REPEAT - �������� ����� �����������

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // 1 - ��� ��������, 2 - ��� ��������� ��������, 3 - ��� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);// GL_TEXTURE_WRAP_S - ������ ���������� �������� �� �����������, GL_CLAMP - ������������ �� �������� �������� ����������� ������ ������� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // GL-TEXTURE_MIN_FILTER - ������� ���������� ��������
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL-TEXTURE_MAX_FILTER - ������� ���������� ��������
    // GL_NEAREST - ����� ����� ����������! �� ��������� �����, GL_LINEAR - ����� ����� ������ ����������������� �� ����� ����� � ������

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
        0, (cnt == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data); // (1 - ��� ��������, 3 - ��� ���������� �������� �� ���������� (4��������� rgba), 4,5 - ������ � ������ ������� ��������,
    // (7 - ��� ���������� ���������� �� ������� �������, 8 - ��� ���������� ������ �������� (0-255), 9 - ������ � ���������)

    glBindTexture(GL_TEXTURE_2D, 0); // ����� ��������� �������� ���������� ��������� �������� ��������

    stbi_image_free(data); // ����������� ������ �� ��������
}

void CDrawOpenGL::ShowText(float x, float y, float fontSize, unsigned int& text_texture, const char* text)
{
    float rectCoord[] = { x, y, 0,  (x+fontSize), y, 0,  (x+fontSize), (y-fontSize) ,0,  x, (y-fontSize), 0 };
    float rectTex[] = { 0,1,  1,1,  1,0,  0,0 }; // ���������� ����������. ������ � ���� ������ �������� ����� ������������� �� �������
    float left, right, top, bottom;

    glEnable(GL_TEXTURE_2D); // ��������� ������������� ��������
    glBindTexture(GL_TEXTURE_2D, text_texture); // ������ ���� �������� ��������

    glColor3f(1.0f, 1.0f, 1.0f); // ��� ����,����� � �������� ������������ ��� ����� - ����� ������� ����� ����
    glPushMatrix();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY); // ������ � �������� ���������� ���������

    glVertexPointer(3, GL_FLOAT, 0, rectCoord);
    glTexCoordPointer(2, GL_FLOAT, 0, rectTex); // ����� �������, ������ ����� ���������� ���������� (1 - ���������� ���������� ��������� �� ������ �������, 2 - ��� ���������, 4 - ����� �������)
    

    while (*text) {
        static float charSize = 1 / 16.0; //������ �������
        char c = *text;
        int posy = c >> 4;
        int posx = c & 0b1111;
        left = posx * charSize;
        right = left + charSize;
        top = posy * charSize;
        bottom = top + charSize;
        rectTex[0] = rectTex[6] = left;
        rectTex[2] = rectTex[4] = right;
        rectTex[1] = rectTex[3] = bottom;
        rectTex[5] = rectTex[7] = top;

        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

        text++;
        glTranslatef(fontSize, 0.0f, 0.0f);
    }

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisable(GL_TEXTURE_2D); // ����� ��������� �������� ���������� ��������� �������� ��������
    glPopMatrix();
}

void CDrawOpenGL::MoveTextureY(Texture* texture) 
{
    float movey;

    Calc_Screen_Offsets();

    if (((offset_x >= texture->x) && (offset_x <= (texture->x + texture->sizex))) &&
        ((offset_y <= (texture->y + texture->sizey)) && (offset_y >= (texture->y - texture->sizey)))) {
        if (GetAsyncKeyState(VK_LBUTTON) != 0) {
            movey = oldposy - offset_y;
            texture->y = offset_y - movey;
            texture->dy = texture->y - texture->sizey;
        }
    }
    oldposy = offset_y;

    LimitationY(texture);

    texture->local_posy = texture->ymax - texture->y;
        
}

void CDrawOpenGL::LimitationY(Texture* texture)
{

    if (texture->y > texture->ymax) {
        texture->y = texture->ymax;
        texture->dy = texture->y - texture->sizey;
    }

    else if (texture->y < texture->ymin) {
        texture->y = texture->ymin;
        texture->dy = texture->y - texture->sizey;
    }

}
