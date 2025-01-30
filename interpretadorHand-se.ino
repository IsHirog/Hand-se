#include <Servo.h>

// Definição dos servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// Definição dos pinos dos servos
const int pinoServo1 = 3;
const int pinoServo2 = 5;
const int pinoServo3 = 6;
const int pinoServo4 = 9;
const int pinoServo5 = 10;

// Array de ponteiros para os servos
Servo* servos[] = { &servo1, &servo2, &servo3, &servo4, &servo5 };

// Função para mover o servo
void moveServo(Servo* servo, int angulo) {
    servo->write(angulo);
}

void setup() {
    Serial.begin(9600);  // Inicia a comunicação serial
    
    // Anexando os servos aos pinos
    servo1.attach(pinoServo1);
    servo2.attach(pinoServo2);
    servo3.attach(pinoServo3);
    servo4.attach(pinoServo4);
    servo5.attach(pinoServo5);
}

void loop() {
    if (Serial.available()) {
        String comando = Serial.readStringUntil('\n');  // Lê os dados enviados pelo Python

        if (comando.length() == 5) {  // Verifica se tem 5 caracteres
            long comandoInt = strtol(comando.c_str(), NULL, 2);  // Converte a string binária para inteiro

            // Agora, comandoInt é um número inteiro representando a sequência binária
            for (int i = 0; i < 5; i++) {
                if (bitRead(comandoInt, 4 - i)) {  // Verifica o i-ésimo bit (a partir do mais significativo)
                    moveServo(servos[i], i == 0 ? 70 : 170);
                } else {
                    moveServo(servos[i], 0);
                }
            }
            
            // Envia uma confirmação para o Python
            Serial.println("Comando recebido com sucesso!");  // Confirmação do Arduino
        }
    }
}
