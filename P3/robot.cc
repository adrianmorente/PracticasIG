#include "objeto_revolucion.h"
#include "robot.h"

Robot::Robot(){
  cubo = new Cubo;
  hexagono = new ObjetoRevolucion(perfil_cilindro, 6);
  cilindro = new ObjetoRevolucion(perfil_cilindro, 20);
  generarEsfera();
  esfera = new ObjetoRevolucion(perfil_esfera, 20);
  prisma = new ObjetoRevolucion(perfil_cilindro, 3);
}

//este método controla el color con el que dibujamos cada parte del robot
void Robot::dibujar(){
  // dibujarPiernas();
  // dibujarTronco();
  dibujarBrazos();
  // dibujarCabeza();
}

void Robot::dibujarPiernas(){
  //cada pierna es un cilindro con una esfera al principio y un prisma triangular
  // "tumbado" al final
  glPushMatrix();
    cilindro->dibujar('A');
  glPopMatrix();
  glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,30,0);
    cilindro->dibujar('F');
  glPopMatrix();
}

void Robot::dibujarTronco(){
  //el tronco constará de un hexágono del que sale un pequeño cilindro a modo de
  // cuello
  glPushMatrix();
    glScalef(20.0,20.0,12.0);
    hexagono->dibujar('A');
  glPopMatrix();
  glPushMatrix();
    glScalef(5.0,5.0,5.0);
    glTranslatef(0.0,20.0,0.0);
    cilindro->dibujar('A');
  glPopMatrix();
}

void Robot::dibujarBrazos(){
  //cada brazo consta de un cilindro pequeño que sale del tronco, una esfera a
  // modo de hombro, otro cilindro más largo como brazo, y otra esfera al final
  // que será la mano
  glPushMatrix();
    glScalef(50.0,50.0,50.0);
    esfera->dibujar('A');
  glPopMatrix();
}

void Robot::dibujarCabeza(){
  //la cabeza será un simple cubo, con un toroide encima algo separado a modo de
  // aureola
  glPushMatrix();
    glScalef(20.0,20.0,20.0);
    glTranslatef(0.0,25.0,0.0);
    cubo->dibujar('A');
  glPopMatrix();
}

void Robot::generarEsfera(){
  float alpha = M_PI/2, suma = 2*M_PI/60, radio = 1.0;
  for(int i=0; i<=30; i++){
    perfil_esfera.push_back(-radio*cos(alpha));
    perfil_esfera.push_back(-radio*sin(alpha));
    perfil_esfera.push_back(0.0);
    alpha += suma;
  }
}
