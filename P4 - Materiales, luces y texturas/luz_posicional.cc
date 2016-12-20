#include "luz_posicional.h"

LuzPosicional::LuzPosicional(float posicion[3]){
  this->posicion[0] = posicion[0];
  this->posicion[1] = posicion[1];
  this->posicion[2] = posicion[2];
}

void LuzPosicional::activar(){
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );
  const GLfloat posf[4] = { posicion[0], posicion[1], posicion[2], 1.0 } ; // (x,y,z,w)
  glLightfv( GL_LIGHT0, GL_POSITION, posf );
}

void LuzPosicional::desactivar(){
  glDisable(GL_LIGHT0);
}

vector<float> LuzPosicional::getPosicion(){
  return posicion;
}

void LuzPosicional::setPosicion(vector<float> pos){
  posicion[0] = pos[0];
  posicion[1] = pos[1];
  posicion[2] = pos[2];
}

void LuzPosicional::moverLuzEjeX(int x){
  posicion[0]+=x;
  posicion[1]=3000;
  posicion[2]=5000;

  const GLfloat posf[4] = { x, 3000, 5000, 1.0 } ; // (x,y,z,w)
  glLightfv( GL_LIGHT0, GL_POSITION, posf );
}
