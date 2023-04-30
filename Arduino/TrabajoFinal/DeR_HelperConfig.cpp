#include "DeR_HelperConfig.h"

DeR_HelperConfig::DeR_HelperConfig() {
  // Constructor
}

//Función para comparar dos vectores
bool DeR_HelperConfig::SonVectoresIguales(byte* vectorA, const byte* vectorB, int longitud)
{
  for (int indice = 0; indice < longitud; indice++)
  {
    if (vectorA[indice] != vectorB[indice]) return false;
  }
  return true;
}
