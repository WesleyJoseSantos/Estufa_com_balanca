//*************************************************************************************************/
//   Projeto    : Leitura Sensor DHT22
//   Arquivo    : Leitura_Sensor_DHT22.ino
//   Descri��o  : Configura��es e loop principal
//   Data       : 29/05/2019
//*************************************************************************************************/

#include <dht.h> // Inclui a biblioteca no seu c�digo
 
dht DHT; // Cria um objeto da classe dht
uint32_t timer = 0;
 
void setup()
{
  Serial.begin(9600); // Inicializa serial com taxa de transmiss�o de 9600 bauds
}
 
void loop()
{
  // Executa 1 vez a cada 2 segundos
  if(millis() - timer>= 2000)
  {
 
    DHT.read11(A1); // chama m�todo de leitura da classe dht,
                    // com o pino de transmiss�o de dados ligado no pino A1
 
    // Exibe na serial o valor de umidade
    Serial.print(DHT.humidity);
    Serial.println(" %");
 
    // Exibe na serial o valor da temperatura
    Serial.print(DHT.temperature);
    Serial.println(" Celsius");
 
    timer = millis(); // Atualiza a refer�ncia
  }
}