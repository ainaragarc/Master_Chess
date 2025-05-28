#include "PantallaCoronando.h"
#include "BrochaPantallas.h"

PantallaCoronando::PantallaCoronando(GestorPantallas* gestor) : gestor(gestor) {
    /*

    botones.push_back({ "CABALLO", Coordenada{-0.5f,  0.1f}, Coordenada{0.3f,  0.25f } });
    botones.push_back({ "ALFIL",Coordenada{-0.5f, -0.2f}, Coordenada{0.3f, -0.05f } });
    botones.push_back({ "TORRE", Coordenada{-0.5f, -0.3f}, Coordenada{0.3f, -0.35f} });
    botones.push_back({ "DAMA", Coordenada{-0.5f, -0.4f}, Coordenada{0.3f, -0.65f} });

    */
}

void PantallaCoronando::tecla(unsigned char key) {
    switch (key) {
    case 'c':
    case 'C':
        accion_pendiente = AccionCoronar::CABALLO;
        break;
    case 'a':
    case 'A':
        accion_pendiente = AccionCoronar::ALFIL;
        break;
    case 't':
    case 'T':
        accion_pendiente = AccionCoronar::TORRE;
        break;
    case 'd':
    case 'D':
        accion_pendiente = AccionCoronar::DAMA;
        break;
    default:
        break;
    }

}

void PantallaCoronando::dibuja() {
	BrochaPantallas::insertarimagen("imagenes/coronacion.png", 2.0, 2.0, 2.0, 2.0);
    /*
    for (auto& b : botones)
        b.dibujar();
    */
}

/*
void PantallaCoronando::raton(int button, int state, int x, int y) {
    if (!BrochaPantallas::es_clic_izquierdo(button, state)) return;

    Coordenada click = BrochaPantallas::convertir_click_a_opengl(x, y);

    if (botones[0].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::CABALLO;
    }
    else if (botones[1].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::ALFIL;
    }
    else if (botones[2].clic_en(click.x, click.y)) {
        accion_pendiente = AccionCoronar::TORRE;
    }
    else if (botones[3].clic_en(click.x, click.y)) {
       accion_pendiente = AccionCoronar::DAMA;
    }
    
}

*/