/*TP2 ECUACIONES DIFERENCIALES ORDINARIAS: EUTROFIZACION LACUSTRE*/

#include <stdio.h>
#include <math.h>
#include "Muestras.h"
#include "Funciones auxiliares.h"
#include "Metodos.h"


#define PI	3.141592654

/*PARAMETROS XYZ=126*/

const float x = 1;
const float y = 2;
const float z = 6;

int main (){

	//variables creadas con los numeros de padron

	float Po = (x*100+y*10+z)/100;	//concentracion media inicial de fosforo en el lago
	float Vo = y*10+z;				//volumen inicial del lago
	float area_lago = x*100+y*10+z;	//area horizontal media del lago
	float Qm = (z+1)/(z+2)*5000;
	float delta_Q = 0.75 * Qm;
	float Pe1 = (x*100+y*10+z)/20;	//concentracion de fosforo en el afluente
	float Pe2 = (x*100+y*10+z)/50;	//concentracion de fosforo en el afluente
	float K = pow (10,-6);			//tasa de sedimentacion
	float Ld1 = (z+1)/2500;			//tasa de aporte lateral distribuido de fosforo
	float Ld2 = (z+1)/10000;		//tasa de aporte lateral distribuido de fosforo
	float A = pow (x*100+y*10+z,2);	//area horizontal de la superficie de drenaje
	float Do = (z+y)/10000;			//tasa de desorcion desde sedimentos del fondo
	float Pc = 5;					//concentracion critica para desorcion de fosforo

	/*PUNTO A*/

	mostrarParametros (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc);

	arreglarUnidades (&Po, &Vo, &area_lago, &Qm, &delta_Q, &Pe1, &Pe2, &K, &Ld1, &Ld2, &A, &Do, &Pc);

	mostrarParametrosDefinitivos (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc);

	//PUNTO C1 CANTIDAD DE PASOS: 2400 INTERVALO: t=[0,240] DELTA_T=0.1

	EulerExplicito (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc,
		2400, 0, 240, "Euler Explicito Punto C1.txt");

	//PUNTO C2 CANTIDAD DE PASOS : 240 INTERVALO: t=[0,240] DELTA_T=1

	EulerExplicito (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc,
		240, 0, 240, "Euler Explicito Punto C2.txt");

	//PUNTO C3 CANTIDAD DE PASOS : 24000 INTERVALO: t=[0,240] DELTA_T=0.01

	EulerExplicito (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc,
		24000, 0, 240,  "Euler Explicito Punto C3.txt");

	//PUNTO C4 CANTIDAD DE PASOS : 240 INTERVALO: t=[0,240] DELTA_T=1

	EulerImplicito (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc,
		240, 0, 240, "Euler Implicito Punto C4.txt");

	//PUNTO C4 CANTIDAD DE PASOS : 240 INTERVALO: t=[0,240] DELTA_T=1

	RungeKuttaOrden2 (Po, Vo, area_lago, Qm, delta_Q, Pe1, Pe2, K, Ld1, Ld2, A, Do, Pc,
		240, 0, 240, "Runge Kutta Orden 2 Punto C5.txt");

	return 0;

}



