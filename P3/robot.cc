#include "objeto_revolucion.h"
#include "robot.h"

Robot::Robot(){
  cubo = new Cubo;
  prisma_hex = new ObjetoRevolucion(perfil_cilindro, 6);
  cilindro = new ObjetoRevolucion(perfil_cilindro, 15);
  generarPerfilEsfera();
  esfera = new ObjetoRevolucion(perfil_esfera, 20);
  prisma = new ObjetoRevolucion(perfil_cilindro, 3);
}

//este método controla el color con el que dibujamos cada parte del robot
void Robot::dibujar(unsigned char modo){
  dibujarCuerpo(modo);
  dibujarCabeza(modo);
  dibujarAureola(modo);
}

void Robot::dibujarPiernas(unsigned char modo){
  //cada pierna es un cilindro con una esfera al principio y un prisma triangular
  // "tumbado" al final
  glPushMatrix();
    cilindro->dibujar(modo);
  glPopMatrix();
  glPushMatrix();
    glScalef(1,1,1);
    glTranslatef(0,30,0);
    cilindro->dibujar(modo);
  glPopMatrix();
}

void Robot::dibujarCuerpo(unsigned char modo){
  //el tronco constará de un hexágono del que sale un pequeño cilindro a modo de
  // cuello
  glPushMatrix();
    glScalef(100.0,100.0,50.0);
    prisma_hex->dibujar(modo);
  glPopMatrix();
  glPushMatrix();
    glScalef(15.0,15.0,15.0);
    glTranslatef(0.0,3.80,0.0);
    cilindro->dibujar(modo);
  glPopMatrix();
  dibujarBrazos(modo);
}

void Robot::dibujarBrazos(unsigned char modo){
  //cada brazo consta de un cilindro pequeño que sale del tronco, una esfera a
  // modo de hombro, otro cilindro más largo como brazo, y otra esfera al final
  // que será la mano
  glScalef(15.0,100.0,15.0);
  glPushMatrix();
    glTranslatef(4.6,0.0,0.0);
    cilindro->dibujar(modo);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(-4.6,0.0,0.0);
    cilindro->dibujar(modo);
  glPopMatrix();
}

void Robot::dibujarCabeza(unsigned char modo){
  //la cabeza será un simple cubo, con un toroide encima algo separado a modo de
  // aureola
  glPushMatrix();
    glScalef(20.0,20.0,20.0);
    glTranslatef(0.0,25.0,0.0);
    cubo->dibujar(modo);
  glPopMatrix();
}

void Robot::dibujarAureola(unsigned char modo){

}

void Robot::generarPerfilEsfera(){
  int n = 60;
  float alpha = M_PI/2, suma = 2*M_PI/n, radio = 1.0;
  for(int i=0; i<=n/2; i++){
    perfil_esfera.push_back(-radio*cos(alpha));
    perfil_esfera.push_back(-radio*sin(alpha));
    perfil_esfera.push_back(0.0);
    alpha += suma;
  }
}
