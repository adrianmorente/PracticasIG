#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include "escena.h"


Escena::Escena(){
  Front_plane=50;
  Back_plane=2000;
  Observer_distance = 4*Front_plane;
  Observer_angle_x = Observer_angle_y=0;
  ejes.changeAxisSize(5000);
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {
	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer
	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);
  /* Creación de objetos */
    cubo = new Cubo;
    tetraedro = new Tetraedro;
    char* nombre_ply = "modelos_ply/big_porsche.ply";
    objetoPLY = new ObjetoPLY(nombre_ply);
    vector<float> vertices = {5.0,6.0,0.0, 4.5,5.0,0.0, 4.0,4.0,0.0,
                              3.0,3.0,0.0, 2.0,2.0,0.0, 1.0,1.0,0.0,
                              1.0,0.0,0.0, 1.0,-1.0,0.0, 1.0,-2.0,0.0,
                              2.0,-3.0,0.0, 5.0,-4.0,0.0};
    objetoRevolucion1 = new ObjetoRevolucion(vertices, 40);
    char* nombre_fichero = "fichero_vertices.ply";
    objetoRevolucionPLY = new ObjetoRevolucion(nombre_fichero);
    vector<float> verticesExamen = {0,0.1,0, 0.7,0.1,0, 1,0,0, 1.1,0,0,
                                    1,0.5,0, 0.5,1,0, 1,2,0, 1.5,3,0,
                                    1.5,4,0, 1.5,5,0, 1.5,6,0, 1.1,6,0,
                                    1.1,5,0, 0.7,4,0, 0,3,0};
    // vector<float> verticesExamen = {0,3,0, 0.7,4,0, 1.1,5,0, 1.1,6,0,
    //                                 1.5,6,0, 1.5,5,0, 1.5,4,0, 1.5,3,0,
    //                                 1,2,0, 0.5,1,0, 1,0.5,0, 1.1,0,0,
    //                                 1,0,0, 0.7,0.1,0, 0,0.1,0};
    objetoExamen = new ObjetoRevolucion(verticesExamen, 10);
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects(unsigned char figura_a_dibujar) {
  switch(figura_a_dibujar){
    case 'C': //cubo
      cubo->dibujar(figura_a_dibujar, forma_dibujado);
      break;
    case 'T': //tetraedro
      tetraedro->dibujar(figura_a_dibujar, forma_dibujado);
      break;
    case 'P': //objetoPLY
      objetoPLY->dibujar(figura_a_dibujar, forma_dibujado);
      break;
    case '0': //objetoRevolucion1
      objetoRevolucion1->borrarTapas();
      this->figura_dibujada = figura_a_dibujar = 'R';
      break;
    case '1': //objetoRevolucion1
      objetoRevolucion1->generarTapaSuperior();
      this->figura_dibujada = figura_a_dibujar = 'R';
      break;
    case '2': //objetoRevolucion1
      objetoRevolucion1->generarTapaInferior();
      this->figura_dibujada = figura_a_dibujar = 'R';
      break;
    case '+': //aumentar tamaño objetos Revolucion
      if(figura_dibujada == 'R'){
        objetoRevolucion1->redimensionar(objetoRevolucion1->getLados()+1);
        cout << "· Nº de perfiles: " << objetoRevolucion1->getLados() << endl;
        figura_a_dibujar = 'R';
        objetoRevolucion1->dibujar(figura_a_dibujar, forma_dibujado);
      }
      else{
        objetoExamen->redimensionar(objetoExamen->getLados()+1);
        cout << "· Nº de perfiles: " << objetoExamen->getLados() << endl;
        figura_a_dibujar = 'M';
        objetoExamen->dibujar(figura_a_dibujar, forma_dibujado);
      }
      break;
    case '-': //disminuir tamaño objetos Revolucion
    if(figura_dibujada == 'R'){
      objetoRevolucion1->redimensionar(objetoRevolucion1->getLados()-1);
      cout << "· Nº de perfiles: " << objetoRevolucion1->getLados() << endl;
      figura_a_dibujar = 'R';
      objetoRevolucion1->dibujar(figura_a_dibujar, forma_dibujado);
    }
    else{
      objetoExamen->redimensionar(objetoExamen->getLados()-1);
      cout << "· Nº de perfiles: " << objetoExamen->getLados() << endl;
      figura_a_dibujar = 'M';
      objetoExamen->dibujar(figura_a_dibujar, forma_dibujado);
    }
    break;
    case 'R': //objetoRevolucion1
      objetoRevolucion1->dibujar(figura_a_dibujar, forma_dibujado);
      break;
    case 'E': //objetoRevolucionPLY
      objetoRevolucionPLY->dibujar(figura_a_dibujar, forma_dibujado);
      break;
    case 'M': //objetoExamen
      objetoExamen->dibujar(figura_a_dibujar, forma_dibujado);
      break;
  }
  figura_dibujada = figura_a_dibujar;
}


void Escena::dibujar(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects(figura_dibujada);
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

  std::cout << "Tecla " << Tecla1 << std::endl;
	if (toupper(Tecla1)=='Q') return 1;

  else if(toupper(Tecla1)=='A' || toupper(Tecla1)=='S' || toupper(Tecla1)=='D' || toupper(Tecla1)=='F'){
    //con estas 4 teclas cambiamos la forma de dibujado: alambres, sólido, puntos y ajedrez
    forma_dibujado = toupper(Tecla1);
    return 0;
  }

  else if(toupper(Tecla1)=='C' || toupper(Tecla1)=='T' || toupper(Tecla1)=='R' || toupper(Tecla1)=='E' ||
          toupper(Tecla1)=='0' || toupper(Tecla1)=='1' || toupper(Tecla1)=='2' || toupper(Tecla1)=='M'){
    //con estas teclas cambiamos la figura dibujada: cubo, tetraedro, objetoRevolucion
    figura_dibujada = toupper(Tecla1);
    draw_objects(figura_dibujada);
    return 0;
  }

  else if(toupper(Tecla1)=='P'){
    //con esta tecla dibujamos un objeto PLY cuyo nombre es leído desde teclado
    string nombre;
    cout << "¿Qué objeto PLY quieres que pinte?: ";
    cin >> nombre;
    char* nombre_archivo = new char[nombre.length()+1];
    strcpy(nombre_archivo, nombre.c_str());
    objetoPLY = new ObjetoPLY(nombre_archivo);
    figura_dibujada = 'P';
    draw_objects(figura_dibujada);
    return 0;
  }

  else if(Tecla1=='+' || Tecla1=='-'){
    draw_objects(Tecla1);
    return 0;
  }

  //si pulsamos cualquier otra, no cambia nada
  else return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyección
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
