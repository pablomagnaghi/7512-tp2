#include "Metodos.h"
#include "Funciones auxiliares.h"
#include "FuncionesNewton.h"

/*PUNTO B*/

int EulerExplicito (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
	float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float N, float a,
	float b, char nomArchivo[])
{
	int i, Anio;
	float t, mes, w, V, Qe, Qs, D, Ld, Pe, delta_t, H, Un;

	FILE *archivo;
	archivo = fopen (nomArchivo, "wt");

	delta_t = (b - a)/N;

	mes = 1;
	Anio = 1;
	Un = Po;
	t = a;
	i = 0;

	fprintf (archivo, nomArchivo);

	fprintf (archivo, "\n");

	fprintf (archivo, "SOLUCION PARA EULER EXPLICITO \n");

	fprintf (archivo, "Paso = %.2f\n", delta_t);

	fprintf (archivo, "Año: %i\n", Anio);

	fprintf (archivo, "U%i = %.6f  T = %.1f  MES = %.1f\n", i, Un, t, mes);

	for (i=1; i<=N; i++){

		t= t + delta_t;
		mes= mes + delta_t;

		if (mes >= 13)
		{
			mes = 1;
			Anio++;
			fprintf (archivo, "Año: %i\n", Anio);
		}
		devolverParametrosFinales (Un, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1,
		Ld2, A, Do, Pc, &w , &Qe, &Qs, &V, &D, &Ld, &Pe, &H, mes, t);

		Un = Un + delta_t * funcion (Un, V, Qe, Pe, Qs, K, H, A, Ld, area_lago, D, Pc);

		fprintf (archivo, "U%i = %.6f  T = %.2f  MES = %.2f\n", i, Un, t, mes);

	}

	return 0;
}

int EulerImplicito (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
	float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float N, float a,
	float b, char nomArchivo[])
{
	int i, j, Anio;
	float t, delta_t, mes, raiz, error, Un, UnMas1;

	FILE *archivo;
	archivo = fopen (nomArchivo, "wt");

	delta_t = (b - a)/N;

	mes = 1;
	Anio = 1;
	Un = Po;
	t = a;
	i = 0;

	fprintf (archivo, nomArchivo);

	fprintf (archivo, "\n");

	fprintf (archivo, "SOLUCION PARA EULER IMPLICITO \n");

	fprintf (archivo, "Paso = %.2f\n", delta_t);

	fprintf (archivo, "Año: %i\n", Anio);

	fprintf (archivo, "U%i = %.6f  T = %.1f  MES = %.1f\n", i, Un, t, mes);

	for (i=1; i<=N; i++){

		t= t + delta_t;
		mes= mes + delta_t;

		if (mes >= 13)
		{
			mes = 1;
			Anio++;
			fprintf (archivo, "Año: %i\n", Anio);
		}

		j = 0;
		raiz=1;
		error=1;

		NewtonRaphson (UnMas1, Un, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1,
				Ld2, A, Do, Pc, delta_t, mes+delta_t, t+delta_t, error, &raiz, &j);

		UnMas1= raiz;

		Un = UnMas1;

		fprintf (archivo, "U%i = %.6f  T = %.2f  MES = %.2f Iteraciones hechas con Newton Raphson: %i\n", i, Un, t, mes, j);

	}

	return 0;
}

int RungeKuttaOrden2 (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
	float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc, float N, float a,
	float b, char nomArchivo[])
{
	int i, Anio;
	float t, mes, w, V, Qe, Qs, D, Ld, Pe, delta_t, H, Q1, Q2, Un;

	FILE *archivo;
	archivo = fopen (nomArchivo, "wt");


	delta_t = (b - a)/N;
	mes = 1;
	Anio = 1;
	Un = Po;
	t = a;
	i = 0;

	fprintf (archivo, nomArchivo);

	fprintf (archivo, "\n");

	fprintf (archivo, "SOLUCION PARA RUNGE KUTTA ORDEN 2\n");

	fprintf (archivo, "Paso = %.2f\n", delta_t);

	fprintf (archivo, "Año: %i\n", Anio);

	fprintf (archivo, "U%i = %.6f  T = %.1f  MES = %.1f\n", i, Un, t, mes);

	for (i=1; i<=N; i++){

		t= t + delta_t;
		mes= mes + delta_t;

		if (mes >= 13)
		{
			mes = 1;
			Anio++;
			fprintf (archivo, "Año: %i\n", Anio);
		}

	devolverParametrosFinales (Un, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1,
			Ld2, A, Do, Pc, &w , &Qe, &Qs, &V, &D, &Ld, &Pe, &H, mes, t);

	Q1 = delta_t * funcion (Un, V, Qe, Pe, Qs, K, H, A, Ld, area_lago, D, Pc);

	devolverParametrosFinales (Un + Q1, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1,
				Ld2, A, Do, Pc, &w , &Qe, &Qs, &V, &D, &Ld, &Pe, &H, mes+delta_t, t+delta_t);

	Q2 = delta_t * funcion (Un + Q1, V, Qe, Pe, Qs, K, H, A, Ld, area_lago, D, Pc);

	Un = Un + 0.5 * (Q1 + Q2);

	fprintf (archivo, "U%i = %.6f  T = %.2f  MES = %.2f\n", i, Un, t, mes);

	}

	return 0;

}

