#include "luz.h"

Luz::Luz(){
  this->color = {1.0, 1.0, 1.0};
  this->posicion.assign(3, 0.0);
}

vector<float> Luz::getPosicion(){
  return posicion;
}

void Luz::setPosicion(vector<float> pos){
  posicion[0] = pos[0];
  posicion[1] = pos[1];
  posicion[2] = pos[2];
}

void Luz::setColorRojo(){
  glEnable(GL_LIGHTING);
  GLfloat amb[] = { 0.5, 0.0, 0.0, 1.0 };
  GLfloat dif[] = { 1.0, 0.0, 0.0, 0.0 };
  GLfloat spec[] = { 1.0, 1.0, 1.0, 1.0 };
  const GLfloat dirf[4] = { -5000, 10, 100, 0.0 };

  glLightfv( GL_LIGHT1, GL_POSITION, dirf );
  glLightfv(GL_LIGHT1, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, dif);
  glLightfv(GL_LIGHT1, GL_SPECULAR, spec);
  glEnable(GL_LIGHT1);
}

void Luz::setColorVerde(){
  glEnable(GL_LIGHTING);
  GLfloat amb[] = { 0.0, 0.5, 0.0, 1.0 };
  GLfloat dif[] = { 0.0, 1.0, 0.0, 0.0 };
  GLfloat spec[] = { 1.0, 1.0, 1.0, 1.0 };
  const GLfloat dirf[4] = { 10000, 10, 100, 0.0 };

  glLightfv( GL_LIGHT2, GL_POSITION, dirf );
  glLightfv(GL_LIGHT2, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, dif);
  glLightfv(GL_LIGHT2, GL_SPECULAR, spec);
  glEnable(GL_LIGHT2);
}

void Luz::setColorAzul(){
  glEnable(GL_LIGHTING);
  GLfloat amb[] = { 0.0, 0.0, 0.5, 1.0 };
  GLfloat dif[] = { 0.0, 0.0, 1.0, 0.0 };
  GLfloat spec[] = { 1.0, 1.0, 1.0, 1.0 };
  const GLfloat dirf[4] = { -0, 10, 100, 0.0 };

  glLightfv( GL_LIGHT3, GL_POSITION, dirf );
  glLightfv(GL_LIGHT3, GL_AMBIENT, amb);
  glLightfv(GL_LIGHT3, GL_DIFFUSE, dif);
  glLightfv(GL_LIGHT3, GL_SPECULAR, spec);
  glEnable(GL_LIGHT3);
}

void Luz::moverLuzEjeX(int x){
  posicion[0] += x;
  GLfloat position[4] = {posicion[0], posicion[1], posicion[2], 0.0};
  glLightfv(GL_LIGHT1, GL_POSITION, position);
}

void Luz::moverLuzEjeY(int y){
  posicion[1] += y;
  GLfloat position[4] = {posicion[0], posicion[1], 10.0, 0.0};
  glLightfv(GL_LIGHT1, GL_POSITION, position);
}

void Luz::moverLuzEjeZ(int z){
  posicion[2] += z;
  GLfloat position[4] = {posicion[0], posicion[1], posicion[2], 0.0};
  glLightfv(GL_LIGHT1, GL_POSITION, position);
}
