#include "Bot.h"

void Bot::juega(Mundo& mundo) {

    // En función de las piezas que juegue el bot se asigna un equipo y se asigna unos enemigos u otros
    const std::vector<Pieza*>& equipo_bot = juega_negras ? mundo.TABLERO.get_piezas_N() : mundo.TABLERO.get_piezas_B();
    std::vector<Pieza*>& equipo_jugador = juega_negras ? mundo.TABLERO.get_piezas_B() : mundo.TABLERO.get_piezas_N(); // ¡Corregido! Enemigo real
    Color color_bot = juega_negras ? NEGRO : BLANCO;

    // En el futuro las piezas del bot podemos hacerlas aleatorias
    std::vector<std::pair<Pieza*, Posicion>> movimientos_captura;
    std::vector<std::pair<Pieza*, Posicion>> movimientos_validos;

    // Algoritmo para que se proteja en caso de Jaque
    // Probamos todos los movimientos posibles
    if (mundo.TABLERO.Jaque(color_bot)) {
        for (Pieza* pieza : equipo_bot) {
            Posicion origen = pieza->get_posicion();
            std::vector<Posicion> movimientos = pieza->posiciones_posibles_conrey();

            for (const Posicion& destino : movimientos) {
                // Guardamos la pieza que había en el destino
                Pieza* capturada = mundo.TABLERO.get_pieza_en_pos(destino);
                bool fue_capturada = false;

                // Simulamos capturar la pieza enemiga
                if (capturada != nullptr) {
                    // Hacemos uso de iteradores y de la función find de <vector> para buscar el puntero "capturada"
                    auto it = std::find(equipo_jugador.begin(), equipo_jugador.end(), capturada);
                    if (it != equipo_jugador.end()) {
                        equipo_jugador.erase(it); // Eliminamos la pieza como si hubiese sido capturada
                        fue_capturada = true;
                    }
                }

                pieza->mueve(destino); // simulamos el movimiento
                bool sigue_en_jaque = mundo.TABLERO.Jaque(color_bot); // comprobamos si sigue en jaque
                pieza->mueve(origen); // revertimos movimiento

                if (fue_capturada) {
                    equipo_jugador.push_back(capturada); // restauramos la pieza capturada
                }

                if (!sigue_en_jaque) {
                    movimientos_validos.push_back({ pieza, destino }); // Si evita el jaque, se guarda
                }
            }
        }

        if (movimientos_validos.empty()) {
            std::cout << "Bot está en jaque mate.\n";
            mundo.cambiar_turno_bot();
            return;
        }

        // HE COMENTADO EL RANDOM QUE SELECCIONA EL INDICE, escogemos el que tiene mayor puntuación, o sea el 0
        Pieza* pieza_elegida = movimientos_validos[0].first;
        Posicion destino = movimientos_validos[0].second;

        if (mundo.TABLERO.hay_pieza(destino)) {
            mundo.TABLERO.comer_pieza(destino);
        }

        pieza_elegida->mueve(destino);
        std::cout << "Bot salió del jaque moviendo a (" << destino.Fila << ", " << destino.Columna << ")\n";
        mundo.cambiar_turno_bot();
        return; // Importante: evitamos que siga ejecutando el turno como si no hubiera habido jaque
    }

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
        mundo.cambiar_turno_bot(); // Si no puede mover, cambia el turno igualmente
        return; // Para salir de la función si no hay movimientos posibles (y cambiar de turno)
    }

    // FUNCIÓN PARA ORDENAR LA CAPTURA EN ORDEN DE PUNTUACIÓN
    if (!movimientos_captura.empty()) {
        std::vector<int> puntos;
        Tipo tipo;

        // Con esto creo un vector QUE TIENE EL MISMO ORDEN, y que contiene la puntuación
        for (auto a : movimientos_captura) {
            tipo = Tablero::tipo_pieza(a.second); // para sacar posición de la pieza que esté ahí
            // si lo pones con el puntero lo que priorizas es con qué pieza comes, lo he aprendido a las malas

            // Opción B por recomendación de Raúl, (posterior implementación, primero voy a intentar gestionar el orden, ver que funciona)
            // ------
            // int puntuaje=0; 
            // puntuaje += a.first->get_punto(); // función para sacar atributo privado (virtual pura)
            // puntos.push_back(puntuaje);
            // SUSTITUIRÍA EL switch

            switch (tipo) {
            case Tipo::PEON: puntos.push_back(1); break;
            case Tipo::CABALLO: puntos.push_back(3); break;
            case Tipo::ALFIL: puntos.push_back(2); break;
            case Tipo::TORRE: puntos.push_back(2); break;
            case Tipo::REINA: puntos.push_back(5); break;
            }
            // HABRÍA QUE METER PUNTOS EXTRA SI DA JAQUE
        }

        // Mecanismo de ordenamiento, no se me ocurría cómo usar el sort, vamos a usar selección directa
        // Está un poco me, pero quiero ver que funcione, ¡MEJORAR EN EL FUTURO!
        for (int i = 0; i < puntos.size() - 1; i++) {
            int max = i;
            for (int j = i + 1; j < puntos.size(); j++) {
                if (puntos[i] < puntos[j]) {
                    max = j;
                }
            }

            // USAMOS SWAP PARA INTERCAMBIAR EN AMBOS
            std::swap(puntos[i], puntos[max]);
            std::swap(movimientos_captura[i], movimientos_captura[max]);
        }
    }
    // aquí muere puntos

    // Elegir entre capturas o movimientos normales, dando preferencia a los movimientos de captura
    std::vector<std::pair<Pieza*, Posicion>>& movimientos =
        !movimientos_captura.empty() ? movimientos_captura : movimientos_validos;

    /*
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Para meterle aleatoriedad basándose en el tiempo
    int indice = std::rand() % movimientos.size(); // Para que esté dentro de nuestro rango usamos %
    */

    // HE COMENTADO EL RANDOM QUE SELECCIONA EL INDICE, escogemos el que tiene mayor puntuación, o sea el 0
    Pieza* pieza_elegida = movimientos[0].first; // AQUI IBA INDICE EN LOS CORCHETES [indice]
    Posicion destino = movimientos[0].second;

    if (mundo.TABLERO.hay_pieza(destino)) {
        mundo.TABLERO.comer_pieza(destino);
    }

    pieza_elegida->mueve(destino);
    std::cout << "Bot movió una pieza a (" << destino.Fila << ", " << destino.Columna << ")\n";

    mundo.cambiar_turno_bot();
}
