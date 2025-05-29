#include "Mundo.h"
#include "GestorEstados.h"
#include "freeglut.h"
#include <cmath>

#include <iostream>

Mundo* punteroMundo = nullptr;//inicializo puntero global el puntero global

//funcion para obtener el nivel del bot
int Mundo::get_nivel_bot() const {
    return estado ? estado->get_nivel_bot_como_int() : 1;
}

void Mundo::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();  // Restablece la matriz de modelo-vista
	

	//AQUI IRAN TODAS LAS FUNCIONES DIBUJA
	glDisable(GL_LIGHTING); // Opcional: desactiva iluminación si no la necesitas para 2D

	BROCHA.dibuja_t(TABLERO.get_numCas(), TABLERO.get_TamCuad()); // Dibuja el tablero
	BROCHA.dibuja_ini(TABLERO.get_TamCuad(), TABLERO.get_numCas(),TABLERO.get_piezas_B());//Dibuja las piezas de inicio
	BROCHA.dibuja_ini(TABLERO.get_TamCuad(), TABLERO.get_numCas(), TABLERO.get_piezas_N());
    if (!casillas_posibles.empty()) {
        BROCHA.resalta_casillas(casillas_posibles, TABLERO.get_TamCuad(), TABLERO.get_numCas());
    }
	glEnable(GL_LIGHTING);

}

void Mundo::mueve()
{
	//Todo lo que se mueva en el mundo o interactue entre sí

}
void Mundo::inicializa_tablero_gardner()
{
    punteroMundo = this;//asigno al puntero la instancia actual de mundo
    TABLERO.inicializa_piezas_GARDNER();
	BROCHA.init_t(BROCHA.get_longVent());
		
}

void Mundo::inicializa_tablero_baby() {

    punteroMundo = this;
    TABLERO.inicializa_piezas_BABY();
    BROCHA.init_t(BROCHA.get_longVent());
}

void Mundo::gestionar_click(int button, int state, int x, int y) {

    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    int fila, columna;
    Posicion clic = BROCHA.get_Pos(x, y,
        BROCHA.get_longVent(),
        TABLERO.get_TamCuad(),
        TABLERO.get_numCas(),
        fila, columna);

    if (fila < 0 || fila >= TABLERO.get_numCas() ||
        columna < 0 || columna >= TABLERO.get_numCas()) {
        std::cout << "Ninguna casilla seleccionada\n";
        pieza_seleccionada = nullptr;
        casillas_posibles.clear();
        esperando_segundo_click = false;
        return;
    }

    Posicion destino{ fila, columna };

    // SEGUNDO CLIC
    if (esperando_segundo_click && pieza_seleccionada) {
        if (pieza_seleccionada->movimiento_posible(destino)) {
            Posicion origen = pieza_seleccionada->get_posicion();

            // Simular el movimiento
            Pieza* capturada = nullptr;
            if (TABLERO.hay_pieza(destino)) {
                capturada = TABLERO.comer_pieza(destino); // <-- asegúrate de que esta función devuelve la pieza capturada
            }

            pieza_seleccionada->mueve(destino);

            // Comprobar si el rey propio sigue en jaque
            if (TABLERO.Jaque(pieza_seleccionada->get_color())) {
                // Revertir el movimiento
                pieza_seleccionada->mueve(origen);
                if (capturada) {
                    if (capturada->get_color() == BLANCO)
                        TABLERO.get_piezas_B().push_back(capturada);
                    else
                        TABLERO.get_piezas_N().push_back(capturada);
                }

                std::cout << "Movimiento ilegal: estás en jaque\n";
            }
            else {
                // Movimiento válido
                Color color_enemigo = (pieza_seleccionada->get_color() == BLANCO) ? NEGRO : BLANCO;

                if (TABLERO.Jaque(color_enemigo)) {
                    std::cout << "JAQUE AL REY " << (color_enemigo == BLANCO ? "BLANCO" : "NEGRO") << "!\n";
                    if (TABLERO.es_jaque_mate(color_enemigo)) {
                        std::cout << "¡JAQUE MATE!\n";
                        if (estado) {
                            estado->cambiar_estado(color_enemigo == BLANCO ? VICTORIA_NEGRO : VICTORIA_BLANCO);
                        }
                        return;
                    }
                }

                if (TABLERO.comprobar_coronacion(pieza_seleccionada)) {
                    std::cout << "CORONAR EL PEON" << std::endl;
                    estado->cambiar_estado(CORONACION);
                    return;
                }

                 if (TABLERO.es_ahogado(color_enemigo)) {
                     std::cout << "ES AHOGADO DEL REY " << (color_enemigo == BLANCO ? "BLANCO" : "NEGRO") << "!\n";
                     estado->cambiar_estado(TABLAS);
                     return;
                 }

                 if (TABLERO.solo_quedan_reyes()) {
                     std::cout << "SOLO QUEDAN REYES " << "!\n";
                     estado->cambiar_estado(Estado::TABLAS);
                     return;
                 }

                turno_actual = cambiar_turno(turno_actual);
                std::cout << "Movimiento exitoso. Turno: " << a_string(turno_actual) << "\n";
            }
        }
        else {
            std::cout << "Movimiento inválido\n";
        }

        pieza_seleccionada = nullptr;
        //Limpiamos el vector casillas_posibles
        casillas_posibles.clear();
        esperando_segundo_click = false;
    }

    // PRIMER CLIC
    std::vector<Pieza*> piezas = es_blanco(turno_actual) ? TABLERO.get_piezas_B() : TABLERO.get_piezas_N();

    for (auto& p : piezas) {
        if (p->get_posicion() == destino) {
            pieza_seleccionada = p;
            casillas_posibles = p->posiciones_posibles();
            esperando_segundo_click = true;

            std::cout << "Pieza seleccionada. Posibles movimientos:\n";
            for (const auto& pos : casillas_posibles)
                std::cout << "- (" << pos.Fila << ", " << pos.Columna << ")\n";
            return;
        }
    }

    std::cout << "No hay pieza seleccionada\n";
}

void Mundo::seleccionar_coronacion(unsigned char tipo) { 
    //se supone que estamos dentro de la pantalla de coronacion, tipo lo establece la pantalla de coronacion
    if (pieza_seleccionada !=nullptr) {
        TABLERO.coronar(pieza_seleccionada, tipo);
        turno_actual = cambiar_turno(turno_actual);

        pieza_seleccionada = nullptr;
        casillas_posibles.clear();
        esperando_segundo_click = false;
    }

}

void Mundo::cambiar_turno_bot() {

    Color color_enemigo = (turno_actual == Turno::BLANCO) ? NEGRO : BLANCO;

    if (TABLERO.es_ahogado(color_enemigo)) {
        std::cout << "REY AHOGADO " << (color_enemigo == BLANCO ? "BLANCO" : "NEGRO") << "!\n";
        estado->cambiar_estado(Estado::TABLAS);
        return;
    }

    if (TABLERO.es_jaque_mate(color_enemigo) && color_enemigo == BLANCO) {
        std::cout << "ES JAQUEMATE " << (color_enemigo == BLANCO ? "BLANCO" : "NEGRO") << "!\n";
        estado->cambiar_estado(Estado::VICTORIA_NEGRO);
        return;
    }

    if (TABLERO.solo_quedan_reyes()) {
        std::cout << "SOLO QUEDAN REYES " << "!\n";
        estado->cambiar_estado(Estado::TABLAS);
        return;
    }

    turno_actual = cambiar_turno(turno_actual);

}