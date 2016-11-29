#include "cubo.h"

Cubo::Cubo(){
  //Ayudandome de un dibujo hecho a mano, introduzco los vertices y las caras
  // en orden antihorario
  this->vertices = {0.0,1.0,0.0,  0.0,1.0,1.0,  1.0,1.0,1.0,
                    1.0,1.0,0.0,  0.0,0.0,0.0,  0.0,0.0,1.0,
                    1.0,0.0,1.0,  1.0,0.0,0.0};
  this->caras = {0,1,3, 1,2,3,  1,5,2,
                 5,6,2, 2,6,3,  6,7,3,
                 7,0,3, 7,4,0,  4,1,0,
                 4,5,1, 4,7,5,  7,6,5};

}
