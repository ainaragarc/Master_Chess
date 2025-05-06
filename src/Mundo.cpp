#include "Mundo.h"
#include "freeglut.h"
#include <cmath>

void Mundo::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();  // Restablece la matriz de modelo-vista
	

	//AQUI IRAN TODAS LAS FUNCIONES DIBUJA
	glDisable(GL_LIGHTING); // Opcional: desactiva iluminación si no la necesitas para 2D

<<<<<<< Updated upstream
	TABLERO.dibuja();  // Dibuja el tablero
	//PIEZA.dibuja(0.4, 10); // En algun momento tendremos que sustituir PIEZA por los nombres de cada figura y FALTA colocar las esferas en su sitio //
=======
	BROCHA.dibuja_t(5, 1.0f, -2.5f); // Dibuja el tablero
	PIEZA.dibuja(0.4, 10); // En algun momento tendremos que sustituir PIEZA por los nombres de cada figura y FALTA colocar las esferas en su sitio //
>>>>>>> Stashed changes

	glEnable(GL_LIGHTING);

}

void Mundo::mueve()
{
	//Todo lo que se mueva en el mundo o interactue entre sí

}
void Mundo::inicializa()
{
	x_ojo = 0;
	y_ojo = 0;
	z_ojo = 10;

	BROCHA.init_t();
}

