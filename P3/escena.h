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
#include "objetoPLY.h"
#include "objeto_revolucion.h"
#include "robot.h"

class Escena {
private:
// tamaño de los ejes
#define AXIS_SIZE 5000
Ejes ejes;
Robot *robot; //<- mi modelo jerárquico

unsigned char forma_dibujado = 'A';		//por defecto, dibujamos el cubo en modo alambres
unsigned char figura_dibujada = 'C';

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
