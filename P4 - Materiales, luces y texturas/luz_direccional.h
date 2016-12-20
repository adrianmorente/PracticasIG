#ifndef _LUZ_DIRECCIONAL_H
#define _LUZ_DIRECCIONAL_H

#include "luz.h"
#include <vector>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class LuzDireccional : public Luz{

  private:
    float alpha, beta;

  public:
    LuzDireccional(float posicion[3]);
    void activar();
    void desactivar();
    void moverLuzEjeX(int x);

};

#endif
