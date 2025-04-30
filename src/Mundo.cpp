#include "Mundo.h"
#include "freeglut.h"
#include <cmath>

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,
		0.0, y_ojo, 0.0, //NOTESE QUE HEMOS CAMBIADO ESTO
		0.0, 1.0, 0.0); //PARA MIRAR AL CENTRO DE LA ESCENA

	//AQUI IRAN TODAS LAS FUNCIONES DIBUJA
	glLoadIdentity();  // Restablece la matriz de modelo-vista
	glDisable(GL_LIGHTING); // Opcional: desactiva iluminación si no la necesitas para 2D

	TABLERO.dibuja();  // Dibuja el tablero
	PIEZA.dibuja(0.4, 10); // En algun momento tendremos que sustituir PIEZA por los nombres de cada figura y FALTA colocar las esferas en su sitio //

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

	TABLERO.init();	
}

