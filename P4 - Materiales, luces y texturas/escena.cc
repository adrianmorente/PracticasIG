#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include "escena.h"
#include "luz_posicional.h"


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
  char* nombre_ply = "modelos_ply/beethoven.ply";
  vector<float> vertices = {5.0,6.0,0.0, 4.5,5.0,0.0, 4.0,4.0,0.0,
                            3.0,3.0,0.0, 2.0,2.0,0.0, 1.0,1.0,0.0,
                            1.0,0.0,0.0, 1.0,-1.0,0.0, 1.0,-2.0,0.0,
                            2.0,-3.0,0.0, 5.0,-4.0,0.0};
  revolucion = new ObjetoRevolucion(vertices, 40);
  ply = new ObjetoPLY(nombre_ply);
  robot = new Robot;

  lata_psup = new ObjetoRevolucion("lata-psup.ply");
  lata_psup->trasladar();
  lata_psup->calcularNormales();

  lata_pcue = new ObjetoRevolucion("lata-pcue.ply");
  lata_pcue->trasladar();
  lata_pcue->calcularNormales();

  lata_pinf = new ObjetoRevolucion("lata-pinf.ply");
  lata_pinf->trasladar();
  lata_pinf->calcularNormales();

  peon1 = new ObjetoRevolucion("peon.ply");
  peon1->trasladar();
  peon1->generarTapaSuperior();
  peon1->generarTapaInferior();
  peon1->calcularNormales();

  peon2 = new ObjetoRevolucion("peon.ply");
  peon2->trasladar();
  peon2->generarTapaSuperior();
  peon2->generarTapaInferior();
  peon2->calcularNormales();

  peon3 = new ObjetoRevolucion("peon.ply");
  peon3->trasladar();
  peon3->generarTapaSuperior();
  peon3->generarTapaInferior();
  peon3->calcularNormales();

  float posicion[3] = {10, 3000, 5000};
  luz_posicional = new LuzPosicional(posicion);

  int n = 60;
  float alpha = M_PI/2, suma = 2*M_PI/n, radio = 1.0;
  vector<float> perfil_esfera;
  for(int i=0; i<=n/2; i++){
    perfil_esfera.push_back(-radio*cos(alpha));
    perfil_esfera.push_back(-radio*sin(alpha));
    perfil_esfera.push_back(0.0);
    alpha += suma;
  }
  esfera = new ObjetoRevolucion(perfil_esfera, n);
  esfera->borrarTapas();
  esfera->calcularNormales();
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects(unsigned char figura_a_dibujar) {
  luz_posicional->activar();
  // luz_posicional->moverLuzEjeX(0);
  switch(figura_a_dibujar){
    case '1':
      ply->escalar(); //para visualizarlo a una escala razonable
      ply->dibujar(forma_dibujado);
      break;
    case '2':
      revolucion->escalar();
      revolucion->dibujar(forma_dibujado);
      break;
    case '3':
      robot->dibujar(forma_dibujado, grados_hombro_i, grados_hombro_d, grados_cabeza, mov_ojos, grados_pierna_i, grados_pierna_d, mov_aureola);
      break;
    case '4':
      esfera->escalar();
      esfera->dibujar(forma_dibujado);
      break;
    case '5':
      glScalef(15,15,15);
      glPushMatrix();
        glPushMatrix();
          glTranslatef(-3,1.4,5);
          peon1->setMaterialBlanco();
          peon1->dibujar(forma_dibujado);
        glPopMatrix();
        glPushMatrix();
          glTranslatef(0,1.4,5);
          peon2->setMaterialNegro();
          peon2->dibujar(forma_dibujado);
        glPopMatrix();
        glPushMatrix();
          glTranslatef(3,1.4,5);
          peon3->setMaterialBase();
          peon3->dibujar(forma_dibujado);
        glPopMatrix();
        glPushMatrix();
          glScalef(8,8,8);
          glPushMatrix();
            glTranslatef(0,0,0);
            lata_pinf->setMaterialBase();
            lata_pinf->dibujar(forma_dibujado);
          glPopMatrix();
          glPushMatrix();
            glTranslatef(0,0,0);
            lata_pcue->setMaterialBase();
            lata_pcue->dibujar(forma_dibujado);
          glPopMatrix();
          glPushMatrix();
            glTranslatef(0,0,0);
            lata_psup->setMaterialBase();
            lata_psup->dibujar(forma_dibujado);
          glPopMatrix();
        glPopMatrix();
      glPopMatrix();
      break;
    case '6':
      if(activar_luces)
        activar_luces=false;
      else
        activar_luces=true;
    case '/':
      if(velocidad_animacion > 2)
      velocidad_animacion -= 0.1;
      break;
    case '*':
      velocidad_animacion += 0.1;
      break;
    case '7':
      revolucion->borrarTapas();
      revolucion->dibujar(forma_dibujado);
      break;
    case '8':
      revolucion->generarTapaSuperior();
      revolucion->dibujar(forma_dibujado);
      break;
    case '9':
      revolucion->generarTapaInferior();
      revolucion->dibujar(forma_dibujado);
      break;
    case 'Z':
      grados_hombro_i += 4;
      grados_hombro_d += 4;
      break;
    case 'z':
      grados_hombro_i -= 4;
      grados_hombro_d -= 4;
      break;
    case 'X':
      if(grados_cabeza < 90)
        grados_cabeza += 2;
      break;
    case 'x':
      if(grados_cabeza > -90)
        grados_cabeza -= 2;
      break;
    case 'C':
      if(mov_ojos > 0.1)
        mov_ojos -= 1;
      break;
    case 'c':
      if(mov_ojos < 30)
        mov_ojos += 1;
      break;
    case 'V':
      grados_pierna_d += 5;
      grados_pierna_i += 5;
      break;
    case 'v':
      grados_pierna_d -= 5;
      grados_pierna_i -= 5;
      break;
    case 'b':
      if(mov_aureola < 20)
        mov_aureola += 2;
      break;
    case 'B':
      if(mov_aureola > 0)
        mov_aureola -= 2;
      break;
    case 'N':
      if(grados_pierna_d > -60){
        grados_pierna_d -= 10;
        grados_pierna_i += 10;
      }
      if(grados_hombro_i > -60){
        grados_hombro_i -= 10;
        grados_hombro_d += 10;
      }
      break;
    case 'n':
      if(grados_pierna_d < 60){
        grados_pierna_d += 10;
        grados_pierna_i -= 10;
      }
      if(grados_hombro_i < 60){
        grados_hombro_i += 10;
        grados_hombro_d -= 10;
      }
      break;
    case '.':
      if(hacer_animacion)
        hacer_animacion = false;
      else
        hacer_animacion = true;
  }
  glDisable(GL_LIGHTING);
  luz_posicional->desactivar();
}


