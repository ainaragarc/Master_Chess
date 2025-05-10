#include "brocha.h"


void Brocha::dibuja_t(int numCasillas, float TamCuadrado) {
    float BOARD_OFFSET = -((numCasillas * TamCuadrado) / 2.0f);

    bool white = true;

    for (int i = 0; i < numCasillas; i++) {
        for (int j = 0; j < numCasillas; j++) {
            if (white)
                glColor3f(1.0f, 1.0f, 1.0f); // Blanco
            else
                glColor3f(0.0f, 0.0f, 0.0f); // Negro

            glBegin(GL_QUADS);
            glVertex2f(j * TamCuadrado + BOARD_OFFSET, i * TamCuadrado + BOARD_OFFSET);
            glVertex2f((j + 1) * TamCuadrado + BOARD_OFFSET, i * TamCuadrado + BOARD_OFFSET);
            glVertex2f((j + 1) * TamCuadrado + BOARD_OFFSET, (i + 1) * TamCuadrado + BOARD_OFFSET);
            glVertex2f(j * TamCuadrado + BOARD_OFFSET, (i + 1) * TamCuadrado + BOARD_OFFSET);
            glEnd();

            white = !white;
        }
        if (numCasillas % 2 == 0)
            white = !white;
    }

}

void Brocha::init_t(float longitudVentana)
{
    glClearColor(0.2f, 0.1f, 0.2f, 1.0f); // Fondo morado
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Aquí definimos una proyección ortográfica 2D
    gluOrtho2D(-longitudVentana, longitudVentana, -longitudVentana, longitudVentana);
    glMatrixMode(GL_MODELVIEW);
}

void Brocha::mouse(int button, int state, int x, int y, float longitudVentana, float TamCuadrado, int numCasillas,int& fila,int& columna) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        get_Pos(x, y,longitudVentana,TamCuadrado,numCasillas,fila,columna);

        if (fila >= 0 && fila < numCasillas && columna >= 0 && columna < numCasillas) {
            char letraColumna = 'A' + columna;
            std::cout << "Has hecho clic en la casilla (" << letraColumna << ", " << fila << ")\n";
        }
    }

}

Posicion Brocha::get_Pos(int x, int y,float longitudVentana,float TamCuadrado,int numCasillas,int& fila,int& columna) {
    // Convertir coordenadas de pantalla (x, y) a coordenadas de OpenGL
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    float glX = (float)x / windowWidth * 2 * longitudVentana - longitudVentana;
    float glY = (float)(windowHeight - y) / windowHeight * 2 * longitudVentana - longitudVentana;

    // Traducir coordenadas OpenGL a casilla de tablero
    float BOARDOFFSET = -((numCasillas * TamCuadrado) / 2.0f);
    columna = (int)std::floor(glX - BOARDOFFSET) / TamCuadrado;
    fila = (int)std::floor(glY - BOARDOFFSET) / TamCuadrado;
    Posicion posicion{ fila,columna };
    return posicion;
}

void Brocha::dibuja_ini(float TamCuadrado,int numCasillas, const std::vector<Pieza*>& equipo) {
    float BOARD_OFFSET = -((numCasillas * TamCuadrado) / 2.0f);

    for (auto i : equipo) {
        // Coordenadas del centro de la casilla deseada
        float posX = BOARD_OFFSET + (i->get_posicion_ini().Columna + 0.5f) * TamCuadrado;
        float posY = BOARD_OFFSET + (i->get_posicion_ini().Fila + 0.5f) * TamCuadrado;

        glPushMatrix(); // Guardar la matriz de transformación actual

        // Trasladar al centro de la casilla
        glTranslatef(posX, posY, 0.0f);
        // Escalar al tamaño de la casilla
        glScalef(TamCuadrado, TamCuadrado, 1.0f);

        //for (auto i : equipo) {
            //Foto de pieza
            glEnable(GL_TEXTURE_2D);
            glEnable(GL_BLEND); //Habilita blending
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Configura cómo se mezcla
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/w_queen_1x_ns.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);
            glColor3f(1, 1, 1);
            double xcoord1{ -0.5 }, xcoord2{ 0.5 };
            double ycoord1{ -0.5 }, ycoord2{ 0.5 };
            glTexCoord2d(0, 1); glVertex2d(xcoord1, ycoord1);
            glTexCoord2d(1, 1); glVertex2d(xcoord2, ycoord1);
            glTexCoord2d(1, 0); glVertex2d(xcoord2, ycoord2);
            glTexCoord2d(0, 0); glVertex2d(xcoord1, ycoord2);
            glEnd();
            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);

            glPopMatrix(); // Restaurar matriz de transformación
       // }
    }
}