#ifndef _LUZ_POSICIONAL_H
#define _LUZ_POSICIONAL_H

#include "luz.h"
#include <vector>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class LuzPosicional : public Luz{

  private:
    vector<float> posicion = {0.0, 0.0, 0.0};

  public:
    LuzPosicional(float posicion[3]);
    void activar();
    void desactivar();
    vector<float> getPosicion();
    void setPosicion(vector<float> pos);
    void moverLuzEjeX(int x);

};

#endif
