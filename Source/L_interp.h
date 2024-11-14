#pragma once
#include <string>
#include <iostream>
#include <fstream>

// L_int_1 y = f(x)
class L_int_1
{
public:

	int ncolumns;
	int nrows;
	int headerSize;
	int i, j;
	int index;
	int count;
	int error;

	float map[30000][50];
	float newmap[30][100];
	float value;
	float cell;
	float x1, x2, y1, y2, z1, z2;

	std::string fileName;
	std::string header;
	std::string str;
	FILE* file;


	float Calc(float x, float* output);

	float Interpolation(float x1, float x2, float y1, float y2, float xInt);
	float Extrapolation(float x1, float x2, float y1, float y2, float xExt);
	void Init(const char* filename);
	void Read();
	void Counter();
	void CountSize();
	void Write_binary(const char* fname);
	void Init_binary(const char* fname);
	void Init_log(const char* fname, FILE* logf);
	void Log_Error(const char* message);
	void Log_Info(const char* message);
	void Log_Info(const char* message, int, int, int);
	void Message(const char* message);
	int CountBranches(int param);
	int CountPoints(int param);
	void CreateFuelTable(float x, float y, float z);
	void InitNewTable(L_int_1& oldtable);
	void CountSize(L_int_1& oldtable);
};

