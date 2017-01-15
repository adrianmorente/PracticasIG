//**************************************************************************
// Práctica 1
//
// F.J. melero
//
// GPL
//**************************************************************************
#ifdef _WIN32
#include <windows.h>
#endif
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "escena.h"

Escena *escena;
Camara camaraActiva;
int pos_x, pos_y;
int estado;


void draw_scene(void)  {
	if (escena!=NULL)	escena->dibujar();
	glutSwapBuffers();
}


//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int newWidth,int newHeight)  {
	if (escena!=NULL)	escena->redimensionar(newWidth,newHeight);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)  {

	int salir=0;
	if (escena!=NULL)	salir=escena->teclaPulsada(Tecla1,x,y);
	if (salir) {
		delete escena;
		exit(0);
	} else
		glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y) {
	if (escena!=NULL)
		escena->teclaEspecial(Tecla1,x,y);
	glutPostRedisplay();
}


void idle(){
	escena->animarRobot();
	glutPostRedisplay();
}

int pick(int x, int y){
	// // 1. Declarar buffer de selección
	// glSelectBuffer(...);
	// // 2. Obtener los parámetros del viewport
	// glGetIntegerv(GL_VIEWPORT, viewport);
	// // 3. Pasar OpenGL a modo selección
	// glRenderMode(GL_SELECT);
	// // 4. Fijar la transformación de proyección para la seleccion
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluPickMatrix(x,(viewport[3] - y),5.0, 5.0, viewport);
	// MatrizProyeccion(); // SIN REALIZAR LoadIdentity !
	// // 5. Dibujar la escena con Nombres
	// dibujarConNombres();
	// // 6. Pasar OpenGL a modo render
	// hits = glRenderMode (GL_RENDER);
	// // 7. Restablecer la transformación de proyección (sin gluPickMatrix)
	// // 8. Analizar el contenido del buffer de selección
	// // 9. Devolver el resultado
}

void clickRaton(int boton, int estado, int x, int y){
	if(boton==GLUT_RIGHT_BUTTON){

		if(estado==GLUT_DOWN){
			cout << "Se pulsa el botón derecho, por lo que se entra en el estado -moviendo cámara-";
			pos_x = x;
			pos_y = y;
		}
		else{
			cout << "Se levanta el botón derecho, por lo que se sale del estado -moviendo cámara-";
		}
	}
	else if(boton==GLUT_LEFT_BUTTON){
		pick(x,y);
	}
}

int xant, yant;
void ratonMovido(int x, int y){
	if(estado == GLUT_DOWN){
		// escena->camaras[escena->camaraActiva]->girar(x-xant, y-yant);
		xant = x;
		yant = y;
	}
	glutPostRedisplay();
}



//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

escena = new Escena();

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);
// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo
glutCreateWindow("Practica 5: ADRIAN MORENTE GABALDON");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
escena->inicializar(UI_window_width,UI_window_height);
// inicio del bucle de eventos
glutIdleFunc( idle );
// glutMouseFunc( clickRaton );
// glutMotionFunc( ratonMovido );

glutMainLoop();
return 0;
}
