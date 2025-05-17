#pragma once

class Pantalla {
public:
    virtual void dibuja();//funcion para dibujar pantallas
    virtual void actualiza();//funcion para actualizar pantallas
    virtual void tecla(unsigned char key);//funcin para usar teclas en las pantallas
    virtual void raton(int button, int state, int x, int y);//funcion para usar el raton en las pantallas
    virtual ~Pantalla() {}
};