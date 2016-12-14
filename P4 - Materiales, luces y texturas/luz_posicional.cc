#include "luz_posicional.h"

LuzPosicional::LuzPosicional(){
  const float ambiental[4] = {0.1, 0.1, 0.1, 1.0};  //color ambiental
  const float difuso[4]    = {0.0, 0.8, 1.0, 1.0};  //color difuso
  const float especular[4] = {1.0, 1.0, 1.0, 1.0};  //color especular
  glLightfv( GL_LIGHT0, GL_AMBIENT, ambiental);
  glLightfv( GL_LIGHT0, GL_DIFFUSE, difuso);
  glLightfv( GL_LIGHT0, GL_SPECULAR, especular);

  const float posicion[4] = {0.0, 0.0, 500.0, 1.0};
  glLightfv( GL_LIGHT0, GL_POSITION, posicion);
}

void LuzPosicional::activar(){
  glEnable(GL_LIGHT0);
}

void LuzPosicional::desactivar(){
  glDisable(GL_LIGHT0);
}
