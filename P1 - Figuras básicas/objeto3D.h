#ifndef _OBJETO_3D_H
#define _OBJETO_3D_H

#ifdef _WIN32
#include <windows.h>
#endif
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include "ejes.h"
using namespace std;

class Objeto3D{

protected:
  vector<float> vertices;
  vector<int> caras;

public:
  Objeto3D();
  void dibujar(GLenum modo);
  void dibujarAjedrez();
};

#endif
