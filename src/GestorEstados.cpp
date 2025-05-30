#include "GestorEstados.h"
#include "PantallaInicio.h"
#include "MenuPrincipal.h"
#include "PantallaSeleccionTablero.h"
#include "PantallaSeleccionBot.h"
#include "PantallaSeleccionNivel.h"
#include "PantallaGameOver.h"
#include "PantallaCoronando.h"
#include "PantallaMedallas.h"
#include "PantallaPausa.h"



#include <iostream>

void GestorEstados::inicializa() {
    if (estado_actual == MENU) {
        gestor_pantallas.set_pantalla(new PantallaInicio(&gestor_pantallas));
        
        //Activamos musica menu
            ETSIDI::playMusica("sonidos/Menu Pokemon.mp3");
    }
    else if (estado_actual == JUGANDO) {
        //Desactivamos musica menu
        ETSIDI::stopMusica();

        //Activamos musica batalla
        ETSIDI::playMusica("sonidos/Musica batalla.mp3");

        switch (tipo_tablero_seleccionado) {
        case TipoTablero::BABY:
            mundo.inicializa_tablero_baby();
            break;
        case TipoTablero::GARDNER:
            mundo.inicializa_tablero_gardner();
            break;
        default:
            break;
        }
    }
    else if (estado_actual == VICTORIA_BLANCO) {
        gestor_pantallas.set_pantalla(new PantallaGameOver(&gestor_pantallas, &mundo, "BLANCAS"));
        

    }
    else if (estado_actual == VICTORIA_NEGRO) {
        gestor_pantallas.set_pantalla(new PantallaGameOver(&gestor_pantallas, &mundo, "NEGRAS"));
        
    }
    else if (estado_actual == TABLAS) {
        gestor_pantallas.set_pantalla(new PantallaGameOver(&gestor_pantallas, &mundo, "TABLAS"));

    }
    else if (estado_actual == CORONACION) {
        gestor_pantallas.set_pantalla(new PantallaCoronando(&gestor_pantallas));

    }
    else if (estado_actual == MEDALLAS) {
        gestor_pantallas.set_pantalla(new PantallaMedallas(&gestor_pantallas));
    }
    mundo.set_estado(this);//pasamos informacion del estado actual a mundo

}


void GestorEstados::dibuja() {
    switch (estado_actual) {
    case MENU:
        gestor_pantallas.dibuja();
        break;

    case JUGANDO:
        mundo.dibuja();
        break;

    case PAUSA:
        gestor_pantallas.dibuja();
        break;

    case VICTORIA_BLANCO:
        gestor_pantallas.dibuja();
        
        break;
        
    case VICTORIA_NEGRO:
        gestor_pantallas.dibuja();
       
        break;
    
    case TABLAS:
        gestor_pantallas.dibuja();

        break;

    case CORONACION:
        //para que se dibuje el tablero tmb
        mundo.dibuja();
        gestor_pantallas.dibuja();
        break;
    case MEDALLAS:
        gestor_pantallas.dibuja();

    default:
        break;


    }
}


