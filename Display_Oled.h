//*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : display_oled_Oled.h
//   Descrição  : Funções para controle do display_oled Oled
//   Data       : 29/05/2019
//*************************************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Celula_de_Carga.h"
#include "Sensor_DHT22.h"
#include "Controle_Estufa.h"
#include "Timer.h"
#include "ConversorInteligente.h"

#ifndef Display_Oled_h
#define Display_Oled_h

#define OLED_RESET A3
Adafruit_SSD1306 display_oled(OLED_RESET);

IntToStr s_peso(&balanca_peso);
IntToStr s_tempAtual(&dht_temperatura);
IntToStr s_tempDesej(&temperatura_desejada);
IntToStr s_humidade(&dht_umidade);
IntToStr s_horaAtual(&tempo_funcionamento);
IntToStr s_horaDesej(&tempo_desejado);
IntToStr s_ajusteBalanca(&ajuste_balanca);

enum telas
{
    tela_monitoramento,
    tela_temperatura,
    tela_tempo,
    tela_peso
};

int tela_selecionada = tela_monitoramento;

void display_escreve(String texto, int pos_x, int pos_y)
{
    display_oled.setCursor(pos_x, pos_y);
    display_oled.print(texto);
    display_oled.display();
    //delay(100);
}

void menu_tela_monitoramento()
{
    display_oled.clearDisplay();
    display_escreve(s_tempAtual.getStr() + "C", 2, 2);
    display_escreve("->", 55, 2);
    display_escreve(s_tempDesej.getStr() + "C", 80, 2);
    display_escreve(s_horaAtual.getStr() + "H", 2, 23);
    display_escreve("->", 55, 23);
    display_escreve(s_horaDesej.getStr() + "H", 80, 23);
    display_escreve(s_peso.getStr() + "g", 2, 47);
    display_escreve(s_humidade.getStr() + "%", 90, 47);
}

void display_configura()
{
    Wire.begin();
    display_oled.begin(SSD1306_SWITCHCAPVCC, 0x3D);
    display_oled.setTextColor(WHITE);
    display_oled.setTextSize(2);
    display_oled.clearDisplay();
    menu_tela_monitoramento();
}

void menu_selecao_temperatura()
{
    display_oled.clearDisplay();
    display_escreve("Temp:", 35, 10);
    display_escreve(s_tempDesej.getStr() + "C", 40, 35);
}

void menu_selecao_tempo()
{
    display_oled.clearDisplay();
    display_escreve("Timer:", 30, 10);
    display_escreve(s_horaDesej.getStr() + "h", 45, 35);
}

void menu_ajuste_balanca()
{
    display_oled.clearDisplay();
    display_escreve("Balanca:", 20, 10);
    display_escreve(s_ajusteBalanca.getStr() + "g", 40, 35);
}

void seleciona_tela(int tela)
{
    switch(tela)
    {
      case tela_monitoramento:
        menu_tela_monitoramento();
        break;
      case tela_temperatura:
        menu_selecao_temperatura();
        break;
      case tela_tempo:
        menu_selecao_tempo();
        break;
      case tela_peso:
        menu_ajuste_balanca();
        break;
      default:
        menu_tela_monitoramento();
        break;
    }
}

#endif