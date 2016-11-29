#include "objeto_revolucion.h"
#include "robot.h"

Robot::Robot(){
  cubo = new Cubo;
  prisma_hex = new ObjetoRevolucion(perfil_cilindro, 6);
  cilindro = new ObjetoRevolucion(perfil_cilindro, 15);
  generarPerfilEsfera();
  esfera = new ObjetoRevolucion(perfil_esfera, 20);
  generarPerfilToroide();
  toroide = new ObjetoRevolucion(perfil_toroide, 20);
  prisma_tri = new ObjetoRevolucion(perfil_cilindro, 3);
}

void Robot::dibujar(unsigned char modo, float grados_hombro_i, float grados_hombro_d, float grados_cabeza, float mov_ojos, float grados_pierna_i, float grados_pierna_d, float mov_aureola){
  //el tronco constará de un hexágono del que sale un pequeño cilindro a modo de
  // cuello
  glPushMatrix();
    glTranslatef(0,-30,0);
    glPushMatrix();
      glScalef(100.0,100.0,50.0);
      prisma_hex->dibujar(modo);
    glPopMatrix();
    glPushMatrix();
      glScalef(15.0,15.0,15.0);
      glTranslatef(0.0,3.80,0.0);
      cilindro->dibujar(modo);
    glPopMatrix();
    dibujarCabeza(modo, grados_cabeza, mov_ojos, mov_aureola);
    dibujarBrazos(modo, grados_hombro_i, grados_hombro_d);
    dibujarPiernas(modo, grados_pierna_i, grados_pierna_d);
  glPopMatrix();
}

void Robot::dibujarPiernas(unsigned char modo, float grados_pierna_i, float grados_pierna_d){
  //cada pierna es un cilindro con una esfera al principio y un prisma triangular
  // "tumbado" al final
  int grados_rodilla_i=0, grados_rodilla_d=0;
  if(grados_pierna_i > 0)
    grados_rodilla_i=0;
  else
    grados_rodilla_i = -grados_pierna_i;

  if(grados_pierna_d > 0)
    grados_rodilla_d=0;
  else
    grados_rodilla_d = -grados_pierna_d;

  glPushMatrix();//pierna izda
    glTranslatef(-20,-50,0);
    glRotatef(grados_pierna_i,1,0,0);
    glPushMatrix();//ingle izda
      glScalef(12,12,12);
      esfera->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//pierna izda
      glTranslatef(0,-22,0);
      glPushMatrix();
        glScalef(12,30,12);
        cilindro->dibujar(modo);
      glPopMatrix();
      glPushMatrix();
        glTranslatef(0,-15,0);
        glRotatef(grados_rodilla_i,1,0,0);
        glPushMatrix();
          glScalef(10,10,10);
          esfera->dibujar(modo);
        glPopMatrix();
        glTranslatef(0,-15,0);
        glPushMatrix();
          glScalef(12,30,12);
          cilindro->dibujar(modo);
        glPopMatrix();
        glPushMatrix();//pie izdo
          glTranslatef(0,-16,0);
          glRotatef(90,0,0,1);
          glScalef(15,28,24);
          prisma_tri->dibujar(modo);
        glPopMatrix();
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();

  glPushMatrix();//pierna dcha
    glTranslatef(20,-50,0);
    glRotatef(grados_pierna_d,1,0,0);
    glPushMatrix();//ingle dcha
      glScalef(12,12,12);
      esfera->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//pierna dcha
      glTranslatef(0,-22,0);
      glPushMatrix();
        glScalef(12,30,12);
        cilindro->dibujar(modo);
      glPopMatrix();
      glPushMatrix();
        glTranslatef(0,-15,0);
        glRotatef(grados_rodilla_d,1,0,0);
        glPushMatrix();
          glScalef(10,10,10);
          esfera->dibujar(modo);
        glPopMatrix();
        glTranslatef(0,-15,0);
        glPushMatrix();
          glScalef(12,30,12);
          cilindro->dibujar(modo);
        glPopMatrix();
        glPushMatrix();//pie dcho
          glTranslatef(0,-16,0);
          glRotatef(90,0,0,1);
          glScalef(15,28,24);
          prisma_tri->dibujar(modo);
        glPopMatrix();
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();
}

