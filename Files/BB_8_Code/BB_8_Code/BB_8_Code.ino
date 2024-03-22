#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial bluetooth(0, 1); // Use outras portas disponíveis para o SoftwareSerial

AF_DCMotor motor1(1); //Define que entrada 1 é o motor1
AF_DCMotor motor2(2); //Define que entrada 2 é o motor2

char command; //variável comando 

int ledPin = 13; //Define que o pin 13 é igual a ledPin

void setup() 
{ 
  pinMode(ledPin, OUTPUT); //Define que ledPin é OUTPUT 
  digitalWrite(ledPin, LOW); //Define o LedPin para Low 

  Serial.begin(9600); //Define a velocidade de transferência de dados entre o Arduino e o computador
  bluetooth.begin(9600); //Define a velocidade de transferência de dados entre o Arduino e o módulo Bluetooth
}

void loop()
{
  while(bluetooth.available() > 0) //enquanto o Bluetooth estiver disponível 
  {
    command = bluetooth.read(); //vai ler o comando enviado por Bluetooth
    
    if(command == 'f') //se o comando for "f"
    {
      motor1.setSpeed(200); //Define a velocidade máxima (255)
      motor1.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
      motor2.setSpeed(200); //Define a velocidade máxima 
      motor2.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
      bluetooth.println("Para a frente"); //Manda a mensagem para a aplicação
    }
    else if (command == 'b') //se o comando for "b"
    {
      motor1.setSpeed(200); //Define a velocidade máxima 
      motor1.run(BACKWARD); //Roda no sentido contrário ao ponteiro do relógio
      motor2.setSpeed(200); //Define a velocidade máxima
      motor2.run(BACKWARD); //Roda no sentido contrário ao ponteiro do relógio
      bluetooth.println("Para trás"); //Manda a mensagem para a aplicação
    }
    else if(command == 'l') //se o comando for "l"
    {
      motor1.setSpeed(200); //Define a velocidade máxima 
      motor1.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
      motor2.setSpeed(0); //Define a velocidade máxima
      motor2.run(FORWARD); //Desliga o motor2
      bluetooth.println("Para a esquerda"); //Manda a mensagem para a aplicação
    }
    else if (command == 'r') //se o comando for "r"
    {
      motor1.setSpeed(0); //Define a velocidade máxima
      motor1.run(FORWARD); //Desliga o motor1
      motor2.setSpeed(200); //Define a velocidade máxima
      motor2.run(FORWARD); //Roda nos sentidos dos ponteiros do relógio
      bluetooth.println("Para a direita"); //Manda a mensagem para a aplicação
    }
    else if (command == '1') //se o comando for "1"
    {
      digitalWrite(ledPin, HIGH); //Define o ledPin como HIGH
      bluetooth.println("LED ligado"); //Manda a mensagem para a aplicação
    } 
    else if (command == '0') //se o comando for "0"
    {
      digitalWrite(ledPin, LOW); //Define o ledPin como Low
      bluetooth.println("LED desligado"); //Manda a mensagem para a aplicação 
    }
    else if (command == 's') //se o comando for "s"
    {
      Stop(); //chama a função Stop
    }
    delay(100); // Pequeno atraso para estabilidade na leitura do Bluetooth
  }  
}

void Stop()
{
  motor1.setSpeed(0); //Define a velocidade máxima
  motor1.run(RELEASE); //Desliga o motor1
  motor2.setSpeed(0); //Define a velocidade máxima
  motor2.run(RELEASE); //Desliga o motor2
  bluetooth.println("Parado"); //Manda a mensagem para a aplicação
}
