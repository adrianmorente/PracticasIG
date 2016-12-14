#include "luz_direccional.h"

LuzDireccional::LuzDireccional(){
  const float ambiental[4] = {0.0, 0.0, 0.2, 0.0};  //color ambiental
  const float difuso[4]    = {0.5, 0.5, 1.0, 0.0};  //color difuso
  const float especular[4] = {1.0, 1.0, 1.0, 0.0};  //color especular
  glLightfv( GL_LIGHT1, GL_AMBIENT, ambiental);
  glLightfv( GL_LIGHT1, GL_DIFFUSE, difuso);
  glLightfv( GL_LIGHT1, GL_SPECULAR, especular);

  const float posicion[4] = {0.0, 0.0, 500.0, 0.0};
  glLightfv( GL_LIGHT1, GL_POSITION, posicion);
}

void LuzDireccional::activar(){
  const float eje[4] = {0.0, 0.0, 1.0, 0.0};
  glEnable(GL_LIGHT1);
  glMatrixMode( GL_MODELVIEW );
  glPushMatrix();
    glLoadIdentity();
    glRotatef(alpha, 0.0, 1.0, 0.0);
    glRotatef(beta, 1.0, 0.0, 0.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, eje);
  glPopMatrix();
}

void LuzDireccional::desactivar(){
  glDisable(GL_LIGHT1);
}
