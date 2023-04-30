#ifndef DER_PUENTEH_H
#define DER_PUENTEH_H

#include <Arduino.h>

//Conexionado del Motor M1
#define PUENTE_H_IN1 2
#define PUENTE_H_IN2 4
#define PUENTE_H_ENA 5
//Conexionado del Motor M2
#define PUENTE_H_IN3 7
#define PUENTE_H_IN4 8
#define PUENTE_H_ENB 6

#define VELOCIDAD_MOTORES 100
#define TIEMPO_EJECUCION_MOTOR 2000
#define TIEMPO_EJECUCION_MOTOR_LADOS 1000

class DeR_PuenteH {
  public:
    DeR_PuenteH();
    void InicializarMotores();
    void MoverMotoresAdelante();
    void MoverMotoresAtras();
    void DetenerMotores();
    void MoverDerecha();
    void MoverIzquierda();
  private:
    void MoverAdelanteM1();
    void MoverAdelanteM2();
    void MoverAtrasM1();
    void MoverAtrasM2();
    void DetenerMotorM1();
    void DetenerMotorM2();
};

#endif
