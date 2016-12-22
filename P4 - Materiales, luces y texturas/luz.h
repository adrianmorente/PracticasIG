#ifndef _LUZ_H
#define _LUZ_H

#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class Luz{

  protected:
    vector<float> ambiental, difuso, especular;
    vector<float> posicion;

  public:
    Luz();
    void activar();
    void desactivar();
    vector<float> getPosicion();
    void setPosicion(vector<float> pos);
    void setColorRojo();
    void setColorVerde();
    void setColorAzul();
    void moverLuzEjeX(int x);
    void moverLuzEjeY(int y);
    void moverLuzEjeZ(int z);

};

#endif
