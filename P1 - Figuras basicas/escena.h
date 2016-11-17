#ifndef _ESCENA_H
#define _ESCENA_H

#ifdef _WIN32
#include <windows.h>
#endif
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "ejes.h"
#include "objeto3D.h"
#include "cubo.h"
#include "tetraedro.h"

class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;
Objeto3D *cubo = new Cubo;
Objeto3D *tetraedro = new Tetraedro;

unsigned char a_pintar = 'A';		//por defecto, dibujamos el cubo en modo alambres

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects(unsigned char Tecla1);

//Transformación de cámara
	void change_projection();
	void change_observer();

public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
