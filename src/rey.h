#pragma once
#include "pieza.h"

class Rey : public Pieza {
	bool en_jaque = false;

public:
	vector<Posicion> posiciones_posibles_conrey() override;

	Rey(Color equipo, Posicion pos) {//constructor parametrizado
		cantidad = 1;
		color = equipo;
		posicion = pos;
		tipo = Tipo::REY;
		if (color == BLANCO) {
			foto_pieza = "imagenes/w_king_1x_ns.png";
		}
		else {
			foto_pieza = "imagenes/b_king_1x.png";
		}

	}

	bool esta_en_jaque() const { return en_jaque; }
	void set_jaque(bool valor) { en_jaque = valor; }
	bool casilla_me_da_jaque(Posicion & pos);

};