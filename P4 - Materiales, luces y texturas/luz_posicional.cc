#include "luz_posicional.h"

LuzPosicional::LuzPosicional(){
}

void LuzPosicional::activar(){
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );
  const GLfloat posf[4] = { 0, 3000, 5000, 1.0 } ; // (x,y,z,w)
  glLightfv( GL_LIGHT0, GL_POSITION, posf );
}

void LuzPosicional::desactivar(){
  glDisable(GL_LIGHT0);
}
