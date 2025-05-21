#include "Bot.h"

void Bot::juega(Mundo& mundo) {
    //inicializamos variable para trabajar m�s c�modo con las piezas negras
    const std::vector<Pieza*>& negras = mundo.TABLERO.get_piezas_N();
    //En el futuro las piezas del bot podemos hacerlas aleatorias

    std::vector<Pieza*> piezas_validas;
    std::vector<Posicion> destinos_validos;

    // Buscar todos los movimientos v�lidos (2� bucle for) de todas las piezas negras (1� bucle for)
    for (Pieza* pieza : negras) {
        for (const Posicion& destino : pieza->posiciones_posibles()) {
            piezas_validas.push_back(pieza);//guardo las piezas del bot en otro vector
            destinos_validos.push_back(destino);//guardo posiciones posibles en otro vector
        }
    }

    if (piezas_validas.empty()) {
        std::cout << "El bot no tiene movimientos disponibles\n";
        mundo.cambiar_turno_bot();// Si no puede mover, cambia el turno igualmente
        return;//Para salir de la funci�n si no hay movimientos posibles (y cambiar de turno)
    }

    // Elegir uno aleatorio
    std::srand(static_cast<unsigned>(std::time(nullptr)));//Para meterle aleatoriedad bas�ndose en el tiempo
    int indice = std::rand() % piezas_validas.size();//Para que est� dentro de nuestro rango usamos %

    Pieza* pieza_elegida = piezas_validas[indice];//Se elige la pieza a mover
    Posicion destino = destinos_validos[indice];//Se define su destino dentro de los v�lidos

    pieza_elegida->mueve(destino);//Ejecutamos el movimiento

    std::cout << "Bot movi� una pieza a (" << destino.Fila << ", " << destino.Columna << ")\n";

    if (mundo.TABLERO.hay_pieza(destino)) {
        mundo.TABLERO.comer_pieza(destino);
    }
    mundo.cambiar_turno_bot();
}