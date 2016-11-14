#include "prisma.h"

Prisma::Prisma(){
  //Ayudandome de un dibujo hecho a mano, introduzco los vertices y las caras
  // en orden antihorario
  this->vertices = {-1,0,1, 1,0,1, 1,0,-1, -1,0,-1, -1,1,0, 1,1,0};
  this->caras = {4,0,5, 0,1,5, 1,2,5, 2,4,5, 2,3,4, 3,0,4};
}
