#include "camara.h"

Camara::Camara(){
  //nein
}

void Camara::girar(float x, float y){
  //recalcular el valor de los parámetros (VPN o lookAt)
}

void Camara::setEye(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ){
  this->eyeX = eyeX;
  this->eyeY = eyeY;
  this->eyeZ = eyeZ;
}

void Camara::setAt(GLdouble atX, GLdouble atY, GLdouble atZ){
  this->atX = atX;
  this->atY = atY;
  this->atZ = atZ;
}

void Camara::setUp(GLdouble upX, GLdouble upY, GLdouble upZ){
  this->upX = upX;
  this->upY = upY;
  this->upZ = upZ;
}

void Camara::setObservador(){

}
