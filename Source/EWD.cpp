#include "EWD.h"

using namespace System;
using namespace System::Windows::Forms;

AirSpeedSettings settings;

[STAThread]
int main(array<System::String^>^ args)
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	InitData();

	Application::Run(gcnew EngineTest::EWD());

	return 0;
}



void EngineTest::EWD::Update(double step)
{

	for (int i = 0; i < 2; i++) {
		Calculate(settings.height, settings.speed, settings.temperature, settings.maxtla, step, i);
	}

	settings.range_error == 1 ? label5->Text = "Error!\nOne of settings is out of range!" : label5->Text = " ";

	DrawOpenGL->Render();

	staticLocation = this->Location;

	fps = 1./step;
	this->Text = L"EWD: " + fps.ToString() + L"FPS";
	
}

void EngineTest::EWD::SetDataHeight()
{
	Double::TryParse(label7->Text, settings.height);
}

void EngineTest::EWD::SetDataSpeed()
{
	Double::TryParse(label8->Text, settings.speed);
}

void EngineTest::EWD::SetDataTemperature()
{
	Double::TryParse(label9->Text, settings.temperature);
}

void EngineTest::EWD::SetMaxTLA()
{
	Double::TryParse(textBox1->Text, settings.maxtla);
}



