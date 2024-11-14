#include <windows.h>
#include <stdio.h>
#include "EngineData.h"
#include "AirSpeedSettings.h"
#include "DrawElements.h"
#include "EngStruct.h"
#include "Filters.h"
#include "Indication.h"
#include "L_interp.h"

FILE* inputData;

L_int_1 asp_data;
L_int_1 tla_data[2];

struct AFilter_structure AFilter_N2[2];
struct AFilter_structure AFilter_EGT[2];
struct AFilter_structure AFilter_FF[2];
struct AFilter_structure AFilter_Thrust[2];
struct AFilter_structure AFilter_Gv[2];
struct LFilter_structure LFilter_N1[2];

extern Texture thrl1;
extern Texture thrl2;
extern AirSpeedSettings settings;

EngStruct eng_stat[2];
Indication eng_ind[2];

float calc_out[30];

#define FILE_1 "EngData\\AirSpeedData.txt"


void InitData()
{
	errno_t err_log;
	err_log = fopen_s(&inputData, FILE_1, "r");

	if (err_log != 0)
	{
		MessageBox(NULL, L"The file 'AirSpeedData.txt' was not opened", L"Error", MB_OK);
	}


	asp_data.Init(FILE_1);


	AperiodicFilterInit(0.1f, 71.7f, &AFilter_N2[0]);//Eng1 N2
	AperiodicFilterInit(0.1f, 71.7f, &AFilter_N2[1]);//Eng2 N2
	LinearFilterInit(0.1f, 50.f, &LFilter_N1[0]);//Eng1 N1
	LinearFilterInit(0.1f, 50.f, &LFilter_N1[1]);//Eng2 N1
	AperiodicFilterInit(0.1f, 408.f, &AFilter_EGT[0]);//Eng1 EGT
	AperiodicFilterInit(0.1f, 408.f, &AFilter_EGT[1]);//Eng2 EGT
	AperiodicFilterInit(0.1f, 1105.0f, &AFilter_FF[0]);//Eng1 FF
	AperiodicFilterInit(0.1f, 1105.0f, &AFilter_FF[1]);//Eng2 FF
	AperiodicFilterInit(0.1f, 1650.0f, &AFilter_Thrust[0]);//Eng1 Thrust
	AperiodicFilterInit(0.1f, 1650.0f, &AFilter_Thrust[1]);//Eng2 Thrust
	AperiodicFilterInit(0.1f, 41.0f, &AFilter_Gv[0]);//Eng1 Gv
	AperiodicFilterInit(0.1f, 41.0f, &AFilter_Gv[1]);//Eng2 Gv
}

void Calculate(float height, float speed, float dT, float maxtla, double step, int numofEng)
{
	maxrange = (thrl1.ymax - thrl1.ymin) / maxtla;

	currenttla[0] = thrl1.local_posy / maxrange;
	currenttla[1] = thrl2.local_posy / maxrange;

	asp_data.CreateFuelTable(height, speed, dT);
	settings.range_error = asp_data.error;
	//Eng
	tla_data[numofEng].InitNewTable(asp_data);
	tla_data[numofEng].Calc(currenttla[numofEng], calc_out);

	eng_stat[numofEng].n2_static = calc_out[1] * 100.;
	eng_stat[numofEng].n1_static = calc_out[2] * 100.;
	eng_stat[numofEng].fFlow_static = calc_out[3];
	eng_stat[numofEng].thrust_static = calc_out[4] * 15000.;
	eng_stat[numofEng].temperature_EG_static = calc_out[5];
	eng_stat[numofEng].gv_static = calc_out[7];

	//N2
	target = eng_stat[numofEng].n2_static;
	t_filter = 25.0f * step;

	eng_ind[numofEng].n2 = AperiodicFilter(&target, &t_filter, &AFilter_N2[numofEng]);

	//N1
	target = eng_stat[numofEng].n1_static;

	if (target > eng_ind[numofEng].n1) {
		if (currenttla[numofEng] < (maxtla / 3.0f))
		{
			rate = 12.0f * step;
		}
		else {
			rate = 34.5f * step;
		}
	}

	else if (target < eng_ind[numofEng].n1) {
		rate = -38.5f * step;
	}

	eng_ind[numofEng].n1 = LinearFilter(&target, &rate, &LFilter_N1[numofEng]);

	//EGT
	target = eng_stat[numofEng].temperature_EG_static;
		if (currenttla[numofEng] < (maxtla / 3.0f) && (target < eng_ind[numofEng].egt_temperature))
		{
			t_filter = 30.0f * step;
		}
		else
		{
			t_filter = 40.0f * step;
		}

	eng_ind[numofEng].egt_temperature = AperiodicFilter(&target, &t_filter, &AFilter_EGT[numofEng]);

	//FF
	target = eng_stat[numofEng].fFlow_static;
	t_filter = 30.0f * step;

	eng_ind[numofEng].fuel_flow = AperiodicFilter(&target, &t_filter, &AFilter_FF[numofEng]);

	//Thrust
	target = eng_stat[numofEng].thrust_static;
	t_filter = 30.0f * step;

	eng_ind[numofEng].thrust = AperiodicFilter(&target, &t_filter, &AFilter_Thrust[numofEng]);

	//Gv
	target = eng_stat[numofEng].gv_static;
	t_filter = 25.0f * step;

	eng_ind[numofEng].gv = AperiodicFilter(&target, &t_filter, &AFilter_Gv[numofEng]);

}