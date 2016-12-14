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
#include <math.h>
#include "ejes.h"
using namespace std;

struct Punto{
  float x, y, z;
};

class Objeto3D{

  protected:
    vector<float> vertices;
    vector<int> caras;
    vector<int> normales_caras;
    vector<int> normales_vertices;
    Punto minimo;     //
    Punto maximo;     // atributos BoundingBox

  public:
    void calcularNormalesCaras();
    void calcularNormalesVertices();
    void setBoundingBox();
    Punto getCentro();
    float getSizeBoundingBox();
    float getMaxX();
    float getMaxY();
    float getMaxZ();
    float modulo(Punto p);
    void escalar();
    void trasladar();
    void rotar(float grados);

    void dibujar(unsigned char modo);
    void dibujarAjedrez();
    void dibujarConLineas();
};

#endif
