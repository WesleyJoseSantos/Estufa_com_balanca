//*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : Celula_de_Carga.h
//   Descrição  : Funções para a leitura da balança da estufa
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "HX711.h"
#include "Timer.h"
#include "Pls.h"
#include "Controle_Estufa.h"

#ifndef Celula_de_Carga_h
#define Celula_de_Carga_h
    
#define PIN_DT A0
#define PIN_SCK A1
#define TIMER_LEITURAS 500

float fator_de_calibracao = 34730;

HX711 balanca;
Timer intervalo_leituras = Timer(TIMER_LEITURAS);
Pls pulso_ajuste;

int balanca_peso = 0;

void balanca_configura()
{
    //balanca.begin(PIN_DT, PIN_SCK);
    //balanca.set_scale(fator_de_calibracao);
    //balanca.tare();
}

void balanca_leitura()
{
    balanca_peso = /*balanca.get_units()*/200.5 - ajuste_balanca;
}

void balanca_ajuste(bool pulso, bool direcao)
{
    if(pulso_ajuste.pls(pulso))
    {
        direcao ? ajuste_balanca++ : ajuste_balanca--;
    }
}

#endif

