import cv2
import mediapipe as mp
import serial
import time

# Configuração da comunicação serial (ajuste 'COM3' para a porta do Arduino)
arduino = serial.Serial('COM12', 9600)
time.sleep(2)  # Tempo para inicializar a conexão serial

# Configuração da captura de vídeo
video = cv2.VideoCapture(0)

# Configuração do Mediapipe
hands = mp.solutions.hands
Hands = hands.Hands(max_num_hands=1)
mpDraw = mp.solutions.drawing_utils

while True:
    success, img = video.read()
    if not success:
        print("Falha ao acessar a câmera.")
        break

    # Conversão para RGB
    frameRGB = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
    results = Hands.process(frameRGB)
    handPoints = results.multi_hand_landmarks
    h, w, _ = img.shape
    pontos = []

    if handPoints:
        for points in handPoints:
            mpDraw.draw_landmarks(img, points, hands.HAND_CONNECTIONS)
            for id, cord in enumerate(points.landmark):
                cx, cy = int(cord.x * w), int(cord.y * h)
                pontos.append((cx, cy))

            # Lista para estados dos dedos
            estado_dedos = [0, 0, 0, 0, 0]  # Polegar, Indicador, Médio, Anelar, Mindinho

            if pontos:
                # Verifica o estado do polegar
                if pontos[4][0] > pontos[3][0]:
                    estado_dedos[0] = 1

                # Verifica o estado dos outros dedos
                if pontos[8][1] < pontos[6][1]:
                    estado_dedos[1] = 1
                if pontos[12][1] < pontos[10][1]:
                    estado_dedos[2] = 1
                if pontos[16][1] < pontos[14][1]:
                    estado_dedos[3] = 1
                if pontos[20][1] < pontos[18][1]:
                    estado_dedos[4] = 1

            # Converte o estado dos dedos para uma string
            comando = ''.join(map(str, estado_dedos))
            arduino.write(comando.encode())  # Envia o comando para o Arduino
            print(f'Comando enviado: {comando}')  # Exibe o comando enviado no terminal

    # Mostra a imagem na tela
    cv2.imshow('Imagem', img)

    # Tecla para sair
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Libera os recursos
arduino.close()
video.release()
cv2.destroyAllWindows()
