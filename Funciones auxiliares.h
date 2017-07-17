#ifndef FUNCIONESAUXILIARES_H_
#define FUNCIONESAUXILIARES_H_

#define PI	3.141592654

#include <stdio.h>
#include <math.h>

int arreglarUnidades (float* Po, float* Vo, float* area_lago, float* Qm, float* delta_Q,
	float* Pe1, float* Pe2, float* K, float* Ld1, float* Ld2, float* A, float* Do,
	float* Pc);

float devolverOmega (float t);

float devolverCaudalQe (float w, float Qm, float delta_Q, float t);

float devolverCaudalQs (float w, float Qm, float delta_Q, float t);

float devolverVolumenDelLago (float Vo, float Qe, float Qs, float delta_t);

float devolverTasaDeDesorcion (float P, float Pc, float Do);

float devolverTasaDeAporteLd (float t, float Ld1, float Ld2);

float devolverConcentracionDeFosforo (float t, float Pe1, float Pe2);

float devolverProfundidad (float V, float area_lago);

int devolverParametrosFinales (float P, float Vo, float area_lago, float Qm, float delta_Q,
	float Pe1, float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float*w,
	float* Qe, float* Qs, float* V, float* D, float* Ld, float* Pe, float* H, float mes,
	float t);

float funcion (float P, float V, float Qe, float Pe, float Qs, float K, float H, float A,
	float Ld, float area_lago, float D, float Pc);

#endif /* FUNCIONESAUXILIARES_H_ */
