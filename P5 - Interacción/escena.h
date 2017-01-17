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
#include "camara.h"

class Escena {
private:

	// tamaño de los ejes
	#define AXIS_SIZE 5000

	//figuras y objetos
	Ejes ejes;
	ObjetoPLY *ply;
	ObjetoRevolucion *revolucion;
	Robot *robot;
	ObjetoRevolucion *esfera;
	ObjetoRevolucion *lata_psup, *lata_pcue, *lata_pinf;
	ObjetoRevolucion *peon1, *peon2, *peon3;
	Cubo *cubo;

	//cámara y selección
	int camaraActiva = 0;
	bool modo_camara = true;
	bool avanzar, retroceder, girar_d, girar_i, resetear;
	float velocidad_camara = 2;
	GLfloat pixels[3];
	bool modo_seleccion = false;

	//atributos del modelo jerárquico
	float grados_hombro_i = 0, grados_hombro_d = 0;
	float grados_cabeza = 0;
	float mov_ojos = 0;
	float grados_pierna_i = 0, grados_pierna_d = 0;
	float grados_cuerpo = 0;
	float mov_aureola = 0;
	bool cabeza_izquierda = true, cabeza_derecha = false;
	bool ojos_fuera = true, ojos_dentro = false;
	bool aureola_arriba = true, aureola_abajo = false;
	bool p_izda_delante = true, p_izda_atras = false;
	bool p_dcha_delante = false, p_dcha_atras = true;
	bool b_izdo_delante = true, b_izdo_atras = false;
	bool b_dcho_delante = true, b_dcho_atras = false;
	bool hacer_animacion = false;
	float velocidad_animacion = 0.1;

	//luces
	LuzPosicional *luz_posicional;
	float posicion_x = 0;
	LuzDireccional *direccional_roja, *direccional_verde, *direccional_azul;
	int discoteca = 0;
	float alpha=0, beta=0;
	bool activar_luces = true, luz_posicional_encendida = false;
	bool animar_luces = true;

	unsigned char forma_dibujado = 's';
	unsigned char figura_dibujada = '5';

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

	// Transformación de cámara
	void change_projection();
	void change_observer();

public:
	Camara camaras[4];
  Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar();
	void animar();

	// Interacción con la escena
	int teclaPulsada(unsigned char tecla,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

	void imprimirMenu();
	void imprimirMenuCamara();
	int getCamaraActiva();
	void moverCamara(int x, int y);
	void actualizarCamara();

	//control de selección de Colores
	void dibujarSeleccion();
	bool getSeleccionado();
	void setSeleccionado(bool condicion);
	void setPixels(float cero, float uno, float dos);
};
#endif
