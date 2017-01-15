#ifndef _CAMARA_H
#define _CAMARA_H

#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class Camara{

  private:
    GLdouble eyeX, eyeY, eyeZ;
    GLdouble atX, atY, atZ;
    GLdouble upX, upY, upZ;

    int avanceAlzado, giroAlzado;
    int avanceIzda, giroIzda;
    int avanceDcha, giroDcha;
    int avancePlanta, giroPlanta;

  public:
    Camara();

    void setVistaAlzado();
    void setVistaPlanta();
    void setVistaPerfilDerecho();
    void setVistaPerfilIzquierdo();

    void avanzar(int camara, int pos);
    void girar(int camara, int pos);
    void girar(int camara, float x, float y);
    void resetear(int camara);

    void setEye(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ);
    void setAt(GLdouble atX, GLdouble atY, GLdouble atZ);
    void setUp(GLdouble upX, GLdouble upY, GLdouble upZ);
    void setObservador();
};

#endif
