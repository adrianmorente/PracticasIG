#include "objetoPLY.h"

ObjetoPLY::ObjetoPLY(){
  this->vertices.clear();
  this->caras.clear();
}

ObjetoPLY::ObjetoPLY(char *nombre){
  lector.open(nombre);
  lector.read(this->vertices, this->caras);
  cout << vertices.size() << endl;
  cout << caras.size() << endl;
}
