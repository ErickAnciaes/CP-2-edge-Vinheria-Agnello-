#include <LiquidCrystal.h>

// Inicialização do LCD
LiquidCrystal lcd(12, 11, 10, 6, 5, 3, 2);

// Definição dos pinos
int LedVERDE = 7;
int LedAMARELO = 8;
int LedVERMELHO = 9;

int buzzer = 4;

int SensorLDR = A0;
int sensorUmidade = A1;
int sensorTemperatura = A2;

// Funções auxiliares
void desligaTodosLEDs() {
  digitalWrite(LedVERDE, LOW);
  digitalWrite(LedAMARELO, LOW);
  digitalWrite(LedVERMELHO, LOW);
}

void limpaLCD() {
  delay(2000); 
  lcd.clear();
}

void setup() {
  Serial.begin(9600);

  pinMode(LedVERDE, OUTPUT);
  pinMode(LedAMARELO, OUTPUT);
  pinMode(LedVERMELHO, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(SensorLDR, INPUT);
  pinMode(sensorUmidade, INPUT);
  pinMode(sensorTemperatura, INPUT);

  lcd.begin(16, 2);
}

void loop() {
  // Leitura dos sensores
  int valorSensorLDR = analogRead(SensorLDR);
  float umidade = analogRead(sensorUmidade);
  int leituraTemp = analogRead(sensorTemperatura);
  float temperatura = (leituraTemp * (5000.0 / 1024.0) - 500) / 10.0;

  Serial.print("Luminosidade: ");
  Serial.println(valorSensorLDR);
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println("ºC");
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println("%");


  // Verifica iluminação e acende LED correspondente

  desligaTodosLEDs(); 
  noTone(buzzer);

  if (valorSensorLDR < 80) {
    digitalWrite(LedVERDE, HIGH);
  } else if (valorSensorLDR <= 220) {
    digitalWrite(LedAMARELO, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente meia");
    lcd.setCursor(0, 1);
    lcd.print("luz!");
    limpaLCD();
  } else {
    digitalWrite(LedVERMELHO, HIGH);
    tone(buzzer, 1000);
    lcd.setCursor(0, 0);
    lcd.print("Ambiente muito");
    lcd.setCursor(0, 1);
    lcd.print("claro!");
    limpaLCD();
  }

  delay(1000);


  // Verifica temperatura 

  noTone(buzzer);  

  if (temperatura < 10) {
    tone(buzzer, 1000);
    lcd.setCursor(0, 0);
    lcd.print("Temp. baixa!");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print("C");
    limpaLCD();
  } else if (temperatura <= 15) {
    lcd.setCursor(0, 0);
    lcd.print("Temp. ok");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print("C");
    limpaLCD();
  } else {
    tone(buzzer, 1000);
    lcd.setCursor(0, 0);
    lcd.print("Temp. alta!");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperatura);
    lcd.print("C");
    limpaLCD();
  }

  delay(1000);


  // Verifica umidade (sem desligar LEDs da luz)
 
  noTone(buzzer);

  if (umidade < 50) {
    tone(buzzer, 1000);
    lcd.setCursor(0, 0);
    lcd.print("Umidade baixa!");
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade);
    lcd.print("%");
    limpaLCD();
  } else if (umidade <= 70) {
    lcd.setCursor(0, 0);
    lcd.print("Umidade ok");
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade);
    lcd.print("%");
    limpaLCD();
  } else {
    tone(buzzer, 1000);
    lcd.setCursor(0, 0);
    lcd.print("Umidade alta!");
    lcd.setCursor(0, 1);
    lcd.print("Umid: ");
    lcd.print(umidade);
    lcd.print("%");
    limpaLCD();
  }

  delay(1000);
}