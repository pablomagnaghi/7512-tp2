#include "FuncionesNewton.h"
#include "Funciones auxiliares.h"


float FdeX (float P, float Po, float V, float Qe, float Pe, float Qs, float K, float H,
	float A, float Ld, float area_lago, float D, float Pc, float delta_t)
{
	float valorAbsoluto, termino1, termino2, termino3, termino4, resultado;

	valorAbsoluto = fabs(Pc-P);

	termino1 = (Qe*Pe-Qs*P)/V;
	termino2 = (K*P)/H;
	termino3 = (A*Ld)/V;
	termino4 = area_lago*D*pow(valorAbsoluto,0.5);

	resultado = P - Po - delta_t*(termino1 - termino2 + termino3 + termino4);

	return resultado;
}


float FDerivada (float P, float V, float Qe, float Pe, float Qs, float K, float H,
	float A, float Ld, float area_lago, float D, float Pc, float delta_t)
{
	float valorAbsoluto, termino1, termino2, termino3, resultado;

	valorAbsoluto = fabs(Pc-P);

	termino1 = (Qs*P)/V;
	termino2 = K/H;
	termino3 = 0.5*area_lago*D*pow(valorAbsoluto,-0.5);

	resultado = 1 + delta_t * (termino1 + termino2 + termino3);

	return resultado;
}

int NewtonRaphson (float P, float Po, float Vo, float area_lago, float Qm, float delta_Q,
		float Pe1, float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc,
		float delta_t, float mes, float t, float error, float* raiz, int* j)
{
	float w, V, Qe, Qs, D, Ld, Pe, H, F, Fprima;

	while (error>ERRORMIN){

		P = *raiz;

		devolverParametrosFinales (P, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1,
				Ld2, A, Do, Pc, &w , &Qe, &Qs, &V, &D, &Ld, &Pe, &H, mes+delta_t, t+delta_t);

		F = FdeX (P, Po, V, Qe, Pe, Qs, K, H, A, Ld, area_lago, D, Pc, delta_t);

		Fprima = FDerivada (P, V, Qe, Pe, Qs, K, H, A, Ld, area_lago, D, Pc, delta_t);

		*raiz = P - (F/Fprima);

		error = fabs(((*raiz)-P)/(*raiz));

		*j = *j + 1;
		}

	return 0;

}







