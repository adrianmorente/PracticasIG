#include "camara.h"

Camara::Camara(){
  avanceAlzado = avanceDcha = avancePlanta = 10;
  avanceIzda = -10;
  giroAlzado = giroIzda = giroDcha = giroPlanta = 0;
}

void Camara::setVistaAlzado(){
  this->setEye(giroAlzado,0,avanceAlzado);
  this->setAt(0,0,0);
  this->setUp(0,1,0);
}

void Camara::setVistaPlanta(){
  this->setEye(giroPlanta,avancePlanta,0);
  this->setAt(0,0,0);
  this->setUp(0,0,-1);
}

void Camara::setVistaPerfilDerecho(){
  this->setEye(avanceDcha,0,giroDcha);
  this->setAt(0,0,0);
  this->setUp(0,1,0);
}

void Camara::setVistaPerfilIzquierdo(){
  this->setEye(avanceIzda,0,giroIzda);
  this->setAt(0,0,0);
  this->setUp(0,1,0);
}

void Camara::avanzar(int camara, int pos){
  switch (camara) {
    case 0:
      avanceAlzado -= pos;
      break;
    case 1:
      avanceDcha += pos;
      break;
    case 2:
      avanceIzda -= pos;
      break;
    case 3:
      avancePlanta += pos;
      break;
  }
}

void Camara::girar(int camara, int pos){
  switch (camara) {
    case 0:
      giroAlzado += pos;
      break;
    case 1:
      giroDcha -= pos;
      break;
    case 2:
      giroIzda += pos;
      break;
    case 3:
      giroPlanta += pos;
  }
}

void Camara::girar(int camara, float x, float y){

}

void Camara::resetear(int camara){
  switch(camara){
    case 0:
      avanceAlzado = 10;
      giroAlzado = 0;
      break;
    case 1:
      avanceDcha = 10;
      giroDcha = 0;
      break;
    case 2:
      avanceIzda = -10;
      giroIzda = 0;
      break;
    case 3:
      avancePlanta = 10;
      giroPlanta = 0;
  }
}

void Camara::setEye(GLdouble X, GLdouble Y, GLdouble Z){
  this->eyeX = X;
  this->eyeY = Y;
  this->eyeZ = Z;
}

void Camara::setAt(GLdouble X, GLdouble Y, GLdouble Z){
  this->atX = X;
  this->atY = Y;
  this->atZ = Z;
}

void Camara::setUp(GLdouble X, GLdouble Y, GLdouble Z){
  this->upX = X;
  this->upY = Y;
  this->upZ = Z;
}

void Camara::setObservador(){
  gluLookAt(eyeX,eyeY,eyeZ, atX,atY,atZ, upX,upY,upZ);
}
