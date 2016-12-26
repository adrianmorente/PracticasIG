#ifndef _LUZ_H
#define _LUZ_H

#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class Luz{

  protected:
<<<<<<< HEAD
    vector<float> ambiental, difuso, especular;
=======
    vector<float> color;
>>>>>>> 3dda2c226d644775d7b36c943c8b7ed746b32d35
    vector<float> posicion;

  public:
    Luz();
    void activar();
    void desactivar();
    vector<float> getPosicion();
    void setPosicion(vector<float> pos);
<<<<<<< HEAD
    void setColorRojo();
    void setColorVerde();
    void setColorAzul();
    void moverLuzEjeX(int x);
    void moverLuzEjeY(int y);
    void moverLuzEjeZ(int z);
=======
>>>>>>> 3dda2c226d644775d7b36c943c8b7ed746b32d35

};

#endif
