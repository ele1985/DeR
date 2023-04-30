#include "DeR_Bluetooth.h"

SoftwareSerial HM10(HM10_RX_PIN, HM10_TX_PIN);

DeR_Bluetooth::DeR_Bluetooth() {
  // Constructor
}

void DeR_Bluetooth::InicializarBluetooth() {
  // Iniciar comunicación serie con el HM-10
  HM10.begin(9600); 
}

bool DeR_Bluetooth::BluetoothConectado(){
  // Verificar si hay información disponible en el buffer
  return HM10.available();  
}

char DeR_Bluetooth::LeerCaracter(){
  // Leer caracter hasta el fin de línea. La app envía el fin de línea.
  String respuesta = HM10.readStringUntil('\n'); 
  // Sólo tomar el primer caracter que envía la app y descartar el resto.
  return respuesta.charAt(0);  
}
