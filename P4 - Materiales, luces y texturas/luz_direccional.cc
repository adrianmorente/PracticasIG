#include "luz_direccional.h"
#include <cmath>

LuzDireccional::LuzDireccional(float posicion[3]){
  float ambiental[4] = {0.0, 0.0, 0.2, 0.0};  //color ambiental
  float difuso[4]    = {0.5, 0.5, 1.0, 0.0};  //color difuso
  float especular[4] = {1.0, 1.0, 1.0, 0.0};  //color especular
  glLightfv( GL_LIGHT1, GL_AMBIENT, ambiental);
  glLightfv( GL_LIGHT1, GL_DIFFUSE, difuso);
  glLightfv( GL_LIGHT1, GL_SPECULAR, especular);
  glEnable(GL_LIGHT1);
  float pos[4] = {0.0, 300.0, 0.0, 0.0};
  glLightfv( GL_LIGHT1, GL_SPOT_DIRECTION, pos);
}

void LuzDireccional::activar(){
  glEnable(GL_LIGHTING);
    GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glEnable(GL_LIGHT1);
}

void LuzDireccional::desactivar(){
  glDisable(GL_LIGHT1);
}

void LuzDireccional::moverLuzEjeX(int x){
  double alfa = M_PI/20.0;

  posicion[0] = posicion[0]*cos(alfa) + sin(alfa)*posicion[2];
  posicion[1] = posicion[1];
  posicion[2] = -sin(alfa)*posicion[0] + cos(alfa)*posicion[2];
}
