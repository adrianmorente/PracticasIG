#include "cubo.h"

Cubo::Cubo(){
  //Ayudandome de un dibujo hecho a mano, introduzco los vertices y las caras
  // en orden antihorario
  float X = 50.0f, O = -50.0f;
  this->vertices = {O,X,O,  O,X,X,  X,X,X,
                    X,X,O,  O,O,O,  O,O,X,
                    X,O,X,  X,O,O};
  this->caras = {0,1,3, 1,2,3,  1,5,2,
                 5,6,2, 2,6,3,  6,7,3,
                 7,0,3, 7,4,0,  4,1,0,
                 4,5,1, 4,7,5,  7,6,5};

}
