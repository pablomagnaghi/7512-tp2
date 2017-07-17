#ifndef METODOS_H_
#define METODOS_H_

/*PUNTO B*/

#include <stdio.h>
#include <math.h>

#define ERRORMIN	0.0001

int EulerExplicito (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
	float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float N, float a,
	float b, char nomArchivo[]);

int EulerImplicito (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
	float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float N, float a,
	float b, char nomArchivo[]);

int RungeKuttaOrden2 (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
	float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float N, float a,
	float b, char nomArchivo[]);

#endif /* METODOS_H_ */
