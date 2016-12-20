#ifndef _LUZ_H
#define _LUZ_H

#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class Luz{

  protected:
    vector<float> color;
    vector<float> posicion;

  public:
    Luz();
    void activar();
    void desactivar();
    vector<float> getPosicion();
    void setPosicion(vector<float> pos);

};

#endif
