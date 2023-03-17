// LiquidCrystal - Version: Latest 
#include <LiquidCrystal.h>

/*Define pins for rain sensor*/
//Definiçao pino Sensor de Chuva
#define pinRainsensor A0

//Definition for limit switches
// Definiçao dos Sensores de Fim de Curso
#define switchCursor 3
#define switchCursor2 4

//Variables To Allocate the limit switches Sensor logic values
//Variaveis Para Alocar os valores logicos do Sensor de fim de Curso
int valorCursor;
int valorCursor2;

//Variable for reading the Rain Sensor value
//Variavel para leitura do valor do Sensor de Chuva
int valorSensor;

//Pin for motor clothesline
// Pino Motor Varal 
#define pinMot 10 


/*Set Velocity for motors*/
/*Velocidade para os motores*/
#define velocidade 11


//Functions declaration
void exporVaral();
void retrairVaral();

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){

    Serial.begin(9600);
    
    lcd.begin(16, 2);

     /*Set pins for limit switches*/   
    //Set dos pinos do fim de curso
    pinMode(switchCursor, INPUT_PULLUP);
    pinMode(switchCursor2, INPUT_PULLUP);
  
  //the motor pins to release energy
  // Deixando os pinos dos motores para soltarem energia
    pinMode(pinMot, OUTPUT);

}

void loop(){
// LCD Code
  lcd.clear();

  lcd.setCursor(3, 0);
  lcd.print("Varal automatico");
  delay(5000);

  lcd.setCursor(3, 1);
  lcd.print(" Automatic Clothesline");
  delay(5000);

  
  valorSensor = analogRead(pinRainsensor);
  valorCursor = digitalRead(switchCursor);
  valorCursor2 = digitalRead(switchCursor2);

  //Conditional to retract the clothesline
  // Condicional para retrair o varal
  if ((valorSensor < 800) && (valorCursor == 1) ){

    exporVaral();
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Expondo Varal!!!");
    delay(10000);
    valorSensor = analogRead(pinRainsensor);
    valorCursor = digitalRead(switchCursor);
  }
  
  // Conditional to expose the clothesline to the sun
  // Condicional para expor o varal ao sol
 if ((valorSensor > 800) && (valorCursor2 == 1)){
    
    retrairVaral(); 
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Retraindo Varal!!!");
    delay(10000);
    valorCursor2 = digitalRead(switchCursor2);
    valorSensor = analogRead(pinRainsensor);
  
    }else{

    digitalWrite(pinMot, LOW);



    }
}

/*Motor Supervision and  Activation from website*/
/*Supervisionamento dos Motores e site e ativaçâo*/
void exporVaral(){
  
  digitalWrite(pinMot, HIGH);
  valorSensor = analogRead(pinRainsensor);
  valorCursor = digitalRead(switchCursor);

  
} 

void retrairVaral(){
  
  
  digitalWrite(pinMot, LOW);
  valorCursor2 = digitalRead(switchCursor2);
  valorSensor = analogRead(pinRainsensor);
  
  
}