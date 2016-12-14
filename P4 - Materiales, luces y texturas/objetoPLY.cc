#include "objetoPLY.h"

ObjetoPLY::ObjetoPLY(){
  this->vertices.clear();
  this->caras.clear();
}

ObjetoPLY::ObjetoPLY(char *nombre){
  lector.open(nombre);
  lector.read(this->vertices, this->caras);
  cout << "Tamaño PLY: " << vertices.size() << " vertices y " << caras.size() << " caras." << endl;
  this->calcularNormales();
  for(int i=0; i<normales_caras.size(); i++){
    cout << normales_caras[i] << " ";
  }
}
