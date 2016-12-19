#include <iostream>
#include "bitmap_image.hpp"

int main(){
    bitmap_image img("text-lata-1.bmp"); // Carga la imagen
    img.bgr_to_rgb(); // Pasa a formato RGB, ya que usa BGR por defecto
    std::cout << "Imagen de " << img.width() << " por " << img.height() << " pixels.\n";
    img.data(); // Devuelve puntero al array de datos.
}
