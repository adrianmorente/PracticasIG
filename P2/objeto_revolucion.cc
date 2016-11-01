#include "objeto_revolucion.h"
#include "math.h"
#include <fstream>
#include "file_ply_stl.h"
#include <iterator>

ObjetoRevolucion::ObjetoRevolucion(vector<float> v_perfil, int n_puntos){
  this->vertices = this->perfil = v_perfil;
  this->n_lados = n_puntos;
  generarContorno();
  generarRevolucion(n_puntos);
  setBoundingBox();
}


ObjetoRevolucion::ObjetoRevolucion(char* nombre_archivo){
  _file_ply lector;
  this->n_lados = 30;   //<-- un número de ejemplo
  lector.open(nombre_archivo);
  this->caras.clear();
  lector.read(this->vertices, this->caras);
  this->perfil = this->vertices;
  generarContorno();
  generarRevolucion(this->n_lados);
  setBoundingBox();
}


int ObjetoRevolucion::getLados(){
  return this->n_lados;
}


int ObjetoRevolucion::getNumeroDePuntos(){
  return this->vertices.size();
}


void ObjetoRevolucion::redimensionar(int n){
  this->n_lados = n;
  this->vertices = perfil;
  this->caras.clear();
  generarContorno();
  generarRevolucion(n_lados);
}


void ObjetoRevolucion::generarRevolucion(int n_puntos){
  int num_vert_perfil = perfil.size();   //número de puntos del perfil original
  //cuantos más puntos, forma circular mejor definida
  //los 360ª necesarios para generar el objeto de revolución, necesitamos
  // introducirlos en radianes:
  float angulo = (2*M_PI) / n_puntos;
  float coseno = cos(angulo);
  float seno = sin(angulo);
  //cálculo de ubicación de los vértices

  for(int i = 0; i < n_puntos; i++){
    for(int j = (i*num_vert_perfil); j < (i*num_vert_perfil + num_vert_perfil); j += 3){
      //actualizamos las variables para los siguientes puntos, de acuerdo con la
      // fórmula encontrada en la teoría (tema 2, pág. 18 (66))
      this->vertices.push_back((coseno*vertices[j]) + (seno*vertices[j+2]));
      this->vertices.push_back(vertices[j+1]);
      this->vertices.push_back(((-seno)*vertices[j]) + (coseno*vertices[j+2]));
    }
  }
}

void ObjetoRevolucion::generarContorno(){
  int num_puntos = this->perfil.size()/3;   //número de puntos (NO COORDENADAS) del perfil

  for(int i = 0; i < this->n_lados; i++){
    int x = (i * num_puntos) + num_puntos-1;
    for(int j = (i*num_puntos); j < x; j++){
      caras.push_back(j+1);
      caras.push_back(j+num_puntos);
      caras.push_back(j);

      caras.push_back(j+1);
      caras.push_back(j+num_puntos+1);
      caras.push_back(j+num_puntos);
    }
  }
}


void ObjetoRevolucion::generarTapaSuperior(){
  this->vertices.push_back(0.0);           //
  this->vertices.push_back(maximo.y);      //  coordenadas del vértice central de la tapa superior
  this->vertices.push_back(0.0);           //
  int num_vert_perfil = perfil.size()/3;

  for(int i = 0; i < n_lados; i++){
    for(int j=(i*num_vert_perfil); j<(i*num_vert_perfil + num_vert_perfil-1); j++){
      if(j == (i*num_vert_perfil)){
        caras.push_back(j+num_vert_perfil);
        caras.push_back(vertices.size()/3 -1);
        caras.push_back(j);
      }
    }
  }
}


void ObjetoRevolucion::generarTapaInferior(){
  this->vertices.push_back(0.0);         //
  this->vertices.push_back(minimo.y);    //  coordenadas del vértice central de la tapa inferior
  this->vertices.push_back(0.0);         //
  int num_vert_perfil = perfil.size()/3;

  for(int i = 0; i < n_lados; i++){
    for(int j=(i*num_vert_perfil); j<(i*num_vert_perfil-1+num_vert_perfil); j++){
      if(j+1 == ((i*num_vert_perfil) + num_vert_perfil-1)){
        caras.push_back(j+1);
        caras.push_back(vertices.size()/3 -1);
        caras.push_back(j+1+num_vert_perfil);
      }
    }
  }
}


void ObjetoRevolucion::borrarTapas(){
  caras.clear();
  generarContorno();
}
