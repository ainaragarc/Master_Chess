#include "Bot.h"

void Bot::juega(Mundo& mundo) {
    //inicializamos variable para trabajar más cómodo con las piezas negras
    const std::vector<Pieza*>& negras = mundo.TABLERO.get_piezas_N();
    //En el futuro las piezas del bot podemos hacerlas aleatorias

    std::vector<Pieza*> piezas_validas;
    std::vector<Posicion> destinos_validos;

    // Buscar todos los movimientos válidos (2º bucle for) de todas las piezas negras (1º bucle for)
    for (Pieza* pieza : negras) {
        for (const Posicion& destino : pieza->posiciones_posibles()) {
            piezas_validas.push_back(pieza);//guardo las piezas del bot en otro vector
            destinos_validos.push_back(destino);//guardo posiciones posibles en otro vector
        }
    }

    if (piezas_validas.empty()) {
        std::cout << "El bot no tiene movimientos disponibles\n";
        mundo.cambiar_turno_bot();// Si no puede mover, cambia el turno igualmente
        return;//Para salir de la función si no hay movimientos posibles (y cambiar de turno)
    }

    // Elegir uno aleatorio
    std::srand(static_cast<unsigned>(std::time(nullptr)));//Para meterle aleatoriedad basándose en el tiempo
    int indice = std::rand() % piezas_validas.size();//Para que esté dentro de nuestro rango usamos %

    Pieza* pieza_elegida = piezas_validas[indice];//Se elige la pieza a mover
    Posicion destino = destinos_validos[indice];//Se define su destino dentro de los válidos

    pieza_elegida->mueve(destino);//Ejecutamos el movimiento

    std::cout << "Bot movió una pieza a (" << destino.Fila << ", " << destino.Columna << ")\n";

    if (mundo.TABLERO.hay_pieza(destino)) {
        mundo.TABLERO.comer_pieza(destino);
    }
    mundo.cambiar_turno_bot();
}