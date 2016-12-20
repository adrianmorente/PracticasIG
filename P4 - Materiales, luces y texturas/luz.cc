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
