//*************************************************************************************************/
//   Projeto    : Estufa com balanca
//   Arquivo    : Sensor_DHT22.h
//   Descrição  : Funções para a leitura do sensor DHT22
//   Data       : 29/05/2019
//*************************************************************************************************/

#include "Timer.h"
#include "DHT.h"

#ifndef Sensor_DHT22_h
#define Sensor_DHT22_h

#define DHT_TYPE DHT22
#define PIN_DHT A2

DHT sensor_dht = DHT(PIN_DHT, DHT_TYPE);
Timer amostragem_dht = Timer(500);

int dht_temperatura = 0;
int dht_umidade = 0;

void dht_configura()
{
    sensor_dht.begin();
}

void dht_leitura()
{
    if(amostragem_dht.tick())
    {
        dht_temperatura = sensor_dht.readTemperature();
        dht_umidade     = sensor_dht.readHumidity();
        amostragem_dht.reset();
    }
}

#endif
