#include "objeto3D.h"
#include "math.h"

Objeto3D::Objeto3D(){
  this->vertices.clear();
  this->caras.clear();
  this->normales_caras.clear();
  this->normales_vertices.clear();
  GLfloat color[4] = {0, 0.5, 0.5, 1.0};
  glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color);
  glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, color);
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color);
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 50);
}

void Objeto3D::calcularNormales(){
  if(this->vertices.size()>0 && this->caras.size()>0){
    Punto a, b; //realmente son los vectores del triangulo
    Punto normal;
    normal.x = normal.y = normal.z = 0;
    normales_vertices.assign(vertices.size(), 0);

    for(unsigned int i=0; i<caras.size()/3; i++){
      float vx, vy, vz;
      //obtenemos los vertices del triangulo
      vx = caras[i*3];
      vy = caras[i*3+1];
      vz = caras[i*3+2];

      //calculamos los vectores
      a.x = vertices[vy*3]   - vertices[vx*3];
      a.y = vertices[vy*3+1] - vertices[vx*3+1];
      a.z = vertices[vy*3+2] - vertices[vx*3+2];
      b.x = vertices[vz*3]   - vertices[vx*3];
      b.y = vertices[vz*3+1] - vertices[vx*3+1];
      b.z = vertices[vz*3+2] - vertices[vx*3+2];
      //hacemos producto vectorial para calcular la normal
      normal.x = (a.y*b.z - b.y*a.z);
      normal.y = (a.z*b.x - b.z*a.x);
      normal.z = (a.x*b.y - b.x*a.y);
      //normalizamos
      float modulo = this->modulo(normal);
      //añadimos al vector de normales
      this->normales_caras.push_back(normal.x/modulo);
      this->normales_caras.push_back(normal.y/modulo);
      this->normales_caras.push_back(normal.z/modulo);
    }
    this->calcularNormalesVertices();
  }
}

void Objeto3D::calcularNormalesVertices(){
  for(unsigned int i=0; i<caras.size()/3; i++){
    normales_vertices[caras[i*3]*3] += normales_caras[i*3];
    normales_vertices[caras[i*3]*3+1] += normales_caras[i*3+1];
    normales_vertices[caras[i*3]*3+2] += normales_caras[i*3+2];

    normales_vertices[caras[i*3+1]*3] += normales_caras[i*3];
    normales_vertices[caras[i*3+1]*3+1] += normales_caras[i*3+1];
    normales_vertices[caras[i*3+1]*3+2] += normales_caras[i*3+2];

    normales_vertices[caras[i*3+2]*3] += normales_caras[i*3];
    normales_vertices[caras[i*3+2]*3+1] += normales_caras[i*3+1];
    normales_vertices[caras[i*3+2]*3+2] += normales_caras[i*3+2];
  }

  for(unsigned int i=0; i<normales_vertices.size()/3; i++){
    Punto aux;
    aux.x = normales_vertices[i*3];
    aux.y = normales_vertices[i*3+1];
    aux.z = normales_vertices[i*3+2];
    float modulo = this->modulo(aux);
    normales_vertices[i*3] /= modulo;
    normales_vertices[i*3+1] /= modulo;
    normales_vertices[i*3+2] /= modulo;
  }
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

void Objeto3D::setMaterialBase(){
  GLfloat color[4] = {0.8, 0.0, 0.0, 1.0};
  GLfloat difuso[4]={0.8,0.0,0.0,1.0};
  GLfloat especular[4]={0.75,0.75,0.75,1.0};

  glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color);
  glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, especular);
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 128);
}

void Objeto3D::setMaterialNegro(){
  GLfloat color[4] = {0.1, 0.1, 0.1, 1.0};
  GLfloat difuso[4]={0.15,0.15,0.15,1.0};
  GLfloat especular[4]={0.75,0.75,0.75,1.0};

  glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color);
  glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, especular);
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 128);
}

void Objeto3D::setMaterialBlanco(){
  GLfloat color[4] = {0.7, 0.7, 0.7, 1.0};
  GLfloat difuso[4] = {0.75, 0.75, 0.75, 1.0};
  GLfloat especular[4]={0.0, 0.0, 0.0, 0.0};
  glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, color);
  glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, especular);
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 5);
}

void Objeto3D::dibujar(unsigned char modo){

  vector<float> colores;
  for(int i=0; i<vertices.size()/3; i++){   //aquí el vector de colores que usaremos.
    colores.push_back(0.58);                //  tenemos que añadir los tres valores RGB tantas veces como
    colores.push_back(0.0);                 //  vértices vayamos a dibujar:
    colores.push_back(0.827);
  }

  glEnable(GL_LIGHTING);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnable(GL_CULL_FACE);
  glLineWidth(1.5);
  glPointSize(5.0);
  glNormalPointer(GL_FLOAT, 0, &normales_vertices[0]);
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

  glDisable(GL_LIGHTING);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisable(GL_CULL_FACE);
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

  glEnable(GL_LIGHTING);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnable(GL_CULL_FACE);
  glLineWidth(3.0);
  glPointSize(5.0);
  glNormalPointer(GL_FLOAT, 0, &normales_vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &color1[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, vert1.size(), GL_UNSIGNED_INT, &vert1[0]);

  glColorPointer(3, GL_FLOAT, 0, &color2[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, vert2.size(), GL_UNSIGNED_INT, &vert2[0]);

  glDisable(GL_LIGHTING);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisable(GL_CULL_FACE);
}

void Objeto3D::dibujarConLineas(){

  glEnable(GL_NORMALIZE);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glEnable(GL_LIGHTING);

  vector<float> colores;
  for(int i=0; i<vertices.size()/3; i++){
    colores.push_back(0.392);
    colores.push_back(0.584);
    colores.push_back(0.929);
  }

  glEnable(GL_CULL_FACE);
  glLineWidth(1.0);
  glPointSize(5.0);
  glNormalPointer(GL_FLOAT, 0, &normales_vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &colores[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
  glPolygonOffset(-1,-1);

  // glBegin(GL_LINES);
  //   for (int i=0; i<normales_vertices.size(); i+=3){
  //     glVertex3f(vertices[i], vertices[i+1], vertices[i+2]);
  //     glVertex3f(vertices[i]+normales_vertices[i],vertices[i+1]+ normales_vertices[i+1], vertices[i+2]+normales_vertices[i+2]);
  //   }
  // glEnd();

  glEnable(GL_POLYGON_OFFSET_LINE);
  colores.clear();

  setBoundingBox();
  for(int i=0; i<vertices.size()/3; i++){
    colores.push_back(0.0);
    colores.push_back(0.0);
    colores.push_back(0.1);
  }
  glNormalPointer(GL_FLOAT, 0, &normales_vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &colores[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
  glDisable(GL_POLYGON_OFFSET_LINE);

  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_COLOR_ARRAY);
  glDisable(GL_CULL_FACE);
}
