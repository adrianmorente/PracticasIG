#include "tetraedro.h"

Tetraedro::Tetraedro(){
  //Ayudandome de un dibujo hecho a mano, introduzco los vertices y las caras
  // en orden antihorario
  this->vertices = {0,80,0, 0,0,-45, -45,0,45, 45,0,45};
  this->caras = {0,2,3, 0,3,1, 2,0,1, 1,3,2};
  this->calcularNormalesCaras();
  this->calcularNormalesVertices();
}
