#ifndef _ROBOT_H
#define _ROBOT_H

#include "objeto3D.h"
#include "objeto_revolucion.h"
#include "cubo.h"
#include "objetoPLY.h"
using namespace std;

class Robot{

  private:
    //vector con los vértices para generar mis figuras por revolución
    vector<float> perfil_cilindro = {0.0,-1.0,0.0, 1.0,-1.0,0.0,
                                      1.0,1.0,0.0, 0.0,1.0,0.0};
    vector<float> perfil_esfera = {0.0,0.0,0.0};
    Cubo *cubo;
    ObjetoRevolucion *hexagono;
    ObjetoRevolucion *cilindro;
    ObjetoRevolucion *esfera;
    ObjetoRevolucion *prisma;

  public:
    Robot();
    void dibujar();
    void dibujarPiernas();
    void dibujarTronco();
    void dibujarBrazos();
    void dibujarCabeza();
};

#endif
