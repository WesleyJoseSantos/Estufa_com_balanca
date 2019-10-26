//*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : Estufa_com_balanca.ino
//   Descrição  : Configurações e loop principal
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "Celula_de_Carga.h"
#include "Sensor_DHT22.h"
#include "Display_Oled.h"
#include "Encoder_KY_040.h"

void setup()
{
    // coloque aqui o seu código de configuração para ser executado uma vez:
    dht_configura();            //Configura e inicializa o sensor dht 
    balanca_configura();        //Configura e inicializa o módulo hx711
    encoder_configura();        //Configura e inicializa o ecoder rotativo
    display_configura();        //Configura e inicializa o display Oled
}

void loop()
{
    // coloque seu código principal aqui, para executar repetidamente:
    dht_leitura();              //Leitura do sensor dht
    balanca_leitura();          //Leitura do módulo hx711
    controle_encoder();         //Lê o encoder, e controla a tela, e parâmetros
    controle_estufa();          //Lê o sensor e o temporizador e realiza o controle da resistência
}