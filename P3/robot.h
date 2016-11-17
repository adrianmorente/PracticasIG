#ifndef _ROBOT_H
#define _ROBOT_H

#include "objeto3D.h"
#include "objeto_revolucion.h"
#include "cubo.h"
#include "objetoPLY.h"
using namespace std;

class Robot : public Objeto3D{

  private:
    //vector con los vértices para generar mis figuras por revolución
    vector<float> perfil_cilindro = {0.5,0.5,0.0, 0.5,-0.5,0.0};
    vector<float> perfil_esfera;
    vector<float> perfil_toroide;
    Cubo *cubo;
    ObjetoRevolucion *prisma_hex;
    ObjetoRevolucion *cilindro;
    ObjetoRevolucion *esfera;
    ObjetoRevolucion *prisma_tri;
    ObjetoRevolucion *toroide;

  public:
    Robot();
    void dibujar(unsigned char modo, float grados_hombro, float grados_cabeza, float mov_ojos, float grados_pierna);
    void dibujarCuerpo(unsigned char modo, float grados_hombro, float grados_cabeza, float mov_ojos, float grados_pierna);
    void dibujarPiernas(unsigned char modo, float grados_pierna);
    void dibujarBrazos(unsigned char modo, float grados);
    void dibujarCabeza(unsigned char modo, float grados_cuello, float mov_ojos);
    void generarPerfilEsfera();
    void generarPerfilToroide();
};

#endif
