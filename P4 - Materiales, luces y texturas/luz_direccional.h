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
<<<<<<< HEAD
    LuzDireccional(float x_pos, float y_pos, float z_pos);
    void activar();
    void desactivar();
    void mover(float posicion);
=======
    LuzDireccional(float posicion[3]);
    void activar();
    void desactivar();
    void moverLuzEjeX(int x);
>>>>>>> 3dda2c226d644775d7b36c943c8b7ed746b32d35

};

#endif
