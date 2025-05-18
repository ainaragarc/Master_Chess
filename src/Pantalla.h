#pragma once
#include <string>

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
    float x1, y1, x2, y2; //coordenadas de las esquinas del botón

public:
    //constructor de botones
    Boton(const std::string& texto, float x1, float y1, float x2, float y2)
        : texto(texto), x1(x1), y1(y1), x2(x2), y2(y2) {
    }

    void dibujar() const; //funcion para dibujar que llama a BrochaPantallas
    bool clic_en(float x, float y) const;   //funcion que comprueba si el clic está dentro del boton

    const std::string& get_texto() const { return texto; }
};

//struct utilizada por funciones en brochapantallas
struct Coordenada {
    float x;
    float y;
};