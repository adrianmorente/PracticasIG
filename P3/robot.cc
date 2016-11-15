#include "objeto_revolucion.h"
#include "robot.h"

Robot::Robot(){
  cubo = new Cubo;
  hexagono = new ObjetoRevolucion(perfil_cilindro, 6);
  cilindro = new ObjetoRevolucion(perfil_cilindro, 20);
  esfera = new ObjetoRevolucion(perfil_esfera, 20);
  prisma = new ObjetoRevolucion(perfil_cilindro, 3);
}

//este método controla el color con el que dibujamos cada parte del robot
void Robot::dibujar(){
  dibujarPiernas();
  dibujarTronco();
  dibujarBrazos();
  dibujarCabeza();
}

void Robot::dibujarPiernas(){
  //cada pierna es un cilindro con una esfera al principio y un prisma triangular
  // "tumbado" al final
  glPushMatrix();
  //   cilindro->dibujar('A');
  // glPopMatrix();
  // glPushMatrix();
  //   glScalef(1,1,1);
  //   glTranslatef(0,30,0);
  //   cilindro->dibujar('F');
  glPopMatrix();
}

void Robot::dibujarTronco(){
  //el tronco constará de un hexágono del que sale un pequeño cilindro a modo de
  // cuello
  glPushMatrix();
    glScalef(1.0,1.0,0.5);
    hexagono->dibujar('A');
  glPopMatrix();
  glPushMatrix();
    glScalef(0.1,0.1,0.1);
    glTranslatef(0,hexagono->getMaxY(),0);
    cilindro->dibujar('A');
  glPopMatrix();
}

void Robot::dibujarBrazos(){
  //cada brazo consta de un cilindro pequeño que sale del tronco, una esfera a
  // modo de hombro, otro cilindro más largo como brazo, y otra esfera al final
  // que será la mano
}

void Robot::dibujarCabeza(){
  //la cabeza será un simple cubo, con un toroide encima algo separado a modo de
  // aureola

}