void GestorEstados::mueve() {
    if (estado_actual == MENU) {
        gestor_pantallas.actualiza();

        Pantalla* pantalla = gestor_pantallas.get_pantalla();
        MenuPrincipal* menu = dynamic_cast<MenuPrincipal*>(pantalla);

        if (menu) {
            
            switch (menu->get_accion()) {
            case AccionMenu::NUEVA_PARTIDA:
                menu->reset_accion();
                // Aqu� cambiamos la pantalla al selector de tablero
                gestor_pantallas.set_pantalla(new PantallaSeleccionTablero(&gestor_pantallas));
                return; // cortamos aqu� para esperar la siguiente iteraci�n
            case AccionMenu::SALIR:
                menu->reset_accion();
                exit(0);
            default:
                break;
            }
        }

       //Pantalla Seleccion Tablero
        PantallaSeleccionTablero* selector = dynamic_cast<PantallaSeleccionTablero*>(pantalla);
        if (selector) {
            switch (selector->get_accion()) {
            case AccionTablero::TABLERO_BABY:
                selector->reset_accion();
                tipo_tablero_seleccionado = TipoTablero::BABY;

                //Mostrar pantalla de selector de modo del bot
                gestor_pantallas.set_pantalla(new PantallaSeleccionBot(&gestor_pantallas));               
                break;

            case AccionTablero::TABLERO_GARDNER:
                selector->reset_accion();
                tipo_tablero_seleccionado = TipoTablero::GARDNER;

                //Mostrar pantalla de selector de modo del bot
                gestor_pantallas.set_pantalla(new PantallaSeleccionBot(&gestor_pantallas));              
                break;

            case AccionTablero::VOLVER:
                selector->reset_accion();
                gestor_pantallas.set_pantalla(new MenuPrincipal(&gestor_pantallas));
                break;

            default:
                break;
            }
        }
        
        // Aqu� la logica para seleccionar el tipo de contringante
        //Pantalla Seleccion Bot
        PantallaSeleccionBot* selectorVS = dynamic_cast<PantallaSeleccionBot*>(pantalla);
        if (selectorVS) {
            switch (selectorVS->get_accion()) {
            case AccionBot::VS_BOT:
                selectorVS->reset_accion();
                tipo_VS_seleccionado = TipoVS::BOT;

                //Mostrar pantalla de selector de modo del nivel
                gestor_pantallas.set_pantalla(new PantallaSeleccionNivel(&gestor_pantallas));
                
                break;

            case AccionBot::VS_AMIGO:
                selectorVS->reset_accion();
                tipo_VS_seleccionado = TipoVS::AMIGO;
                estado_actual = JUGANDO;
                inicializa();
                break;

            case AccionBot::MEDALLAS:
                selectorVS->reset_accion();
                ETSIDI::playMusica("sonidos/Musica medallas.mp3");
                gestor_pantallas.set_pantalla(new PantallaMedallas(&gestor_pantallas));
                break;

            case AccionBot::VOLVER:
                selectorVS->reset_accion();
                gestor_pantallas.set_pantalla(new PantallaSeleccionTablero(&gestor_pantallas));
                break;
            default:
                break;
            }
        }

        // Aqu� la logica para la pantalla de medallas
        PantallaMedallas* selectormedallas = dynamic_cast<PantallaMedallas*>(pantalla);
        if (selectormedallas) {
            switch (selectormedallas->get_accion()) {
            case Medallas::VOLVER:
                selectormedallas->reset_accion();
                gestor_pantallas.set_pantalla(new PantallaSeleccionBot(&gestor_pantallas));
                ETSIDI::playMusica("sonidos/Menu Pokemon.mp3");
                break;
            }
        }
        // Aqu� la logica para volver a la selecci�n de nivel
        /*PantallaMedallas* selectorVS = dynamic_cast<PantallaMedallas*>(pantalla);
        if (selectorVS) {
            switch (selectorVS->get_accion()) {
            case AccionBot::VOLVER:
                selectorVS->reset_accion();
                gestor_pantallas.set_pantalla(new PantallaSeleccionTablero(&gestor_pantallas));
                break;
            default:
                break;
            }*/
        // Aqu� la logica para seleccionar el nivel del bot
        PantallaSeleccionNivel* selectorNivel = dynamic_cast<PantallaSeleccionNivel*>(pantalla);
        if (selectorNivel) {
            switch (selectorNivel->get_accion()) {
            case AccionNivel::Nivel1:
                selectorNivel->reset_accion();
                tipo_Nivel_seleccionado = NivelBot::NIVEL1;
                estado_actual = JUGANDO;
                inicializa();
                break;
            case AccionNivel::Nivel2:
                selectorNivel->reset_accion();
                tipo_Nivel_seleccionado = NivelBot::NIVEL2;
                estado_actual = JUGANDO;
                inicializa();
                break;
            case AccionNivel::Nivel3:
                selectorNivel->reset_accion();
                tipo_Nivel_seleccionado = NivelBot::NIVEL3;
                estado_actual = JUGANDO;
                inicializa();

            case AccionNivel::VOLVER:
                selectorNivel->reset_accion();
                gestor_pantallas.set_pantalla(new PantallaSeleccionBot(&gestor_pantallas));
                break;
            default:
                break;
            }
        }
    }

    if (estado_actual == JUGANDO) {
        mundo.mueve();
        // Turno del bot (negras)
        
        switch (tipo_VS_seleccionado)
        {
            
        case GestorEstados::TipoVS::BOT:
           
            if (mundo.get_turno() == Turno::NEGRO) { // Solo juega el bot si es su turno
                switch (tipo_Nivel_seleccionado)
                {
                case GestorEstados::NivelBot::NIVEL1:
                    
                    bot.juegaNivel1(mundo);

                    //AQU� FUNCIONAAAAAAAA
                    //POR ALG�N MOTIVO NO SE METE EN EL IF
                    //if (mundo.TABLERO.es_jaque_mate(NEGRO)) {
                        Bot::otorgar_medalla_amarilla();
                   // }

                    break;
                case GestorEstados::NivelBot::NIVEL2:
                    
                    bot.juegaNivel2(mundo);
                    Bot::otorgar_medalla_fuego();
                    break;
                case GestorEstados::NivelBot::NIVEL3:
                    
                    bot.juegaNivel3(mundo);
                    Bot::otorgar_medalla_azul();
                    break;
                default:
                    break;
                }
            }
            break;
        default:
            break;
        }
    }

    if (estado_actual==CORONACION){

        gestor_pantallas.actualiza();

        Pantalla* pantalla = gestor_pantallas.get_pantalla();
        PantallaCoronando* selectorCoronando = dynamic_cast<PantallaCoronando*>(pantalla);

        if (selectorCoronando) {
            switch (selectorCoronando->get_accion()) {
            case AccionCoronar::CABALLO:
                mundo.seleccionar_coronacion('c');
                break;
            case AccionCoronar::ALFIL:
                mundo.seleccionar_coronacion('a');
                break;
            case AccionCoronar::TORRE:
                mundo.seleccionar_coronacion('t');
                break;
            case AccionCoronar::DAMA:
                mundo.seleccionar_coronacion('d');
                break;
            default:
                return;
            }
            selectorCoronando->reset_accion();
            estado_actual = JUGANDO;
            gestor_pantallas.set_pantalla(nullptr);
        }
    }

    if (estado_actual == PAUSA) {
        gestor_pantallas.actualiza();
        //auto* pausa = dynamic_cast<PantallaPausa*>(gestor_pantallas.get_pantalla());
        Pantalla* pantalla = gestor_pantallas.get_pantalla();
        PantallaPausa* pausa = dynamic_cast<PantallaPausa*>(pantalla);
        if (pausa) {
            switch (pausa->get_accion()) {
            case AccionPausa::REANUDAR:
                pausa->reset_accion();
                estado_actual = JUGANDO;
                gestor_pantallas.set_pantalla(nullptr);
                break;

            case AccionPausa::RENDIRSE:
                pausa->reset_accion();
                //ir a gameover y luego ir a menu
                if (mundo.get_turno() == Turno::BLANCO) { estado_actual = VICTORIA_NEGRO; }
                else if (mundo.get_turno() == Turno::NEGRO) { estado_actual = VICTORIA_BLANCO; }

                //SE DEBERIA PODER VOVER DESDE VICTORIA AL MENU Y BORRAR LAS FICHAS
                //NO VA AQUI
                //mundo.TABLERO.eliminar_piezas();
                //reset tablero----
                inicializa();
                break;

            case AccionPausa::GUARDAR:
                pausa->reset_accion();
                std::cout << "[Guardar partida] a�n no implementado\n";
                break;

            case AccionPausa::SALIR_JUEGO:
                pausa->reset_accion();
                exit(0);
                break;

            default:
                break;
            }
        }
    }

    if (estado_actual == VICTORIA_BLANCO || estado_actual == VICTORIA_NEGRO || estado_actual == TABLAS) {
        gestor_pantallas.actualiza();

        Pantalla* pantalla = gestor_pantallas.get_pantalla();
        PantallaGameOver* selectorover = dynamic_cast<PantallaGameOver*>(pantalla);

        if (selectorover) {
            switch (selectorover->get_accion()) {
            case Game_over::VOLVER:
                selectorover->reset_accion();
                gestor_pantallas.set_pantalla(new MenuPrincipal(& gestor_pantallas));
                estado_actual = MENU;
                mundo.volver_a_por_defecto();
                mundo.TABLERO.eliminar_piezas();
                break;
            }
        }
    }

    if (estado_actual == MEDALLAS) {

        gestor_pantallas.actualiza();
        Pantalla* pantalla = gestor_pantallas.get_pantalla();
    }
}


