#include <SoftwareSerial.h>//Biblioteca utilizada para módulo Bluetooth
#include <AFMotor.h>//Biblioteca utilizada para os motores

SoftwareSerial bluetooth(1, 0); //Define as portas RX e TX do módulo Bluetooth

AF_DCMotor motor1(2); //Define que entrada 4 é o motor1
AF_DCMotor motor2(1); //Define que entrada 3 é o motor2

char command;//variável comando 

int ledPin = 13; //Define que o pin 13 é igual a ledPin

void setup() 
{ 
  pinMode(ledPin, OUTPUT);//Define que ledPin é OUTPUT 

  digitalWrite(ledPin, LOW); //Define o LedPin para Low 

  Serial.begin(9600);//Define a veloidade de transferência de dados entre o Arduino e o computador

   bluetooth.begin(9600);//Define a velocidade de transferência de dados entre o Arduino e o módulo Bluetooth
}

void loop()
{
  while(bluetooth.available() > 0)//enquanto o Bluetooth estiver disponível 
  {

    command = bluetooth.read(); //vai ler o comando enviado por Bluetooth
    
  
  if(command == 'f')//se o comando for "f"
{
  motor1.setSpeed(200); //Define a velocidade máxima (255)
  motor1.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
  motor2.setSpeed(200); //Define a velocidade máxima 
  motor2.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
}

else if (command == 'b')//se o comando for "b"
{
  motor1.setSpeed(200); //Define a velocidade máxima 
  motor1.run(BACKWARD); //Roda no sentido contrário ao ponteiro do relógio
  motor2.setSpeed(200); //Define a velocidade máxima
  motor2.run(BACKWARD); //Roda no sentido contrário ao ponteiro do relógio
}

else if(command == 'l')//se o comando for "l"
{
  motor1.setSpeed(200); //Define a velocidade máxima 
  motor1.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
  motor2.setSpeed(100);//Define a velocidade máxima
  motor2.run(FORWARD); //Desliga o motor2
}

else if (command == 'r')//se o comando for "r"
{
  motor1.setSpeed(100);//Define a velocidade máxima
  motor1.run(FORWARD); //Desliga o motor1
  motor2.setSpeed(200); //Define a velocidade máxima
  motor2.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
}

    else if (command == '1')//se o comando for "1"
    {

      digitalWrite(ledPin, HIGH); //Define o ledPin como HIGH
      bluetooth.println("LED ligado"); //Manda a mensagem para a aplicação

    } 
    else if (command == '0') //se o comando for "0"
    {

      digitalWrite(ledPin, LOW);//Define o ledPin como Low 
      

    }

    else if (command == 's')//se o comando for "s"
    {

        Stop();//chama a função Stop

    }

}  

}

void Stop()
{
  motor1.setSpeed(0);//Define a velocidade máxima
  motor2.run(RELEASE); //Desliga o motor1
  motor2.setSpeed(0);//Define a velocidade máxima
  motor2.run(RELEASE); //Desliga o motor2
}
