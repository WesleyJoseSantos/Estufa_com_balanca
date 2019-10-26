//*************************************************************************************************/
//   Projeto    : HX711 Celula de Carga
//   Arquivo    : HX711_Celula_de_Carga.ino
//   Descri��o  : Configura��es e loop principal
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "HX711.h"

#define DOUT A0
#define CLK  A1

HX711 bau;             // instancia Balan�a HX711

float calibration_factor = 34730;     // fator de calibra��o aferido na Calibra��o 

void setup()
{
    Serial.begin(9600); 
    bau.begin(DOUT, CLK);                          // inicializa a balan�a
    bau.set_scale(calibration_factor);             // ajusta fator de calibra��o
    bau.tare();                                    // zera a Balan�a
}

void loop()
{
    Serial.print("Peso: ");                            
    Serial.print(bau.get_units(), 3);         // imprime peso na balan�a com duas casas decimais 
    Serial.println(" kg");                             // imprime no monitor serial 
    delay(500) ;                                       
    if (Serial.available())                            // se a serial estiver disponivel
    {
        char temp = Serial.read();                       // le carcter da serial 
        if (temp == 't' || temp == 'T')                  // se pressionar t ou T
        {
            bau.tare();                                // zera a balan�a
            Serial.println(" Balan�a zerada");             // imprime no monitor serial
        }
    }
}
