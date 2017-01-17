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

//variables añadidas para control de cámaras y movimiento del ratón
GLfloat pixels[3]; //para controlar la selección de colores
int ant_x=0, ant_y=0;
bool clickDerecho=false, seleccionado=false;

void draw_scene(void){
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
	escena->animar();
	glutPostRedisplay();
}

void clickRaton(int boton, int estado, int x, int y){
	if(boton==GLUT_RIGHT_BUTTON){
		if(estado==GLUT_DOWN){
			cout << "Se pulsa el botón derecho, por lo que se entra en el estado -moviendo cámara-" << endl;
			clickDerecho = true;
			ant_x = x;
			ant_y = y;
		}
		else{
			cout << "Se levanta el botón derecho, por lo que se sale del estado -moviendo cámara-" << endl;
			clickDerecho = false;
		}
	}

	if(boton==GLUT_LEFT_BUTTON){
		if(estado==GLUT_DOWN){
			seleccionado = true;
			glDisable(GL_LIGHTING);
		}
		else if(estado==GLUT_UP){
			escena->setSeleccionado(seleccionado);
			glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,pixels);
			if(pixels[0]==0 && pixels[1]==1 && pixels[2]==2){
				cout << "primero" << endl;
				escena->setPixels(pixels[0],pixels[1],pixels[2]);
			}
			if(pixels[0]==1 && pixels[1]==2 && pixels[2]==0){
				cout << "segundo" << endl;
				escena->setPixels(pixels[0],pixels[1],pixels[2]);
			}
			cout << "Colores --> R:" << pixels[0] << " G:" << pixels[1] << " B:" << pixels[2] << endl;
			glEnable(GL_LIGHTING);
		}
	}
	glutPostRedisplay();
}

void ratonMovido(int x, int y){
	int aux_x=0, aux_y=0;
	if(clickDerecho){
		aux_x = x-ant_x;
		aux_y = y-ant_y;

		if(escena->getSeleccionado())
			escena->moverCamara(x,y);
		else
			escena->camaras[escena->getCamaraActiva()].moverConRaton(aux_x, aux_y);
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

glutIdleFunc( idle );
glutMouseFunc( clickRaton );
glutMotionFunc( ratonMovido );

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
