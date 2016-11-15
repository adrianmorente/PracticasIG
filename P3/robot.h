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
    vector<float> perfil_cilindro = {0.0,-0.5,0.0, 0.5,-0.5,0.0,
                                      0.5,0.5,0.0, 0.0,0.5,0.0};
    vector<float> perfil_esfera;
    Cubo *cubo;
    ObjetoRevolucion *prisma_hex;
    ObjetoRevolucion *cilindro;
    ObjetoRevolucion *esfera;
    ObjetoRevolucion *prisma;

  public:
    Robot();
    void dibujar(unsigned char modo);
    void dibujarPiernas(unsigned char modo);
    void dibujarCuerpo(unsigned char modo);
    void dibujarBrazos(unsigned char modo);
    void dibujarCabeza(unsigned char modo);
    void dibujarAureola(unsigned char modo);
    void generarPerfilEsfera();
    /*
    void rotarPiernas();
    void rotarBrazos();
    void rotarCabeza();
    */
};

#endif
