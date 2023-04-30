#include "DeR_Buzzer.h"

int melodiaMarioInicio[] = {
  // Mario Inicio:
  NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8,
  NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
};

int melodiaMarioFinal[] = {
  // Mario Cancion Bandera:
  NOTE_C5,8, NOTE_E5,8, NOTE_G5,8, NOTE_C6,8, NOTE_E6,8, NOTE_G6,4, NOTE_E6,8, REST,8,
  NOTE_C5,8, NOTE_DS5,8, NOTE_GS5,8, NOTE_C6,8, NOTE_DS6,8, NOTE_GS6,4, NOTE_DS6,8, REST,8,
  NOTE_D5,8, NOTE_F5,8, NOTE_AS5,8, NOTE_DS6,8, NOTE_F6,8, NOTE_AS6,4, REST,8,
  NOTE_AS6,8, NOTE_AS6,8, NOTE_AS6,8, NOTE_C7,4, REST,4,
};

// Esta variable se puede cambiar para que la melodía sea más lenta o más rápida
int tempo = 200;

// Esta variable calcula la duración de una nota completa en milisegundos
int notaCompleta = (60000 * 4) / tempo;

// sizeof devuelve el numero de bytes, cada variable de tipo int se compone de 2 bytes (16 bits)
// hay 2 valores por nota (tono y duración), asi que por cada nota hay 4 bytes
int notasMarioInicio = sizeof(melodiaMarioInicio) / sizeof(melodiaMarioInicio[0]) / 2;

int notasMarioFinal = sizeof(melodiaMarioFinal) / sizeof(melodiaMarioFinal[0]) / 2;

int divisor = 0, duracionNota = 0;


DeR_Buzzer::DeR_Buzzer() {
  // Constructor
}

void DeR_Buzzer::InicializarBuzzer()
{
  pinMode(BUZZER_PIN, OUTPUT); 
}

void DeR_Buzzer::SonidoNuevaTarjetaCargada()
{
  Beep(100);
}

void DeR_Buzzer::SonidoInicioEjecucionSecuencia() {
  EjecutarMelodia(MELODIA_MARIO_INICIO);
}

void DeR_Buzzer::SonidoFinEjecucionSecuencia() {
  EjecutarMelodia(MELODIA_MARIO_FINAL);
}

// --- Métodos privados --- //

void DeR_Buzzer::Beep(byte pausa) {
  analogWrite(BUZZER_PIN,20);
  delay(pausa);
  analogWrite(BUZZER_PIN,0);
  delay(2*pausa);
}

void DeR_Buzzer::EjecutarMelodia(int melodiaSeleccionada) {
  int notas = 0;
  int *melodia;
  
  switch(melodiaSeleccionada)
  {
    case MELODIA_MARIO_INICIO: notas = notasMarioInicio; melodia = melodiaMarioInicio; break;
    case MELODIA_MARIO_FINAL: notas = notasMarioFinal; melodia = melodiaMarioFinal; break;
  }
  
  // itera sobre las notas de la melodía.
  // Recordar que el arreglo es el doble de la cantidad de notas (tonos + duraciones)
  for (int notaActual = 0; notaActual < notas * 2; notaActual = notaActual + 2) {

    // calcula la duración de cada nota
    divisor = melodia[notaActual + 1];
    if (divisor > 0) {
      // nota normal
      duracionNota = (notaCompleta) / divisor;
    } else if (divisor < 0) {
      // notas con punto representadas con valores negativos
      duracionNota = (notaCompleta) / abs(divisor);
      duracionNota *= 1.5; // incrementa un 50% la duración de las notas con punto.
    }

    // se reproduce solo un 90% de la duración de la nota dejando un 10% como pausa.
    tone(BUZZER_PIN, melodia[notaActual], duracionNota * 0.9);

    // Se espera la duración de la nota como pausa antes de reproducir la próxima nota.
    delay(duracionNota);

    // se frena la generación de onda antes de la próxima nota.
    noTone(BUZZER_PIN);
  }
}
