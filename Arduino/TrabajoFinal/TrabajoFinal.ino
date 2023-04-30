#include "DeR_Buzzer.h"
#include "DeR_RFID.h"
#include "DeR_OledDisplay.h"
#include "DeR_PuenteH.h"
#include "DeR_Bluetooth.h"
#include "DeR_HelperConfig.h"

DeR_Buzzer buzzer;
DeR_RFID RFID;
DeR_OledDisplay oledDisplay;
DeR_PuenteH puenteH;
DeR_Bluetooth bluetooth;
DeR_HelperConfig helperConfig;

// IMPORTANTE! Toda la configuración de la aplicación está en HelperConfig
int secuenciaProgramacion[CANTIDAD_MAX_TARJETAS];

void setup()
{
  InicializarsecuenciaProgramacion();
  InicializarComponentes();
  oledDisplay.MostrarPantallaInicio();
}

void loop()
{
  if(bluetooth.BluetoothConectado()){
    oledDisplay.MostrarMensaje("Bluetooth activado");
    CargarSecuenciaProgramacionDesdeBluetooth();
    EjecutarSecuenciaProgramacion();
    InicializarsecuenciaProgramacion();
  } 
  else if (RFID.HayTarjetaDisponible()) {
    oledDisplay.MostrarMensaje("Esperando tarjetas");
    CargarSecuenciaProgramacion();
    EjecutarSecuenciaProgramacion();
    InicializarsecuenciaProgramacion();
  }
}

void InicializarComponentes()
{
  RFID.InicializarModuloRFID();
  buzzer.InicializarBuzzer();
  puenteH.InicializarMotores();
  bluetooth.InicializarBluetooth();
}

void InicializarsecuenciaProgramacion()
{
  for(int i=0; i<CANTIDAD_MAX_TARJETAS; i++)
  {
    secuenciaProgramacion[i] = ACCION_FIN;
  }
}

//----- FUNCIONES PARA LA CARGA DE LA SECUENCIA DE PROGRAMACIÓN DESDE RFID -----//

bool EsTarjetaAdelante()
{
  return helperConfig.SonVectoresIguales(RFID.ObtenerCodigoTarjeta(), helperConfig.tarjetaAdelante, 4);
}

bool EsTarjetaAtras()
{
  return helperConfig.SonVectoresIguales(RFID.ObtenerCodigoTarjeta(), helperConfig.tarjetaAtras, 4);
}

bool EsTarjetaDerecha()
{
  return helperConfig.SonVectoresIguales(RFID.ObtenerCodigoTarjeta(), helperConfig.tarjetaDerecha, 4);
}

bool EsTarjetaIzquierda()
{
  return helperConfig.SonVectoresIguales(RFID.ObtenerCodigoTarjeta(), helperConfig.tarjetaIzquierda, 4);
}

bool EsTarjetaInicio()
{
  return helperConfig.SonVectoresIguales(RFID.ObtenerCodigoTarjeta(), helperConfig.tarjetaInicio, 4);
}

void CargarSecuenciaProgramacion()
{
  int indiceTarjeta = 0;
  bool finDeCarga = false;
  
  while(indiceTarjeta < CANTIDAD_MAX_TARJETAS && !finDeCarga){
    if (RFID.HayTarjetaDisponible())
    {
      if (RFID.IdentificadorLeido())
      {
        buzzer.SonidoNuevaTarjetaCargada();
        //Cargar tarjeta en la secuencia de programación
        //Comparar ID con las claves válidas
        if (EsTarjetaAdelante())
        {
          oledDisplay.MostrarFlechaArriba();
          secuenciaProgramacion[indiceTarjeta] = ACCION_ADELANTE;
          indiceTarjeta = indiceTarjeta + 1;
        } 
        if (EsTarjetaAtras())
        {
          oledDisplay.MostrarFlechaAbajo();
          secuenciaProgramacion[indiceTarjeta] = ACCION_ATRAS;
          indiceTarjeta = indiceTarjeta + 1;
        } 
        if (EsTarjetaDerecha())
        {
          oledDisplay.MostrarFlechaDerecha();
          secuenciaProgramacion[indiceTarjeta] = ACCION_DERECHA;
          indiceTarjeta = indiceTarjeta + 1;
        } 
        if (EsTarjetaIzquierda())
        {
          oledDisplay.MostrarFlechaIzquierda();
          secuenciaProgramacion[indiceTarjeta] = ACCION_IZQUIERDA;
          indiceTarjeta = indiceTarjeta + 1;
        } 
        if (EsTarjetaInicio())
        {
          secuenciaProgramacion[indiceTarjeta] = ACCION_FIN;
          indiceTarjeta = indiceTarjeta + 1;
          finDeCarga = true;
        }
        // Finalizar lectura actual
        RFID.FinalizarLectura();
      }
    }
    delay(250);
  }

  oledDisplay.MostrarMensaje("Iniciando...");
}

