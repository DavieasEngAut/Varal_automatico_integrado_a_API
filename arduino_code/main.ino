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

//Pins for motor clothesline 1
// Pinos Motor Varal 1
#define pinMot1A 10 
#define pinMot1B 9

//Pins for motor clothesline 2
// Pinos Motor Varal 2
#define pinMot2A 5
#define pinMot2B 6

/*Set Velocity for motors*/
/*Velocidade para os motores*/
#define velocidade 11

void setup(){

    Serial.begin(9600);

     /*Set pins for limit switches*/   
    //Set dos pinos do fim de curso
    pinMode(switchCursor, INPUT_PULLUP);
    pinMode(switchCursor2, INPUT_PULLUP);
  
  //the motor pins to release energy
  // Deixando os pinos dos motores para soltarem energia
    pinMode(pinMot1A, OUTPUT);
    pinMode(pinMot1B, OUTPUT);
    pinMode(pinMot2A, OUTPUT);
    pinMode(pinMot2B, OUTPUT);

     /*Define pin for velocity*/ 
    /*Definiçao pino de velocidade*/
    pinMode(velocidade, OUTPUT);


}

void loop(){

//reading of the limit switches Sensor values
// leitura dos valores do Sensor de Fim de curso
    valorCursor = digitalRead(switchCursor);
    valorCursor2 = digitalRead(switchCursor2);

//Reading rain sensor values 
// leitura dos Valores sensor de chuva 
    valorSensor = analogRead(pinRainsensor);
    valorSensor = map(pinRainsensor, 0, 1023, 0, 1000);

/*
Showing sensor values in real time in serial
*/
/*Mostrando os valores do sensor no Serial do arduino*/
    Serial.print(valorSensor);
    delay(100);

    Serial.println("Valor Fim de Curso 1");
    Serial.print(valorCursor);
    delay(500);

    Serial.println("Valor Fim de Curso 1");
    Serial.print(valorCursor2);
    delay(500);


    //Print of Rain Sensor Value
   //Print do Valor do sensor de Chuva
    Serial.print(valorSensor);


  /*Motor Supervision and Activation*/
  /*Supervisionamento dos Motores e ativaçâo*/


  //Conditional to retract the clothesline
  // Condicional para retrair o varal
  if ((valorSensor < 800) && (valorCursor == 1) ){

    digitalWrite(pinMot1A, HIGH);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, HIGH);
    digitalWrite(pinMot2B, LOW);
    valorSensor = analogRead(pinRainsensor);
    valorCursor = digitalRead(switchCursor);

  }else{

    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);



  }
  
  // Conditional to expose the clothesline to the sun
  // Condicional para expor o varal ao sol
 if ((valorSensor > 800) && (valorCursor2 == 1)){
    
    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, HIGH);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, HIGH);
    valorSensor = analogRead(pinRainsensor);
    valorCursor2 = digitalRead(switchCursor2);

    }else{

    digitalWrite(pinMot1A, LOW);
    digitalWrite(pinMot1B, LOW);
    digitalWrite(pinMot2A, LOW);
    digitalWrite(pinMot2B, LOW);



    }
}