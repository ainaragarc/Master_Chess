#include "Bot.h"

void Bot::juega(Mundo& mundo) {
    
    // En función de las piezas que juegue el bot se asigna un equipo y se asigna unos enemigos u otros
    const std::vector<Pieza*>& equipo_bot = juega_negras ? mundo.TABLERO.get_piezas_N() : mundo.TABLERO.get_piezas_B();

    //En el futuro las piezas del bot podemos hacerlas aleatorias
    std::vector<std::pair<Pieza*, Posicion>> movimientos_captura;
    std::vector<std::pair<Pieza*, Posicion>> movimientos_validos;

    // Buscar todos los movimientos válidos (2º bucle for) de todas las piezas del bot (1º bucle for) 
    for (Pieza* pieza : equipo_bot) {
        for (Posicion& destino : pieza->posiciones_posibles()) {
            bool es_captura = false;

            if (pieza->get_posicion() == destino) {
                continue; // Evitar que se coma a sí misma al moverse a su propia posición xd
            }

            // Busca las posiciones en las que es posible capturar
            if (juega_negras && mundo.TABLERO.hay_pieza_BLANCA(destino)) {
                es_captura = true;
            }
            else if (!juega_negras && mundo.TABLERO.hay_pieza_NEGRA(destino)) {
                es_captura = true;
            }

            if (es_captura) {
                movimientos_captura.push_back({ pieza, destino });
            }
            else {
                movimientos_validos.push_back({ pieza, destino });
            }

        }
    }
    
    if (movimientos_captura.empty() && movimientos_validos.empty()) {
        std::cout << "El bot no tiene movimientos disponibles\n";
        mundo.cambiar_turno_bot();// Si no puede mover, cambia el turno igualmente
        return;//Para salir de la función si no hay movimientos posibles (y cambiar de turno)
    }

    // Elegir entre capturas o movimientos normales, dando preferencia a los movimientos de captura
    std::vector<std::pair<Pieza*, Posicion>>& movimientos =
        !movimientos_captura.empty() ? movimientos_captura : movimientos_validos;

    std::srand(static_cast<unsigned>(std::time(nullptr)));//Para meterle aleatoriedad basándose en el tiempo
    int indice = std::rand() % movimientos.size();//Para que esté dentro de nuestro rango usamos %

    Pieza* pieza_elegida = movimientos[indice].first;
    Posicion destino = movimientos[indice].second;
    
    if (mundo.TABLERO.hay_pieza(destino)) {
        mundo.TABLERO.comer_pieza(destino);
    }

    pieza_elegida->mueve(destino);
    std::cout << "Bot movió una pieza a (" << destino.Fila << ", " << destino.Columna << ")\n";

    mundo.cambiar_turno_bot();
}