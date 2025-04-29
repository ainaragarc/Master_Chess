#include "freeglut.h"
#include <iostream>

#define BOARD_SIZE 5
//Ver si se puede hacer plenamente con macros en vez de variables const (u otra forma más eficiente)
const float SQUARE_SIZE = 1.0f;
const float BOARD_OFFSET = -((BOARD_SIZE * SQUARE_SIZE) / 2.0f);

//Función que dibuja el tablero
void drawBoard() {
    bool color_casilla = true;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (color_casilla)
                glColor3ub(190, 27, 27);//Rojo
            else
                glColor3ub(0.0f, 0.0f, 0.0f); // Negro //

            glBegin(GL_QUADS);
            glVertex2f(j * SQUARE_SIZE + BOARD_OFFSET, i * SQUARE_SIZE + BOARD_OFFSET);
            glVertex2f((j + 1) * SQUARE_SIZE + BOARD_OFFSET, i * SQUARE_SIZE + BOARD_OFFSET);
            glVertex2f((j + 1) * SQUARE_SIZE + BOARD_OFFSET, (i + 1) * SQUARE_SIZE + BOARD_OFFSET);
            glVertex2f(j * SQUARE_SIZE + BOARD_OFFSET, (i + 1) * SQUARE_SIZE + BOARD_OFFSET);
            glEnd();

            color_casilla = !color_casilla;
        }
        if (BOARD_SIZE % 2 == 0)
            color_casilla = !color_casilla;
    }
}

//(callback) función llamada para dibujar, igual que la función OnDraw de las prácticas pero que le he puesto el nombre de display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawBoard();

    glutSwapBuffers();
}

//función para el control del ratón
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

        float glX = (float)x / windowWidth * 6.0f - 3.0f;
        float glY = (float)(windowHeight - y) / windowHeight * 6.0f - 3.0f;

        // Traducir coordenadas OpenGL a casilla de tablero
        int col = (int)((glX - BOARD_OFFSET) / SQUARE_SIZE);
        int row = (int)((glY - BOARD_OFFSET) / SQUARE_SIZE);

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            std::cout << "Has hecho clic en la casilla (" << row << ", " << col << ")\n";
        }
    }
}

//Inicialización de la vista
void init() {
    glClearColor(0.29f, 0.0f, 0.51f, 1.0f); // Fondo morado (relativo al 255 del RGB)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Aquí definimos una proyección ortográfica 2D
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Master_Chess");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
