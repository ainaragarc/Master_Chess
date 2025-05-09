#include "Mundo.h"
#include "freeglut.h"
#include <cmath>

void Mundo::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();  // Restablece la matriz de modelo-vista
	

	//AQUI IRAN TODAS LAS FUNCIONES DIBUJA
	glDisable(GL_LIGHTING); // Opcional: desactiva iluminación si no la necesitas para 2D

	BROCHA.dibuja_t(TABLERO.get_numCas(), TABLERO.get_TamCuad()); // Dibuja el tablero

	glEnable(GL_LIGHTING);

}

void Mundo::mueve()
{
	//Todo lo que se mueva en el mundo o interactue entre sí

}
void Mundo::inicializa()
{
	BROCHA.init_t(BROCHA.get_longVent());
	TABLERO.inicializa_piezas();

}

