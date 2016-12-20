#ifndef _ROBOT_H
#define _ROBOT_H

#include "objeto_revolucion.h"
#include "cubo.h"
#include "objetoPLY.h"
#include "objeto3D.h"
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
    void dibujar(unsigned char modo, float grados_hombro_i, float grados_hombro_d, float grados_cabeza, float mov_ojos, float grados_pierna_i,
          float grados_pierna_d, float mov_aureola);
    void dibujarPiernas(unsigned char modo, float grados_pierna_i, float grados_pierna_d);
    void dibujarBrazos(unsigned char modo, float grados_i, float grados_d);
    void dibujarCabeza(unsigned char modo, float grados_cuello, float mov_ojos, float mov_aureola);
    void generarPerfilEsfera();
    void generarPerfilToroide();
    void animarRobot();
};

#endif
