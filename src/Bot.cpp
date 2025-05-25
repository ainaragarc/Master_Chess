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

    //FUNCION PARA ORDENAR LA CAPTURA EN ORDEN DE PUNTUACION
    if (!movimientos_captura.empty()) {
        vector <int> puntos;
        Tipo tipo;

        //con esto creo un vector QUE TIENE EL MISMO ORDEN, y que contiene la puntuacion
        for (auto a : movimientos_captura) {
            tipo = Tablero::tipo_pieza(a.second);//para sacar posicion de la pieza que este ahi
            //si lo pones con el puntero lo que priorizas es con que pieza comes, lo he aprendido a las malas

            //opcion b por recomendacion de raul, (posterior implementacion, primero voy a intentar gestionar el orden, ver que funciona)
            // ------
            //int puntuaje=0; 
            //puntuaje += a.first->get_punto(); //funcion para sacar atributo privado (virtual pura)
            //puntos.push_back(puntuaje);
            //SUSTITUIRIA EL switch

            switch (tipo) {
            case Tipo::PEON: puntos.push_back(1); break;
            case Tipo::CABALLO: puntos.push_back(3); break;
            case Tipo::ALFIL: puntos.push_back(2); break;
            case Tipo::TORRE: puntos.push_back(2); break;
            case Tipo::REINA: puntos.push_back(5); break;
            }
            //HABRIA QUE METER PUNTOS EXTRA SI DA JAQUE
        }

        //mecanismo de ordenamiento, no se me ocurria como usar el short, vamos usar seleccion directa
        //esta un poco me, pero quiero ver que funcione, MEJORAR EN EL FUTURO!!!!!
		
		for (int i = 0; i < puntos.size() - 1; i++) {
            int max=i;
			for (int j = i + 1; j < puntos.size(); j++) {
				if (puntos[i] < puntos[j]) { 
                    max = j;
				}
			}

        //USAMOS SWAP PARA INTERCAMBIAR EN AMBOS
        std::swap(puntos[i], puntos[max]);
        std::swap(movimientos_captura[i], movimientos_captura[max]);

		}
		for (auto a : puntos) {
			std::cout << a << " ";
		}
        std::cout << "Puntuacion: " << puntos[0] << endl;
        for (auto a : movimientos_captura) {
            char c;
			if (a.first->get_tipo() == Tipo::CABALLO)c = 'c';
			else if (a.first->get_tipo() == Tipo::ALFIL)c = 'a';
			else if (a.first->get_tipo() == Tipo::TORRE)c = 't';
			else if (a.first->get_tipo() == Tipo::REINA)c = 'd';
			else c = 'p'; //peon
            std::cout <<c << "-";
        }

    }
    //aqui muere puntos

    // Elegir entre capturas o movimientos normales, dando preferencia a los movimientos de captura
    std::vector<std::pair<Pieza*, Posicion>>& movimientos =
        !movimientos_captura.empty() ? movimientos_captura : movimientos_validos;

    /*
    std::srand(static_cast<unsigned>(std::time(nullptr)));//Para meterle aleatoriedad basándose en el tiempo
    int indice = std::rand() % movimientos.size();//Para que esté dentro de nuestro rango usamos %
    */

    //HE COMENTADO EL RANDOM QUE SELECCIONA EL INCIDE, escogemos el que tiene mayor puntuacion, osea el 0
    Pieza* pieza_elegida = movimientos[0].first;  //AQUI IBA INDICE EN LOS CORCHETES [indice]
    Posicion destino = movimientos[0].second;
    

    if (mundo.TABLERO.hay_pieza(destino)) {
        mundo.TABLERO.comer_pieza(destino);
    }

    pieza_elegida->mueve(destino);
    std::cout << "Bot movió una pieza a (" << destino.Fila << ", " << destino.Columna << ")\n";

    mundo.cambiar_turno_bot();
}