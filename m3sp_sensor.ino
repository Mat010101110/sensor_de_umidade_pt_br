// codigo em c++
//
#include <Adafruit_LiquidCrystal.h>
//^Bibilhoteca do lcd
int moisture = 0;
Adafruit_LiquidCrystal lcd_1(0);
//^modulos
void setup() {
  pinMode(A0, OUTPUT);//saida de energia/informaçao
  pinMode(A1, INPUT);//entrada de energia/informaçao
  lcd_1.begin(16, 2);//tamanho da tela lcd
  lcd_1.print("editavel");//nome do dispositivo/empresa
  Serial.begin(9600);
}//Ĥardware com as conexoes, sensor e lcd

void loop() {
  moisture = analogRead(A1);//pega os dados do sensor
   digitalWrite(A0, HIGH);//liga sensor
    delay(10);//pausa de 10 milisegundos
  moisture = analogRead(A1);
   // Desliga o sensor para o aumento da vida util
   digitalWrite(A0, LOW);//desliga sensor
  Serial.println(moisture);
  lcd_1.clear(); //Limpa o lcd para a atualizaçao do status
  Serial.println(moisture);
  
  if (moisture < 200) {
    lcd_1.print("Seco");
  } else if (moisture < 400) {
    lcd_1.print("Molhado");
  } else if (moisture < 600) {
    lcd_1.print("Bem Molhado");
  } else if (moisture < 800) {
    lcd_1.print("Ideal");
  } else {
    lcd_1.print("Enxarcado");
  }
  //escreve o perfil de umidade do solo
  delay(1000);//pausa de 1000 milisegundos
}
