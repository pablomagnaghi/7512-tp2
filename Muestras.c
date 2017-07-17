#include "Muestras.h"

int mostrarParametros (float Po, float Vo, float area_lago, float Qm, float delta_Q, float Pe1,
		float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc)
{
	printf ("Parametros obtenidos con los numeros de padron XYZ = 126: \n");
	printf ("Concentracion media inicial de fosforo en el lago: %.2f (ug/l)\n", Po);
	printf ("volumen inicial del lago: %.2f (Hm^3)\n", Vo);
	printf ("Area horizontal media del lago: %.2f (Ha)\n", area_lago);
	printf ("Qm: %.2f (m^3/dia)\n", Qm );
	printf ("Delta_Q: %.2f (m^3/dia)\n", delta_Q);
	printf ("Concentracion de fosforo en el afluente en invierno: %.2f (ug/l)\n", Pe1);
	printf ("Concentracion de fosforo en el afluente en verano: %.2f (ug/l)\n", Pe2);
	printf ("Tasa de sedimentacion: %.6f (m/s)\n", K);
	printf ("Tasa de aporte lateral distribuido de fosforo por unidad de superficie de drenaje en mes: %.4f (Kg/(Ha.mes))\n", Ld1);
	printf ("Tasa de aporte lateral distribuido de fosforo por unidad de superficie de drenaje en mes: %.4f (Kg/(Ha.mes))\n", Ld2);
	printf ("Area horizontal de la superficie de drenaje: %.2f (Ha)\n", A);
	printf ("Tasa de desorcion desde sedimentos del fondo por unidad de superficie del lago: %.4f (Kg^1/2.mes/Ha^7/4)\n", Do);
	printf ("Concentracion critica para desorcion de fosforo desde los sedimentos del fondo: %.2f (ug/l)\n", Pc);

	printf ("\n");

	return 0;
}

int mostrarParametrosDefinitivos (float Po, float Vo, float area_lago, float Qm, float delta_Q,
		float Pe1, float Pe2, float K, float Ld1, float Ld2, float A, float Do, float Pc)
{
	printf ("Parametros con sus unidades definitivas: \n");
	printf ("Concentracion media inicial de fosforo en el lago: %.2f (Kg/Hm^3)\n", Po);
	printf ("volumen inicial del lago: %.2f (Hm^3)\n", Vo);
	printf ("Area horizontal media del lago: %.2f (Hm^2)\n", area_lago);
	printf ("Qm: %.8f (Hm^3/mes)\n", Qm );
	printf ("Delta_Q: %.8f (Hm^3/mes)\n", delta_Q);
	printf ("Concentracion de fosforo en el afluente en invierno: %.2f (Kg/Hm^3)\n", Pe1);
	printf ("Concentracion de fosforo en el afluente en verano: %.2f (Kg/Hm^3)\n", Pe2);
	printf ("Tasa de sedimentacion: %.6f (Hm/mes)\n", K);
	printf ("Tasa de aporte lateral distribuido de fosforo por unidad de superficie de drenaje en mes: %.4f Kg/(Hm^2.mes)\n", Ld1);
	printf ("Tasa de aporte lateral distribuido de fosforo por unidad de superficie de drenaje en mes: %.4f Kg/(Hm^2.mes)\n", Ld2);
	printf ("Area horizontal de la superficie de drenaje: %.2f (Hm^2)\n", A);
	printf ("Tasa de desorcion desde sedimentos del fondo por unidad de superficie del lago: %.4f (Kg^(1/2).mes^(-1).Hm^(-7/2))\n", Do);
	printf ("Concentracion critica para desorcion de fosforo desde los sedimentos del fondo: %.2f (Kg/Hm^3)\n", Pc);

	printf ("\n");

	return 0;
}
