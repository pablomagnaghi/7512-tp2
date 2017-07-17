#include "Funciones auxiliares.h"

int arreglarUnidades (float* Po, float* Vo, float* area_lago, float* Qm, float* delta_Q,
	float* Pe1, float* Pe2, float* K, float* Ld1, float* Ld2, float* A, float* Do, float* Pc)
{
	*Po = *Po; //(de ug/dm^3 a Kg/Hm^3)
	*Vo = *Vo; //(Hm^3)
	*area_lago = *area_lago; //(de Ha a Hm^2)
	*Qm = *Qm *  (pow(10, -6)* 30); //(de m^3/dia a Hm^3/mes)
	*delta_Q = *delta_Q * (pow(10, -6)* 30); //(de m^3/dia a Hm^3/mes)
	*Pe1 = *Pe1; //(de ug/dm^3 a Kg/Hm^3)
	*Pe2 = *Pe2; //(de ug/dm^3 a Kg/Hm^3)
	*K = *K * ((86400*30)/100); //(m/seg de Hm/dia)
	*Ld1 = *Ld1; //(de Kg/(Ha.mes) a Kg/(Hm^2.mes))
	*Ld2 = *Ld2; //(de Kg/(Ha.mes) a Kg/(Hm^2.mes))
	*A = *A; //(de Ha a Hm^2)
	*Do = *Do; //(de Kg^(1/2).mes^(-1).Ha^(-7/2) a Kg^(1/2).mes^(-1).Hm^(-7/2)
	*Pc = *Pc; //(de ug/dm^3 a Kg/Hm^3)

	return 0;
}


float devolverOmega (float t)
{
	float w;

	w = (PI/6)*(1/t);

	return w;
}

float devolverCaudalQe (float w, float Qm, float delta_Q, float t)
{
	float Qe;

	Qe = Qm + delta_Q * cos(w*t);

    return Qe;
}

float devolverCaudalQs (float w, float Qm, float delta_Q, float t)
{
	float Qs;

	Qs = Qm + delta_Q * cos(w*(t-3));

    return Qs;
}

float devolverVolumenDelLago (float Vo, float Qe, float Qs, float delta_t)
{
	float V;

	V = Vo + (Qe - Qs)*delta_t;

	return V;
}

float devolverTasaDeDesorcion (float P, float Pc, float Do)
{
	float D;

	if (P<Pc)
		D = Do;
	else D = 0;

	return D;
}

float devolverTasaDeAporteLd (float t, float Ld1, float Ld2){
	float Ld;

	if ((t>=9) && (t<10)) // esta en el mes 9
		Ld = Ld1;
	else if ((t>=3) && (t<4)) // esta en el mes 3
		Ld = Ld2;
	else Ld = 0;

	return Ld;
}

float devolverConcentracionDeFosforo (float t, float Pe1, float Pe2){

	float Pe;

	if ((3<t) && (t<10)) /* 3<t<10 t puede ser 9 */
		Pe = Pe1;
	else Pe = Pe2;       /* t>9 && t<2 t puede ser 3*/

	return Pe;
}

float devolverProfundidad (float V, float area_lago){
	float H;

	H = V/area_lago;

	return H;
}

int devolverParametrosFinales (float P, float Vo, float area_lago, float Qm, float delta_Q,
	float Pe1, float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc,
	float* w, float* Qe, float* Qs, float* V, float* D, float* Ld, float* Pe, float* H,
	float mes, float t)
{
	*w = devolverOmega (mes);

	*Qe = devolverCaudalQe (*w, Qm, delta_Q, mes);

	*Qs = devolverCaudalQs (*w, Qm, delta_Q, mes);

	*V = devolverVolumenDelLago (Vo, *Qe, *Qs, t);

	*D = devolverTasaDeDesorcion (P, Pc, Do);

	*Ld = devolverTasaDeAporteLd (mes, Ld1, Ld2);

	*Pe = devolverConcentracionDeFosforo (mes, Pe1, Pe2);

	*H = devolverProfundidad (*V, area_lago);

	return 0;

}

float funcion (float P, float V, float Qe, float Pe, float Qs, float K, float H,
		float A, float Ld, float area_lago, float D, float Pc)
{
	float valorAbsoluto, termino1, termino2, termino3, termino4, resultado;

	valorAbsoluto = fabs(Pc-P);

	termino1 = (Qe*Pe-Qs*P)/V;
	termino2 = (K*P)/H;
	termino3 = (A*Ld)/V;
	termino4 = area_lago*D*pow(valorAbsoluto,0.5);

	resultado = termino1 - termino2 + termino3 + termino4;

	return resultado;
}




