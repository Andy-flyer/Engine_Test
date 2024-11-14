#pragma once
class Texture
{
public:

	float x;
	float y;
	float dx;
	float dy;
	char* fileName;

	float sizex;
	float sizey;

	float xmin;
	float xmax;
	float ymin;
	float ymax;

	float local_posx;
	float local_posy;

	void Set(float x, float y, float dx, float dy, char* fileName)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->fileName = fileName;

		sizex = this->dx - this->x;
		sizey = this->y - this->dy;
	}

	void SetMinMaxValues(float xmin, float xmax, float ymin, float ymax)
	{
		this->xmin = xmin;
		this->xmax = xmax;
		this->ymin = ymin;
		this->ymax = ymax;
	}

	void SetMinMaxValues(float ymin, float ymax)
	{
		this->ymin = ymin;
		this->ymax = ymax;
	}

};