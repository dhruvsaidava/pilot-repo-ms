#include <MatrizLed.h>

/*
 * Texto que aparece por la derecha y sale por la izquierda
 */

MatrizLed pantalla;

void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
}

void loop() { 
  pantalla.borrar();
  pantalla.escribirFraseScroll("VERINAG", 200); // Texto, milisegundos entre frames
}
