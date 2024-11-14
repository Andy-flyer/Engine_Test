#pragma once
class AirSpeedSettings {
public:

	double height;
	double speed;
	double temperature;
	double currenttla;
	double maxtla;

	int range_error;

	AirSpeedSettings()
	{
		height = speed = 0.0f;
		temperature = -5.0f;
		currenttla = 0.0f;
		maxtla = 50.;
		range_error = 0;
	}
};
