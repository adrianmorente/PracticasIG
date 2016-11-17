#ifndef _OBJETO_PLY_H
#define _OBJETO_PLY_H

#include "objeto3D.h"
#include "file_ply_stl.h"
using namespace std;

class ObjetoPLY : public Objeto3D{

  public:
    ObjetoPLY();
    ObjetoPLY(char *nombre);

  private:
    _file_ply lector;

};


#endif
