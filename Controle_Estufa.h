//*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : Controle_Estufa.h
//   Descrição  : Funções para controle de temperatura da estufa
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "Saidas.h"
#include "Sensor_DHT22.h"
#include "Timer.h"

#ifndef Controle_Estufa_h
#define Controle_Estufa_h

int temperatura_desejada = 35;
int tempo_desejado = 0;
int tempo_funcionamento = 0;
int ajuste_balanca = 0;

TimerLong timerEstufa;

bool percent_maior()
{
    int diferenca = temperatura_desejada - dht_temperatura;
    float percent = temperatura_desejada * (5/100);
    return(diferenca > percent);
}

bool percent_menor()
{
    int diferenca = temperatura_desejada - dht_temperatura;
    float percent = temperatura_desejada * (5/100);
    return(diferenca < -percent);
}

void controle_temperatura()
{
    if(percent_maior())
    {
        resistencia_liga();
    }
    if(percent_menor())
    {
        resistencia_desliga();
    }
}

void controle_estufa()
{
    if(tempo_desejado > 0)
    {
        if(!timerEstufa.tick())
        {
            tempo_funcionamento = timerEstufa.getTime();
            controle_temperatura();
        }
        else
        {
            resistencia_desliga();
            tempo_desejado = 0;
            timerEstufa.setInterval(0);
            timerEstufa.reset();
        }
    }
    else
    {
        timerEstufa.reset();
    }
}

void ajusta_tempo(int tempo)
{
    timerEstufa.setInterval(tempo);
}

#endif