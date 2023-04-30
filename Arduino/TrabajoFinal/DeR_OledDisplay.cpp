#include "DeR_OledDisplay.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);

DeR_OledDisplay::DeR_OledDisplay() {
  // Constructor
}

void DeR_OledDisplay::MostrarMensaje(String mensaje)
{
  u8g.firstPage();  
  do {
    Dibujar(mensaje);
  } while( u8g.nextPage() );  
}

void DeR_OledDisplay::MostrarFlechaArriba()
{
  u8g.firstPage();  
  do {
    DibujarFlechaArriba();
  } while( u8g.nextPage() );  
}

void DeR_OledDisplay::MostrarFlechaAbajo()
{
  u8g.firstPage();  
  do {
    DibujarFlechaAbajo();
  } while( u8g.nextPage() );  
}

void DeR_OledDisplay::MostrarFlechaDerecha()
{
  u8g.firstPage();  
  do {
    DibujarFlechaDerecha();
  } while( u8g.nextPage() );  
}

void DeR_OledDisplay::MostrarFlechaIzquierda()
{
  u8g.firstPage();  
  do {
    DibujarFlechaIzquierda();
  } while( u8g.nextPage() );  
}

void DeR_OledDisplay::MostrarPantallaInicio()
{
  u8g.firstPage();  
  do {
    PantallaInicio();
  } while( u8g.nextPage() );  
}

void DeR_OledDisplay::MostrarCaracter(char caracter)
{
  u8g.firstPage();  
  do {
    DibujarCaracter(caracter);
  } while( u8g.nextPage() );  
}

// --- Métodos privados --- //

// La librería provee las siguientes funciones que se utilizaron:
// drawTriangle(x1,y1,x2,y2,x3,y3): Dibuja triángulo con vértices X1(x1,y1), X2(x2,y2), X3(x3,y3) 
// drawBox(x, y, width, height): Dibuja un rectángulo con posición en (x,y), ancho(width), alto(height)
// drawFrame(x, y, width, height): Dibuja el contorno de un rectángulo con posición en (x,y), ancho(width), alto(height)

void DeR_OledDisplay::DibujarFlechaArriba() {
  u8g.drawTriangle(64, 5, 54, 20, 74, 20); // Dibuja el triángulo
  u8g.drawBox(59, 20, 10, 20); // Dibuja el rectángulo
}

void DeR_OledDisplay::DibujarFlechaAbajo() {
  u8g.drawTriangle(64, 48, 54, 33, 74, 33); // Dibuja el triángulo  
  u8g.drawBox(59, 13, 10, 20); // Dibuja el rectángulo
}

void DeR_OledDisplay::DibujarFlechaDerecha() {
  u8g.drawTriangle(30, 36, 40, 26, 40, 46); // Dibuja un triángulo que forma la flecha
  u8g.drawBox(40, 32, 20, 10); // Dibuja un rectángulo
}

void DeR_OledDisplay::DibujarFlechaIzquierda() {
  u8g.drawTriangle(74, 26, 74, 46, 84, 37); // Dibuja el triángulo
  u8g.drawBox(54, 32, 20, 10); // Dibuja el rectángulo  
}

void DeR_OledDisplay::PantallaInicio() {
  u8g.drawFrame(10, 5, 10, 10); //cara rectangular
  u8g.drawBox(12, 7, 2, 2); //ojo izquierdo
  u8g.drawBox(16, 7, 2, 2); //ojo derecho
  u8g.drawBox(8, 3, 1, 5); //antena izquierda
  u8g.drawBox(21, 3, 1, 5); //antena derecha
  u8g.drawFrame(7, 16, 15, 25); //cuerpo rectangular
  u8g.drawFrame(7, 41, 5, 12); //pierna izquierda
  u8g.drawFrame(17, 41, 5, 12); //pierna derecha
  u8g.drawFrame(2, 16, 5, 20); //brazo izquierdo
  u8g.drawFrame(22, 16, 5, 20); //brazo derecho

  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(40, 20); 
  u8g.print("DIPLOMATURA");

  u8g.setPrintPos(70, 35); 
  u8g.print("EN");

  u8g.setPrintPos(50, 50); 
  u8g.print("ROBOTICA");
}

void DeR_OledDisplay::Dibujar(String mensaje) {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 20); 
  u8g.print(mensaje);
}

void DeR_OledDisplay::DibujarCaracter(char caracter) {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 20); 
  u8g.print(caracter);
}
