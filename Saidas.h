//*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : Termocontrole.h
//   Descrição  : Funções para controle da resistência e do cooler
//   Data       : 29/05/2019
//*************************************************************************************************/

#ifndef Saidas_h
#define Saidas_h

#define PIN_RESISTENCIA 5
#define PIN_COOLER 5

void saidas_configura()
{
    pinMode(PIN_RESISTENCIA, OUTPUT);
    pinMode(PIN_COOLER, OUTPUT);
}

void resistencia_liga()
{
    digitalWrite(PIN_RESISTENCIA, HIGH);
}

void resistencia_desliga()
{
    digitalWrite(PIN_RESISTENCIA, LOW);
}

#endif