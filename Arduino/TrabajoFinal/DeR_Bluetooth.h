#ifndef DER_BLUETOOTH_H
#define DER_BLUETOOTH_HSE_H

// --- Librería Módulo HM-10 --- //
#include <SoftwareSerial.h>
#include <Arduino.h>

// --- Conexionado físico --- //
#define HM10_TX_PIN 1
#define HM10_RX_PIN 0
#define HM10_STATE_PIN 3

class DeR_Bluetooth {
  public:
    DeR_Bluetooth();
    void InicializarBluetooth();
    bool BluetoothConectado();
    char LeerCaracter();
};

#endif