//----- FUNCIONES PARA LA CARGA DE LA SECUENCIA DE PROGRAMACIÓN DESDE BLUETOOTH -----//

bool EsCaracterAdelante(char caracter)
{
  return caracter == 'a';
}

bool EsCaracterAtras(char caracter)
{
  return caracter == 'b';
}

bool EsCaracterDerecha(char caracter)
{
  return caracter == 'c';
}

bool EsCaracterIzquierda(char caracter)
{
  return caracter == 'd';
}

bool EsCaracterInicio(char caracter)
{
  return caracter == 'z';
}

void CargarSecuenciaProgramacionDesdeBluetooth()
{
  int indiceTarjeta = 0;
  bool finDeCarga = false;
  
  while(indiceTarjeta < CANTIDAD_MAX_TARJETAS && !finDeCarga){
    
    if (bluetooth.BluetoothConectado())
    {
      char c = bluetooth.LeerCaracter();
      buzzer.SonidoNuevaTarjetaCargada();

      if (EsCaracterAdelante(c))
      {
        oledDisplay.MostrarFlechaArriba();
        secuenciaProgramacion[indiceTarjeta] = ACCION_ADELANTE;
        indiceTarjeta = indiceTarjeta + 1;
      } 
      if (EsCaracterAtras(c))
      {
        oledDisplay.MostrarFlechaAbajo();
        secuenciaProgramacion[indiceTarjeta] = ACCION_ATRAS;
        indiceTarjeta = indiceTarjeta + 1;
      } 
      if (EsCaracterDerecha(c))
      {
        oledDisplay.MostrarFlechaDerecha();
        secuenciaProgramacion[indiceTarjeta] = ACCION_DERECHA;
        indiceTarjeta = indiceTarjeta + 1;
      } 
      if (EsCaracterIzquierda(c))
      {
        oledDisplay.MostrarFlechaIzquierda();
        secuenciaProgramacion[indiceTarjeta] = ACCION_IZQUIERDA;
        indiceTarjeta = indiceTarjeta + 1;
      } 
      if (EsCaracterInicio(c))
      {
        secuenciaProgramacion[indiceTarjeta] = ACCION_FIN;
        indiceTarjeta = indiceTarjeta + 1;
        finDeCarga = true;
      }
    }
    delay(250);
  }

  oledDisplay.MostrarMensaje("Iniciando...");
}

//----- FUNCIONES PARA LA EJECUCIÓN DE LA SECUENCIA DE PROGRAMACIÓN -----//

void RobotAvanzar()
{
  oledDisplay.MostrarFlechaArriba();
  puenteH.MoverMotoresAdelante();
}

void RobotRetroceder()
{
  oledDisplay.MostrarFlechaAbajo();
  puenteH.MoverMotoresAtras();
}

void RobotGirarDerecha()
{
  oledDisplay.MostrarFlechaDerecha();
  puenteH.MoverDerecha();
}

void RobotGirarIzquierda()
{
  oledDisplay.MostrarFlechaIzquierda();
  puenteH.MoverIzquierda();
}

void EjecutarSecuenciaProgramacion()
{
  buzzer.SonidoInicioEjecucionSecuencia();
  int indiceTarjeta = 0;
  while(secuenciaProgramacion[indiceTarjeta] != ACCION_FIN && indiceTarjeta <= CANTIDAD_MAX_TARJETAS)
  {
    switch(secuenciaProgramacion[indiceTarjeta])  
    {
      case ACCION_ADELANTE: RobotAvanzar(); delay(TIEMPO_EJECUCION_MOTOR); break;
      case ACCION_ATRAS: RobotRetroceder(); delay(TIEMPO_EJECUCION_MOTOR); break;
      case ACCION_DERECHA: RobotGirarDerecha(); delay(TIEMPO_EJECUCION_MOTOR_LADOS); break;
      case ACCION_IZQUIERDA: RobotGirarIzquierda(); delay(TIEMPO_EJECUCION_MOTOR_LADOS);break;
    }
    
    puenteH.DetenerMotores();
    delay(250);
    indiceTarjeta++;
  }

  puenteH.DetenerMotores();
  oledDisplay.MostrarMensaje("FIN");
  buzzer.SonidoFinEjecucionSecuencia();
}
