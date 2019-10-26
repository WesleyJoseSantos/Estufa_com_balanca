//*************************************************************************************************/
//   Projeto    : Exemplo Display Oled I2C
//   Arquivo    : Exemplo_Display_Oled_I2C.ino
//   Descri��o  : Configura��es e loop principal
//   Data       : 29/05/2019
//*************************************************************************************************/

#include <Wire.h> //INCLUS�O DE BIBLIOTECA
#include <Adafruit_GFX.h> //INCLUS�O DE BIBLIOTECA
#include <Adafruit_SSD1306.h> //INCLUS�O DE BIBLIOTECA

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup(){
    //Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
    display.begin(SSD1306_SWITCHCAPVCC, 0x3D); //INICIALIZA O DISPLAY COM ENDERE�O I2C 0x3C
    display.setTextColor(WHITE); //DEFINE A COR DO TEXTO
    display.setTextSize(1); //DEFINE O TAMANHO DA FONTE DO TEXTO
    display.clearDisplay(); //LIMPA AS INFORMA��ES DO DISPLAY
    
}
void loop() {
    display.setCursor(10,10); //POSI��O EM QUE O CURSOR IR� FAZER A ESCRITA
    display.print("A MasterWalker Shop"); //ESCREVE O TEXTO NO DISPLAY
    display.display(); //EFETIVA A ESCRITA NO DISPLAY
    delay(200); //INTERVALO DE 1,5 SEGUNDOS
    display.clearDisplay(); //LIMPA AS INFORMA��ES DO DISPLAY
    display.setCursor(32,10); //POSI��O EM QUE O CURSOR IR� FAZER A ESCRITA
    display.print("se preocupa"); //ESCREVE O TEXTO NO DISPLAY
    display.display(); //EFETIVA A ESCRITA NO DISPLAY
    delay(200); //INTERVALO DE 1,5 SEGUNDOS
    display.clearDisplay(); //LIMPA AS INFORMA��ES DO DISPLAY
    display.setCursor(37,10); //POSI��O EM QUE O CURSOR IR� FAZER A ESCRITA
    display.print("com o seu"); //ESCREVE O TEXTO NO DISPLAY
    display.display(); //EFETIVA A ESCRITA NO DISPLAY
    delay(200); //INTERVALO DE 1,5 SEGUNDOS
    display.clearDisplay(); //LIMPA AS INFORMA��ES DO DISPLAY
    display.setCursor(32,10); //POSI��O EM QUE O CURSOR IR� FAZER A ESCRITA
    display.print("aprendizado!"); //ESCREVE O TEXTO NO DISPLAY
    display.display(); //EFETIVA A ESCRITA NO DISPLAY
    delay(200); //INTERVALO DE 1,5 SEGUNDOS
    display.clearDisplay(); //LIMPA AS INFORMA��ES DO DISPLAY
}