#pragma once
#include "freeglut.h"

struct Posicion
{
	int Fila, Columna;

	inline bool operator==(const Posicion& p2) const{ return (p2.Fila==Fila&& p2.Columna == Columna); }

	inline Posicion& operator+=(const Posicion& p2) {
		this->Fila += p2.Fila;
		this->Columna += p2.Columna;
		return *this;
	}

};
typedef unsigned char uchar;

//propuesta de primero asignar el color con un enum y luego pintarlo con brocha
enum Color { BLANCO, NEGRO };
/*struct Color
{
	
	uchar r{ 255 }, g{ 255 }, b{ 255 };
	void pon_color() {
		glColor3ub(r, g, b);

	}
};*/
