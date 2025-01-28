#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Inicializa o controlador do PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Parâmetros do servo
#define SERVOMIN  150 // Pulso mínimo (ajuste conforme necessário)
#define SERVOMAX  600 // Pulso máximo (ajuste conforme necessário)

// Variáveis globais para o canal e o ângulo do servo
int servoChannel = 0; // Canal do PCA9685 (0-15)
int servoAngle = 0;   // Ângulo do servo (0-180 graus)

// Função para converter graus para valor do pulso
uint16_t degreesToPulse(int angle) {
    return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

// Função para fechar os servos
void fechar() {
    pwm.setPWM(0, 0, degreesToPulse(170));
    pwm.setPWM(1, 0, degreesToPulse(160));
    pwm.setPWM(2, 0, degreesToPulse(150));
    pwm.setPWM(3, 0, degreesToPulse(160));
    delay(400);
    pwm.setPWM(4, 0, degreesToPulse(70));
}

// Função para abrir os servos
void abrir() {
    pwm.setPWM(4, 0, degreesToPulse(0));
    pwm.setPWM(0, 0, degreesToPulse(0));
    pwm.setPWM(1, 0, degreesToPulse(0));
    pwm.setPWM(2, 0, degreesToPulse(0));
    pwm.setPWM(3, 0, degreesToPulse(0));
}

// Função para testar o movimento dos servos
void testar() {
    fechar();
    delay(1000);
    abrir();
    delay(1000);

    pwm.setPWM(0, 0, degreesToPulse(170));
    delay(500);
    pwm.setPWM(1, 0, degreesToPulse(160));
    delay(500);
    pwm.setPWM(2, 0, degreesToPulse(150));
    delay(500);
    pwm.setPWM(3, 0, degreesToPulse(160));
    delay(500);
    pwm.setPWM(4, 0, degreesToPulse(70));

    delay(1000);
    abrir();
}

void setup() {
    // Inicializa comunicação serial
    Serial.begin(9600);
    Serial.println("Controle do Servo Ativado!");
    Serial.println("Comandos disponíveis:");
    Serial.println(" - <canal> <ângulo>: Ajusta o servo do canal especificado para o ângulo desejado.");
    Serial.println(" - abrir: Abre os servos.");
    Serial.println(" - fechar: Fecha os servos.");
    Serial.println(" - testar: Executa o teste dos servos.");

    // Inicializa o PCA9685 e configura a frequência para 60 Hz
    pwm.begin();
    pwm.setPWMFreq(60);
}

void loop() {
    // Verifica se há dados disponíveis no monitor serial
    if (Serial.available() > 0) {
        String input = Serial.readStringUntil('\n'); // Lê a entrada do monitor serial
        input.trim(); // Remove espaços em branco extras

        // Verifica se o comando é "abrir", "fechar" ou "testar"
        if (input.equalsIgnoreCase("abrir")) {
            abrir();
            Serial.println("Comando recebido: Abrir.");
        } else if (input.equalsIgnoreCase("fechar")) {
            fechar();
            Serial.println("Comando recebido: Fechar.");
        } else if (input.equalsIgnoreCase("testar")) {
            testar();
            Serial.println("Comando recebido: Testar.");
        } else {
            // Divide o input em dois valores: canal e ângulo
            int spaceIndex = input.indexOf(' ');
            if (spaceIndex > 0) {
                String channelStr = input.substring(0, spaceIndex);
                String angleStr = input.substring(spaceIndex + 1);

                servoChannel = channelStr.toInt();
                servoAngle = angleStr.toInt();

                // Verifica se os valores estão dentro dos limites
                if (servoChannel >= 0 && servoChannel <= 15 && servoAngle >= 0 && servoAngle <= 180) {
                    pwm.setPWM(servoChannel, 0, degreesToPulse(servoAngle));
                    Serial.print("Servo no canal ");
                    Serial.print(servoChannel);
                    Serial.print(" ajustado para ");
                    Serial.print(servoAngle);
                    Serial.println(" graus.");
                } else {
                    Serial.println("Erro: Canal (0-15) ou ângulo (0-180) fora do intervalo permitido.");
                }
            } else {
                Serial.println("Entrada inválida. Formato correto: <canal> <ângulo> ou comandos: abrir, fechar, testar.");
            }
        }
    }
}
