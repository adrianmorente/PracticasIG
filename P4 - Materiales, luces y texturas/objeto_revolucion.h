#ifndef _OBJETO_REVOLUCION_H
#define _OBJETO_REVOLUCION_H

#include "objeto3D.h"
#include "math.h"
using namespace std;

class ObjetoRevolucion : public Objeto3D {

  private:
    vector<float> perfil;
    int n_lados;

  public:
    ObjetoRevolucion(vector<float> v_perfil, int n_puntos);
    ObjetoRevolucion(char* nombre_archivo);
    int getLados();
    int getNumeroDePuntos();
    void redimensionar(int n);
    void generarRevolucion(int n_puntos);
    void generarContorno();
    void generarTapaSuperior();
    void generarTapaInferior();
    void borrarTapas();
};

#endif
