#include "objetoPLY.h"

ObjetoPLY::ObjetoPLY(){
  this->vertices.clear();
  this->caras.clear();
}

ObjetoPLY::ObjetoPLY(char *nombre){
  lector.open(nombre);
  lector.read(this->vertices, this->caras);
  cout << "Tamaño PLY: " << vertices.size() << " vertices y " << caras.size() << " caras." << endl;
  this->calcularNormalesCaras();
  this->calcularNormalesVertices();
}
