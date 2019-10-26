    //*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : Encoder_KY_040.h
//   Descrição  : Funções para elitura do encoder rotacional
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "Pls.h"
#include "Display_Oled.h"

#define CLK 2
#define DT 3
#define SW 4

Pls pulso_encoder;
Pls pulso_botao;

enum direcao
{
    decrescimo,
    acrescimo
};

void encoder_configura()
{
    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
    pinMode(SW, INPUT_PULLUP);
}

bool encoder_pulso()
{
    bool leitura = digitalRead(CLK);
    bool pulso = pulso_encoder.pls(leitura);
    return(pulso);
    
}

bool encoder_direcao()
{
    bool dir = digitalRead(DT);
    return(dir);
}

bool encoder_botao()
{
    bool bt = !digitalRead(SW);
    bool pulso = pulso_botao.pls(bt);
    return(pulso);
}

void encoder_seleciona_telas()
{
    if(encoder_botao())
    {
        tela_selecionada++;
        if(tela_selecionada > tela_peso)
        {
            tela_selecionada = tela_monitoramento;
        }
    }
    seleciona_tela(tela_selecionada);
}

void incremento(int *var, int valor, int sentido)
{
    if(sentido == acrescimo)
    {
        *var += valor;
    }
    else if(*var - valor >= 0)
    {
        *var -= valor;
    }
}

void encoder_ajusta_temperatura()
{
    if(tela_selecionada == tela_temperatura)
    {
        if(encoder_pulso())
        {
            incremento(&temperatura_desejada, 1, encoder_direcao());
        }
    }
}

void encoder_ajusta_tempo()
{
    if(tela_selecionada == tela_tempo)
    {
        if(encoder_pulso())
        {
            incremento(&tempo_desejado, 1, encoder_direcao());
            ajusta_tempo(tempo_desejado);
        }
    }
}

void encoder_ajusta_balanca()
{
    if(tela_selecionada == tela_peso)
    {
        if(encoder_pulso())
        {
            incremento(&ajuste_balanca, 5, encoder_direcao());
        }
    }
}

void controle_encoder()
{
    encoder_seleciona_telas();
    encoder_ajusta_temperatura();
    encoder_ajusta_tempo();
    encoder_ajusta_balanca();
}