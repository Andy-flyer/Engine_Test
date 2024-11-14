#pragma once
/*
 * AperiodicFilter.h
 *
 *Author: Oleg Volkov
 *
 */
#include <math.h>

#ifndef INC_APERIODICFILTER_H_
#define INC_APERIODICFILTER_H_

static float target;
static float t_filter;
static float rate;

struct AFilter_structure {
	float T_filter;
	float T_dt;
	float outData;
};

void AperiodicFilterInit(float T_dt, float start_value, struct AFilter_structure* p);
float AperiodicFilter(float* inputData, float* T_filter, struct AFilter_structure* p);

#endif /* INC_APERIODICFILTER_H_ */

struct LFilter_structure {
	float temp;
	float T_dt;
	float outData;
};

void LinearFilterInit(float T_dt, float start_value, struct LFilter_structure* p);
float LinearFilter(float* inputData, float* rate, struct LFilter_structure* p);