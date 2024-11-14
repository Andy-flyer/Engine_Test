#include "Filters.h"

void AperiodicFilterInit(float T_dt, float start_value, struct AFilter_structure* p) {
	p->T_dt = T_dt;
	p->outData = start_value;
}

float AperiodicFilter(float* inputData, float* T_filter, struct AFilter_structure* p) {
	float Temp_data;

	p->T_filter = *T_filter;

	if (p->T_filter <= 0.0f) {
		p->outData = *inputData;
	}
	else {
		Temp_data = (*inputData - p->outData) / p->T_filter;
		p->outData = p->outData + Temp_data * p->T_dt;
	}
	return p->outData;
}

void LinearFilterInit(float T_dt, float start_value, struct LFilter_structure* p) {
	p->T_dt = T_dt;
	p->outData = start_value;
}

float LinearFilter(float* inputData, float* rate, struct LFilter_structure* p) {
	int isStatic;

	isStatic = (fabs(p->outData) < 0.01 && fabs(*inputData) < 0.01) ? 1 :
		(p->outData > (0.99 * *inputData) && p->outData < (1.01 * *inputData)) ? 1 : 0;

	p->temp = *rate;

	if (isStatic) {
		p->outData = *inputData;
	}
	else {
		p->outData = p->outData + p->temp * p ->T_dt;
	}

	return p->outData;
}