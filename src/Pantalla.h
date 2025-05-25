#pragma once
#include <string>

struct Coordenada {
    float x;
    float y;
};

struct ColorTextos {
    float r, g, b;

    ColorTextos(float r, float g, float b) :r(r), g(g), b(b) {} // constructor de color por si acaso
};

class Pantalla {
public:
    virtual void dibuja();//funcion para dibujar pantallas
    virtual void actualiza();//funcion para actualizar pantallas
    virtual void tecla(unsigned char key);//funcin para usar teclas en las pantallas
    virtual void raton(int button, int state, int x, int y);//funcion para usar el raton en las pantallas
    virtual ~Pantalla() {}
};

//creamos clase para crear botones con facilidad
class Boton {
private:
    std::string texto;
    Coordenada desde, hasta; //coordenadas de las esquinas del botón

public:
    //constructor de botones
    Boton(const std::string& texto, Coordenada desde, Coordenada hasta)
        : texto(texto), desde(desde), hasta(hasta) {}

    void dibujar() const; //funcion para dibujar que llama a BrochaPantallas
    bool clic_en(float x, float y) const; //funcion que comprueba si el clic está dentro del boton

    const std::string& get_texto() const { return texto; }
};

//struct utilizada por funciones en brochapantallas