void Escena::dibujar(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects(figura_dibujada);
}

int Escena::teclaPulsada(unsigned char tecla,int x,int y) {

  std::cout << "Tecla " << tecla << std::endl;
	if (toupper(tecla)=='Q') return 1;

  //con estas teclas cambiamos la forma de dibujar las figuras
  else if(tolower(tecla)=='p' || tolower(tecla)=='l' || tolower(tecla)=='s' || tolower(tecla)=='a'){
    forma_dibujado = tolower(tecla);
    return 0;
  }

  else if(tecla=='z' || tecla=='Z' || tecla=='x' || tecla=='X' || tecla=='c' || tecla=='C'
        || tecla=='v' || tecla=='V' || tecla=='b' || tecla=='B' || tecla=='n' || tecla=='N'
        || tecla=='6' || tecla=='7' || tecla=='8' || tecla=='9' || tecla=='.' || tecla=='/'
        || tecla=='*'){
    // z/Z -> modificar grado de libertad: rotación de los brazos con respecto a los hombros
    // x/X -> modificar grado de libertad: rotación de la cabeza sobre el cuello (eje Y)
    // c/C -> modificar grado de libertad: traslación de los ojos (eje Z)
    // v/V -> modificar grado de libertad: rotación de las piernas sobre la ingle (eje X)
    // b/B -> modificar grado de libertad: traslación de la aureola (eje Z)
    // n/N -> animación: efecto de caminar (mezcla de z/Z y v/V)
    draw_objects(tecla);
    return 0;
  }

  else if(tecla=='+'){
    luz_posicional->moverLuzEjeX(150);
    draw_objects(figura_dibujada);
  }

  else if(tecla=='-'){
    luz_posicional->moverLuzEjeX(-150);
    draw_objects(figura_dibujada);
  }

  else if(tecla=='1' || tecla=='2' || tecla=='3' || tecla=='4' || tecla=='5'){
    figura_dibujada = tecla;
    draw_objects(figura_dibujada);
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

//**************************************************************************
// Funcion que anima al robot de forma automática
//***************************************************************************
void Escena::animarRobot(){
  if(hacer_animacion){
    if(cabeza_izquierda && grados_cabeza < 90)
      grados_cabeza += (2+velocidad_animacion);
    else{
      cabeza_derecha = true;
      cabeza_izquierda = false;
    }
    if(cabeza_derecha && grados_cabeza > -90)
      grados_cabeza -= (2+velocidad_animacion);
    else{
      cabeza_izquierda = true;
      cabeza_derecha = false;
    }

    if(ojos_fuera && mov_ojos < 30)
      mov_ojos += (1+velocidad_animacion/3);
    else{
      ojos_dentro = true;
      ojos_fuera = false;
    }
    if(ojos_dentro && mov_ojos > 0.1)
      mov_ojos -= (1+velocidad_animacion/3);
    else{
      ojos_fuera = true;
      ojos_dentro = false;
    }

    if(aureola_arriba && mov_aureola < 20)
      mov_aureola += (2+velocidad_animacion);
    else{
      aureola_abajo = true;
      aureola_arriba = false;
    }
    if(aureola_abajo && mov_aureola > 0)
      mov_aureola -= (2+velocidad_animacion);
    else{
      aureola_arriba = true;
      aureola_abajo = false;
    }

    if(p_izda_delante && grados_pierna_d > -60)
      grados_pierna_d -= (5+velocidad_animacion);
    else{
      p_izda_atras = true;
      p_izda_delante = false;
    }
    if(p_izda_atras && grados_pierna_d < 60)
      grados_pierna_d += (5+velocidad_animacion);
    else{
      p_izda_delante = true;
      p_izda_atras = false;
    }

    if(p_izda_delante && grados_pierna_i < 60)
      grados_pierna_i += (5+velocidad_animacion);
    else{
      p_izda_atras = true;
      p_izda_delante = false;
    }
    if(p_izda_atras && grados_pierna_i > -60)
      grados_pierna_i -= (5+velocidad_animacion);
    else{
      p_izda_delante = true;
      p_izda_atras = false;
    }

    if(p_izda_delante && grados_hombro_d > -60)
      grados_hombro_d -= (5+velocidad_animacion);
    else{
      p_izda_atras = true;
      p_izda_delante = false;
    }
    if(p_izda_atras && grados_hombro_d < 60)
      grados_hombro_d += (5+velocidad_animacion);
    else{
      p_izda_delante = true;
      p_izda_atras = false;
    }

    if(p_izda_delante && grados_hombro_i < 60)
      grados_hombro_i += (5+velocidad_animacion);
    else{
      p_izda_atras = true;
      p_izda_delante = false;
    }
    if(p_izda_atras && grados_hombro_i > -60)
      grados_hombro_i -= (5+velocidad_animacion);
    else{
      p_izda_delante = true;
      p_izda_atras = false;
    }
  }
}
