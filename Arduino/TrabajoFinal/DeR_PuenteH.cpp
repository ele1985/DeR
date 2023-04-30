#include "DeR_PuenteH.h"

DeR_PuenteH::DeR_PuenteH() {
  // Constructor
}

void DeR_PuenteH::InicializarMotores()
{
  //Motor M1
  pinMode(PUENTE_H_IN1, OUTPUT);
  pinMode(PUENTE_H_IN2, OUTPUT);
  pinMode(PUENTE_H_ENA, OUTPUT);

  //Motor M2
  pinMode(PUENTE_H_IN3, OUTPUT);
  pinMode(PUENTE_H_IN4, OUTPUT);
  pinMode(PUENTE_H_ENB, OUTPUT);
}

void DeR_PuenteH::MoverMotoresAdelante()
{
  MoverAdelanteM1();
  MoverAdelanteM2();
}

void DeR_PuenteH::MoverMotoresAtras()
{
  MoverAtrasM1();
  MoverAtrasM2();
}

void DeR_PuenteH::DetenerMotores()
{
  DetenerMotorM1();
  DetenerMotorM2();
}

void DeR_PuenteH::MoverDerecha()
{
  MoverAtrasM1();
  MoverAdelanteM2();
}

void DeR_PuenteH::MoverIzquierda()
{
  MoverAtrasM2();
  MoverAdelanteM1();
}

// --- Métodos privados --- //

void DeR_PuenteH::MoverAdelanteM1()
{
  analogWrite(PUENTE_H_ENA, VELOCIDAD_MOTORES); 
  digitalWrite(PUENTE_H_IN1, LOW); 
  digitalWrite(PUENTE_H_IN2, HIGH);
}

void DeR_PuenteH::MoverAdelanteM2()
{
  analogWrite(PUENTE_H_ENB, VELOCIDAD_MOTORES); 
  digitalWrite(PUENTE_H_IN3, LOW); 
  digitalWrite(PUENTE_H_IN4, HIGH);
}

void DeR_PuenteH::MoverAtrasM1()
{
  analogWrite(PUENTE_H_ENA, VELOCIDAD_MOTORES); 
  digitalWrite(PUENTE_H_IN1, HIGH); 
  digitalWrite(PUENTE_H_IN2, LOW);
}

void DeR_PuenteH::MoverAtrasM2()
{
  analogWrite(PUENTE_H_ENB, VELOCIDAD_MOTORES); 
  digitalWrite(PUENTE_H_IN3, HIGH); 
  digitalWrite(PUENTE_H_IN4, LOW);
}

void DeR_PuenteH::DetenerMotorM1()
{
  analogWrite(PUENTE_H_ENA, 0); 
}

void DeR_PuenteH::DetenerMotorM2()
{
  analogWrite(PUENTE_H_ENB, 0); 
}
