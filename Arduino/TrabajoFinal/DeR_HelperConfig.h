#ifndef DER_HELPERCONFIG_H
#define DER_HELPERCONFIG_H

#include <Arduino.h>

#define CANTIDAD_MAX_TARJETAS 10

#define ACCION_FIN 0
#define ACCION_ADELANTE 1
#define ACCION_ATRAS 2
#define ACCION_DERECHA 3
#define ACCION_IZQUIERDA 4

class DeR_HelperConfig {
  public:
    DeR_HelperConfig();

    // Identificadores de tarjetas
    const byte tarjetaInicio[4] = { 0x03, 0xA8, 0x22, 0x0E };
    const byte tarjetaAdelante[4] = { 0x59, 0xE7, 0x11, 0xB4 };
    const byte tarjetaAtras[4] = { 0x73, 0x17, 0x18, 0x0E };
    const byte tarjetaDerecha[4] = { 0x83, 0x62, 0x35, 0x10 };
    const byte tarjetaIzquierda[4] = { 0x33, 0xE5, 0x23, 0x10 };

    bool SonVectoresIguales(byte* vectorA, const byte* vectorB, int longitud);
};

#endif