void GestorEstados::tecla(unsigned char key) {
    if (estado_actual == MENU)
        gestor_pantallas.tecla(key);

    if (estado_actual == JUGANDO && key == 'p'|| estado_actual == JUGANDO && key == 'P') {
        estado_actual = PAUSA;
        gestor_pantallas.set_pantalla(new PantallaPausa(&gestor_pantallas, &mundo));
    }

    if (estado_actual==CORONACION){
        gestor_pantallas.tecla(key);

    }
}

void GestorEstados::raton(int button, int state, int x, int y) {
    if (estado_actual == MENU)
        gestor_pantallas.raton(button, state, x, y);
    if (estado_actual == JUGANDO)
        mundo.gestionar_click(button, state, x, y);
    if (estado_actual == PAUSA)
        gestor_pantallas.raton(button, state, x, y);
    if (estado_actual == VICTORIA_BLANCO || estado_actual == VICTORIA_NEGRO || estado_actual == TABLAS)
        gestor_pantallas.raton(button, state, x, y);
    /*
    if (estado_actual == CORONACION)
        gestor_pantallas.raton(button, state, x, y);
        */
}

void GestorEstados::mover_raton(int x, int y) {
    if (estado_actual == MENU)
        gestor_pantallas.mover_raton(x, y);
    if (estado_actual == PAUSA)
        gestor_pantallas.mover_raton(x, y);
    if (estado_actual == VICTORIA_BLANCO || estado_actual == VICTORIA_NEGRO || estado_actual == TABLAS)
        gestor_pantallas.mover_raton(x, y);
}

int GestorEstados::get_nivel_bot_como_int() const {//se necesita esta funcion ya que la enum es privada de gestorestado y necesitamos pasarle el nivel a mundo
    switch (tipo_Nivel_seleccionado) {
    case NivelBot::NIVEL1: return 1;
    case NivelBot::NIVEL2: return 2;
    case NivelBot::NIVEL3: return 3;
    default: return 1;
    }
}