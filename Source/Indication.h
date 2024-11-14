#pragma once
class Indication
{
public:
	float n1;
	float n2;
	float egt_temperature;
	float fuel_flow;
	float thrust;
	float gv;

	float egt_max;
	float fuel_flow_max;
	float thrust_max;
	float gv_max;

	Indication()
	{
		n1 = 50.;
		n2 = 71.5;
		egt_temperature = 417.5;
		fuel_flow = 0.28f;
		thrust = 1455.;
		gv = 39.9f;

		egt_max = 1300.;
		fuel_flow_max = 15000.;
		thrust_max = 16000.;
		gv_max = 200.;
	}

};
