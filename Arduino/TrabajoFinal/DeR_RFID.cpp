#include "DeR_RFID.h"

MFRC522 mfrc522(RFID_SDA_PIN, RFID_RST_PIN);

DeR_RFID::DeR_RFID() {
  // Constructor
}

void DeR_RFID::InicializarModuloRFID()
{
  // Inicialización SPI
  SPI.begin(); 
  // Inicialización RFID
  mfrc522.PCD_Init(); 
}

bool DeR_RFID::HayTarjetaDisponible()
{
  return mfrc522.PICC_IsNewCardPresent();
}

byte* DeR_RFID::ObtenerCodigoTarjeta()
{
  return mfrc522.uid.uidByte;
}

bool DeR_RFID::IdentificadorLeido()
{
  return mfrc522.PICC_ReadCardSerial();
}

void DeR_RFID::FinalizarLectura()
{
  mfrc522.PICC_HaltA();
}
