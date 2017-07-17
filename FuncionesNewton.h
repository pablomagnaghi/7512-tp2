#ifndef FUNCIONESNEWTON_H_
#define FUNCIONESNEWTON_H_

#include <stdio.h>
#include <math.h>

#define ERRORMIN	0.0001

float FdeX (float P, float Po, float V, float Qe, float Pe, float Qs, float K, float H,
	float A, float Ld, float area_lago, float D, float Pc, float delta_t);

float FDerivada (float P, float V, float Qe, float Pe, float Qs, float K, float H,
	float A, float Ld, float area_lago, float D, float Pc, float delta_t);

int NewtonRaphson (float P, float Po, float Vo, float area_lago, float Qm, float delta_Q,
		float Pe1, float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc,
		float delta_t, float mes, float t, float error, float* raiz, int* j);

#endif
