#include "objeto3D.h"
#include "math.h"


Objeto3D::Objeto3D(){
  this->vertices.clear();
  this->caras.clear();
}

void Objeto3D::calcularNormalCara(vector<int> & cara){
  Punto normal; //realmente es un vector 3D, pero lo llamaremos Punto igual que nuestro struct
  normal.x = 0;
  normal.y = 0;
  normal.z = 0;

  Punto actual, siguiente;
  for(int i=0; i<cara.size(); i++){
    actual.x = cara[i];
    actual.y = cara[i+1];
    actual.z = cara[i+2];
    siguiente.x = cara[(i+3) %cara.size()];
    siguiente.y = cara[(i+4) %cara.size()];
    siguiente.z = cara[(i+5) %cara.size()];

    normal.x += ((actual.y - siguiente.y)*(actual.z - siguiente.z));
    normal.y += ((actual.z - siguiente.z)*(actual.x - siguiente.x));
    normal.z += ((actual.x - siguiente.x)*(actual.y - siguiente.y));
  }

  float modulo = sqrt( normal.x*normal.x + normal.y*normal.y + normal.z+normal.z );
  normal.x = normal.x/modulo;
  normal.y = normal.y/modulo;
  normal.z = normal.z/modulo;
}

void Objeto3D::calcularNormalesCaras(){
  vector<int> aux = {0,0,0};
  for(int i=0; i<caras.size(); i+=3){
    aux[0] = caras[i];
    aux[1] = caras[i+1];
    aux[2] = caras[i+2];
    calcularNormalCara(aux);
    this->normales_caras.push_back(aux[0]);
    this->normales_caras.push_back(aux[1]);
    this->normales_caras.push_back(aux[2]);
  }
}

void Objeto3D::calcularNormalesVertices(){

}

void Objeto3D::setBoundingBox(){
  Punto mini, maxi;
  mini.x = maxi.x = vertices[0];
  mini.y = maxi.y = vertices[1];
  mini.z = maxi.z = vertices[2];
  for(int i=0; i<vertices.size(); i+=3){
    mini.x = min(vertices[i], mini.x);
    mini.y = min(vertices[i+1], mini.y);
    mini.z = min(vertices[i+2], mini.z);
    maxi.x = max(vertices[i], maxi.x);
    maxi.y = max(vertices[i+1], maxi.y);
    maxi.z = max(vertices[i+2], maxi.z);
  }
  minimo = mini;
  maximo = maxi;
}

Punto Objeto3D::getCentro(){
  Punto centro;
  centro.x = (minimo.x + maximo.x)/2.0f;
  centro.y = (minimo.y + maximo.y)/2.0f;
  centro.z = (minimo.z + maximo.z)/2.0f;
  return centro;
}

float Objeto3D::getSizeBoundingBox(){
  //buscamos el vector que une minimo y maximo, y hallamos su modulo
  Punto p;
  p.x = maximo.x - minimo.x;
  p.y = maximo.y - minimo.y;
  p.z = maximo.z - minimo.z;
  return modulo(p);
}

float Objeto3D::getMaxX(){
  return maximo.x;
}

float Objeto3D::getMaxY(){
  return maximo.y;
}

float Objeto3D::getMaxZ(){
  return maximo.z;
}


float Objeto3D::modulo(Punto p){
  return sqrt( pow(p.x,2) + pow(p.y,2) + pow(p.z,2) );
}

void Objeto3D::escalar(){
  float tama = getSizeBoundingBox();
  //con el tamaño real, obtenemos un tamaño que "quepa en nuestra pantalla"
  glScalef(200.0f/tama,200.0f/tama,200.0f/tama);
}

void Objeto3D::trasladar(){
  Punto centro = getCentro();
  glTranslatef(-1*centro.x, -1*centro.y, -1*centro.x);
}

void Objeto3D::rotar(float grados){
  glRotatef(grados,0.0f,0.0f,0.0f);
}

void Objeto3D::dibujar(unsigned char modo){

  vector<float> colores;
  for(int i=0; i<vertices.size()/3; i++){   //aquí el vector de colores que usaremos.
    colores.push_back(0.58);                //  tenemos que añadir los tres valores RGB tantas veces como
    colores.push_back(0.0);                 //  vértices vayamos a dibujar:
    colores.push_back(0.827);
  }

  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnable(GL_CULL_FACE);
  glLineWidth(1.5);
  glPointSize(5.0);
  glNormalPointer(GL_FLOAT, 0, &normales_caras[0]);
  glColorPointer(3, GL_FLOAT, 0, &colores[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);

  switch(modo){
    case 'l':
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
      break;
    case 's':
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      dibujarConLineas();
      break;
    case 'p':
      glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
      glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
      break;
    case 'a':
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      dibujarAjedrez();
      break;
  }
  setBoundingBox();
}

void Objeto3D::dibujarAjedrez(){

  //dividimos las caras a pintar en dos
  vector<int> vert1, vert2;
  for(int i=0; i<caras.size(); i+=6){
    vert1.push_back(caras[i]);
    vert1.push_back(caras[i+1]);
    vert1.push_back(caras[i+2]);
    vert2.push_back(caras[i+3]);
    vert2.push_back(caras[i+4]);
    vert2.push_back(caras[i+5]);
  }
  //almacenaremos los valores RGB en dos arrays, tantas veces como vértices tengamos
  vector<float> color1, color2;
  for(int i=0; i<caras.size(); i++){
    //1º
    color1.push_back(0.0);
    color1.push_back(0.0);
    color1.push_back(0.1);
    //2º
    color2.push_back(0.392);
    color2.push_back(0.584);
    color2.push_back(0.929);
  }

  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glLineWidth(3.0);
  glPointSize(5.0);
  glNormalPointer(GL_FLOAT, 0, &normales_caras[0]);
  glColorPointer(3, GL_FLOAT, 0, &color1[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, vert1.size(), GL_UNSIGNED_INT, &vert1[0]);
  //tras pintar la mitad de las caras de un color, "mojamos el pincel" en otro
  // color y pintamos el resto de caras
  glColorPointer(3, GL_FLOAT, 0, &color2[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, vert2.size(), GL_UNSIGNED_INT, &vert2[0]);
}

void Objeto3D::dibujarConLineas(){

  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  vector<float> colores;
  for(int i=0; i<vertices.size()/3; i++){
    colores.push_back(0.392);
    colores.push_back(0.584);
    colores.push_back(0.929);
  }


  glEnable(GL_CULL_FACE);
  glLineWidth(1.0);
  glPointSize(5.0);
  glNormalPointer(GL_FLOAT, 0, &normales_caras[0]);
  glColorPointer(3, GL_FLOAT, 0, &colores[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
  glPolygonOffset(-1,-1);

  glEnable(GL_POLYGON_OFFSET_LINE);
  colores.clear();

  setBoundingBox();
  for(int i=0; i<vertices.size()/3; i++){
    colores.push_back(0.0);
    colores.push_back(0.0);
    colores.push_back(0.1);
  }
  glColorPointer(3, GL_FLOAT, 0, &colores[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
  glDisable(GL_POLYGON_OFFSET_LINE);
}
