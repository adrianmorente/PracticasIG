#ifndef _LUZ_H
#define _LUZ_H

struct Posicion{
  float x, y, z;
}

class Luz{

  private:
    Posicion posicion;
    int tipo; // 0 -> posicional; 1 -> direccional

  public:
    posicionar();

};

#endif
