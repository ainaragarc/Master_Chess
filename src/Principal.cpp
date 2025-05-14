#include "freeglut.h"
#include "Mundo.h"
#include <iostream>
void keyboard(unsigned char key, int x, int y);
Mundo mundo;

//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void onMouseClick(int button, int state, int x, int y);

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Master Chess");

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	//glutKeyboardFunc(keyboard);//Función para controlar con el teclado
	glutMouseFunc(onMouseClick);

	mundo.inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}


void onMouseClick(int button, int state, int x, int y)
{
	//mundo.BROCHA.mouse(button, state, x, y,mundo.BROCHA.get_longVent(), mundo.TABLERO.get_TamCuad(), mundo.TABLERO.get_numCas(),mundo.TABLERO.get_fila(), mundo.TABLERO.get_columna());
	mundo.gestionar_click(button, state, x, y);

}


void OnTimer(int value)
{
	//poner aqui el código de animacion
	mundo.mueve();

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}


//void keyboard(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'w': // Mover peón blanco hacia adelante
//		mundo.TABLERO.get_piezas_B()[2]->get_posicion().Fila+=1;
//		break;
//	case 'a': // Mover peón blanco hacia adelante
//		mundo.TABLERO.get_piezas_B()[2]->get_posicion().Columna -= 1;
//		break;
//	case 's': // Mover peón blanco hacia adelante
//		mundo.TABLERO.get_piezas_B()[2]->get_posicion().Fila -= 1;
//		break;
//	case 'd': // Mover peón blanco hacia adelante
//		mundo.TABLERO.get_piezas_B()[2]->get_posicion().Columna += 1;
//		break;
//	}
//
//	glutPostRedisplay();
//}