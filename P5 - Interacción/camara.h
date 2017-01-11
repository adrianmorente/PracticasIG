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

  public:
    Camara();
    void girar(float x, float y);
    void setEye(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ);
    void setAt(GLdouble atX, GLdouble atY, GLdouble atZ);
    void setUp(GLdouble upX, GLdouble upY, GLdouble upZ);
    void setObservador();
};

#endif
