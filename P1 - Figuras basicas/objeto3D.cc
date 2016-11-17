#include "objeto3D.h"


Objeto3D::Objeto3D(){
  this->vertices.clear();
  this->caras.clear();
}

void Objeto3D::dibujar(GLenum modo){

  vector<float> colores;
  for(int i=0; i<vertices.size()/3; i++){   //aquí el vector de colores que usaremos.
    colores.push_back(0.58);                //  tenemos que añadir los tres valores RGB tantas veces como
    colores.push_back(0.0);                 //  vértices vayamos a dibujar:
    colores.push_back(0.827);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glLineWidth(3.0);
  glPointSize(5.0);
  glColorPointer(3, GL_FLOAT, 0, &colores[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  //usamos el 'GLenum modo' para elegir cómo pintar el poliedro según tecla pulsada
  glDrawElements(modo, caras.size(), GL_UNSIGNED_INT, &caras[0]);
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
    //1º Dorado
    color1.push_back(1.0);
    color1.push_back(0.843);
    color1.push_back(0.0);
    //2º Lila
    color2.push_back(0.576);
    color2.push_back(0.439);
    color2.push_back(0.859);
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glLineWidth(3.0);
  glPointSize(5.0);

  glColorPointer(3, GL_FLOAT, 0, &color1[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, vert1.size(), GL_UNSIGNED_INT, &vert1[0]);
  //tras pintar la mitad de las caras de un color, "mojamos el pincel" en otro
  // color y pintamos el resto de caras
  glColorPointer(3, GL_FLOAT, 0, &color2[0]);
  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glDrawElements(GL_TRIANGLES, vert2.size(), GL_UNSIGNED_INT, &vert2[0]);


}
