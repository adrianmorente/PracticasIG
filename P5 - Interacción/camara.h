#ifndef _CAMARA_H
#define _CAMARA_H

#include <iostream>
#include <vector>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

struct Posicion{
  GLdouble x, y, z;
};

class Camara{

  private:
    int avanceAlzado, giroAlzado;
    int avanceIzda, giroIzda;
    int avanceDcha, giroDcha;
    int avancePlanta, giroPlanta;

    Posicion eye, at, up;
    Posicion angulo_euler;

  public:
    Camara();
    void setPosicion(float x, float y, float z);
    void setEye(float uno, float dos, float tres);
    void setAt(float uno, float dos, float tres);
    void setUp(float uno, float dos, float tres);

    void setVistaAlzado();
    void setVistaPerfilDerecho();
    void setVistaPerfilIzquierdo();
    void setVistaPlanta();
    void resetear(int camara);

    void avanzar(int camara, int pos);
    void girar(int camara, int pos);

    void setObservador();
    void imprimirPosicion();
};

#endif
