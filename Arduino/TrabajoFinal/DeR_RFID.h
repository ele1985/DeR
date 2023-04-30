#ifndef DER_RFID_H
#define DER_RFID_H

// --- Conexión Módulo RFID --- //
//RST          D9
//SDA(SS)      D10
//MOSI         D11
//MISO         D12
//SCK          D13

#include <SPI.h>
#include <MFRC522.h>

// --- Conexionado físico --- //
#define RFID_RST_PIN 9
#define RFID_SDA_PIN 10

class DeR_RFID {
  public:
    DeR_RFID();
    void InicializarModuloRFID();
    bool HayTarjetaDisponible();
    byte* ObtenerCodigoTarjeta();
    bool IdentificadorLeido();
    void FinalizarLectura();
};

#endif
