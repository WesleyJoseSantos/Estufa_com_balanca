//*************************************************************************************************/
//   Projeto    : HX711 Celula de Carga
//   Arquivo    : Calibracao.h
//   Descri��o  : Fun��es utilizadas para calibrar a c�lula
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "HX711.h"

#define DOUT A0                    
#define CLK A1

HX711 peso;                // instancia Balan�a HX711

float calibration_factor = 34730;     // fator de calibra��o para teste inicial

void setup()
{
  Serial.begin(9600);  
  peso.begin(DOUT, CLK);      // inicializa a balan�a                                            
  Serial.println();                                                
  Serial.println("Calibracao da Balan�a");                 
  peso.set_scale();                                // configura a escala da Balan�a            
  zerapeso();                                    // zera a Balan�a             
}

void zerapeso()
{
  Serial.println();                                             
  peso.tare();                                                 // zera a Balan�a
  Serial.println("Zerando a Balan�a ");
}

void calib()
{
  peso.set_scale(calibration_factor);            // ajusta fator de calibra��o
  Serial.print("Peso: ");                       // imprime no monitor serial
  Serial.print(peso.get_units(), 3);           // imprime peso da balan�a com 3 casas decimais
  Serial.print(" kg");
  Serial.print("      Fator de Calibra��o: ");               // imprime no monitor serial
  Serial.println(calibration_factor);                        // imprime fator de calibra��o
  delay(500) ;                                               
  if (Serial.available())             // reconhece letra para ajuste do fator de calibra��o
  {
    char temp = Serial.read();
    if (temp == '+' || temp == 'a')                // a = aumenta 10
      calibration_factor += 10;
    else if (temp == '-' || temp == 'z')           // z = diminui 10
      calibration_factor -= 10;
    else if (temp == 's')                          // s = aumenta 100
      calibration_factor += 100;
    else if (temp == 'x')                          // x = diminui 100
      calibration_factor -= 100;
    else if (temp == 'd')                          // d = aumenta 1000
      calibration_factor += 1000;
    else if (temp == 'c')                          // c = diminui 1000
      calibration_factor -= 1000;
    else if (temp == 'f')                          // f = aumenta 10000
      calibration_factor += 10000;
    else if (temp == 'v')                          // v = dimuni 10000
      calibration_factor -= 10000;
    else if (temp == 't') zerapeso ();             // t = zera a Balan�a
  }
}