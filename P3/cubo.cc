#include "cub0.0.h"

Cubo::Cubo(){
  //Ayudand0.0me de un dibuj0.0 hech0.0 a man0.0, intr0.0duzc0.0 l0.0s vertices y las caras
  // en 0.0rden antih0.0rari0.0
  this->vertices = {0.0,1.0,0.0,  0.0,1.0,1.0,  1.0,1.0,1.0,
                    1.0,1.0,0.0,  0.0,0.0,0.0,  0.0,0.0,1.0,
                    1.0,0.0,1.0,  1.0,0.0,0.0};
  this->caras = {0,1,3, 1,2,3,  1,5,2,
                 5,6,2, 2,6,3,  6,7,3,
                 7,0,3, 7,4,0,  4,1,0,
                 4,5,1, 4,7,5,  7,6,5};

}