void Robot::dibujarBrazos(unsigned char modo, float grados_i, float grados_d){

  glPushMatrix();//cilindro del hombro izquierdo (fijo)
    glTranslatef(-56,38,0);
    glRotatef(90,0,0,1);
    glScalef(12,24,12);
    cilindro->dibujar(modo);
  glPopMatrix();
  //brazo izquierdo
  glPushMatrix();//esfera del hombro (rota con el brazo)
    glPushMatrix();
      glTranslatef(-65,38,0);
      glRotatef(grados_i,1,0,0);
      glScalef(12,12,12);
      esfera->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//brazo
      glTranslatef(-65,38,0);
      glRotatef(grados_i,1,0,0);
      glTranslatef(0,-38.5,0);
      glPushMatrix();
        glScalef(12,76,12);
        cilindro->dibujar(modo);
      glPopMatrix();
      glPushMatrix();//mano izquierda(rota en el extremo del brazo)
        glTranslatef(0,-38,0);
        glScalef(12,12,12);
        esfera->dibujar(modo);
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();

  glPushMatrix();//cilindro del hombro derecho (fijo)
    glTranslatef(56,38,0);
    glRotatef(90,0,0,1);
    glScalef(12,24,12);
    cilindro->dibujar(modo);
  glPopMatrix();
  //brazo derecho
  glPushMatrix();//esfera del hombro (rota con el brazo)
    glPushMatrix();
      glTranslatef(65,38,0);
      glRotatef(grados_d,1,0,0);
      glScalef(12,12,12);
      esfera->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//brazo
      glTranslatef(65,38,0);
      glRotatef(grados_d,1,0,0);
      glTranslatef(0,-38.5,0);
      glPushMatrix();
        glScalef(12,76,12);
        cilindro->dibujar(modo);
      glPopMatrix();
      glPushMatrix();//mano derecha(rota en el extremo del brazo)
        glTranslatef(0,-38,0);
        glScalef(12,12,12);
        esfera->dibujar(modo);
      glPopMatrix();
    glPopMatrix();
  glPopMatrix();
}

void Robot::dibujarCabeza(unsigned char modo, float grados_cuello, float mov_ojos, float mov_aureola){
  glPushMatrix();
    glTranslatef(0,95,0);//cabeza
    glRotatef(grados_cuello,0,1,0);
    glPushMatrix();
      glScalef(75,60,75);
      cubo->trasladar();
      cubo->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//ojo izdo
      glTranslatef(-15,10,40.5+mov_ojos);
      glRotatef(90,1,0,0);
      glRotatef(30,0,1,0);
      glScalef(18,5,18);
      prisma_tri->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//ojo dcho
      glTranslatef(15,10,40.5+mov_ojos);
      glRotatef(90,1,0,0);
      glRotatef(30,0,1,0);
      glScalef(18,5,18);
      prisma_tri->dibujar(modo);
    glPopMatrix();
    glPushMatrix();//aureola
      glTranslatef(0,50+mov_aureola,-15);
      glRotatef(-15,1,0,0);
      glScalef(8,6,8);
      toroide->borrarTapas();
      toroide->dibujar(modo);
    glPopMatrix();
  glPopMatrix();
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

void Robot::generarPerfilToroide(){
  int n = 60;
  float alpha = M_PI/2, suma = 2*M_PI/n, radio = 1.0;
  for(int i=0; i<=n; i++){
    perfil_toroide.push_back(-radio*cos(alpha)+4);
    perfil_toroide.push_back(-radio*sin(alpha));
    perfil_toroide.push_back(0.0);
    alpha += suma;
  }
}
