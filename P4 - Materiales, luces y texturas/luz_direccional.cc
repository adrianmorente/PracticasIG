#include "luz_direccional.h"
#include <cmath>

<<<<<<< HEAD
LuzDireccional::LuzDireccional(float x_pos, float y_pos, float z_pos){
  alpha = beta = 0;
  this->activar();
  float pos[4] = {x_pos, y_pos, z_pos, 0.0};
  glLightfv( GL_LIGHT1, GL_POSITION, pos);
  glLightfv( GL_LIGHT2, GL_POSITION, pos);
  glLightfv( GL_LIGHT3, GL_POSITION, pos);
=======
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
>>>>>>> 3dda2c226d644775d7b36c943c8b7ed746b32d35
}

void LuzDireccional::activar(){
  glEnable(GL_LIGHTING);
<<<<<<< HEAD
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
=======
    GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glEnable(GL_LIGHT1);
>>>>>>> 3dda2c226d644775d7b36c943c8b7ed746b32d35
}

void LuzDireccional::desactivar(){
  glDisable(GL_LIGHT1);
<<<<<<< HEAD
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
=======
}

void LuzDireccional::moverLuzEjeX(int x){
  double alfa = M_PI/20.0;

  posicion[0] = posicion[0]*cos(alfa) + sin(alfa)*posicion[2];
  posicion[1] = posicion[1];
  posicion[2] = -sin(alfa)*posicion[0] + cos(alfa)*posicion[2];
>>>>>>> 3dda2c226d644775d7b36c943c8b7ed746b32d35
}
