#include "luz_direccional.h"
#include <cmath>

LuzDireccional::LuzDireccional(float x_pos, float y_pos, float z_pos){
  alpha = beta = 0;
  this->activar();
  float pos[4] = {x_pos, y_pos, z_pos, 0.0};
  glLightfv( GL_LIGHT1, GL_POSITION, pos);
  glLightfv( GL_LIGHT2, GL_POSITION, pos);
  glLightfv( GL_LIGHT3, GL_POSITION, pos);
}

void LuzDireccional::activar(){
  glEnable(GL_LIGHTING);
  GLfloat ambiental[] = { 0.2, 0.2, 0.2, 1.0 };
  GLfloat difuso[] = { 0.8, 0.0, 0.0, 1.0 };
  GLfloat especular[] = { 1.0, 0.0, 0.0, 1.0 };
  glLightfv(GL_LIGHT1, GL_AMBIENT, ambiental);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, difuso);
  glLightfv(GL_LIGHT1, GL_SPECULAR, especular);
  glRotatef( alpha, 0.0, 1.0, 0.0 ) ;
  glRotatef( beta, -1.0, 0.0, 0.0 ) ;
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
}

void LuzDireccional::desactivar(){
  glDisable(GL_LIGHT1);
  glDisable(GL_LIGHT2);
  glDisable(GL_LIGHT3);
}

void LuzDireccional::mover(float posicion){
  GLfloat posf[] = { posicion, 100.0, 0.0, 0.0 };
  glLightfv(GL_LIGHT1, GL_POSITION, posf);
  const GLfloat posf1[4] = {posicion-1000000,20,500,0};
	const GLfloat posf2[4] = {posicion,20,500,0};
	const GLfloat posf3[4] = {posicion+1000000,20,500,0};
	glLightfv(GL_LIGHT1, GL_POSITION, posf1);
	glLightfv(GL_LIGHT2, GL_POSITION, posf2);
	glLightfv(GL_LIGHT3, GL_POSITION, posf3);
}
