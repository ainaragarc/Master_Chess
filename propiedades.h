#pragma once
#include "freeglut.h"
struct Posicion
{
	int X, Y;
};
typedef unsigned char uchar;
struct Color
{
	uchar r{ 255 }, g{ 255 }, b{ 255 };
	void pon_color() {
		glColor3ub(r, g, b);
	}
};
