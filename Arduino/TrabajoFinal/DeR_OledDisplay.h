#ifndef DER_OLEDDISPLAY_H
#define DER_OLEDDISPLAY_H

#include "U8glib.h"

class DeR_OledDisplay {
  public:
    DeR_OledDisplay();
    void MostrarMensaje(String mensaje);
    void MostrarFlechaArriba();
    void MostrarFlechaAbajo();
    void MostrarFlechaDerecha();
    void MostrarFlechaIzquierda();
    void MostrarPantallaInicio();
    void MostrarCaracter(char caracter);
  private:
    void DibujarFlechaArriba();
    void DibujarFlechaAbajo();
    void DibujarFlechaDerecha();
    void DibujarFlechaIzquierda();
    void PantallaInicio();
    void Dibujar(String mensaje);
    void DibujarCaracter(char caracter);
};

#endif
