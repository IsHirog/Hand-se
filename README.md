# Hand'se

## Descrição

Este projeto envolve um braço robótico controlado por um Arduino e um código de visão computacional em Python. O objetivo é permitir que o braço robótico execute movimentos, como abrir e fechar os dedos, através de comandos recebidos via serial. Ele também pode ser controlado por uma interface de visão computacional, o que possibilita interação com objetos no ambiente.

O projeto foi desenvolvido com a intenção de criar um braço robótico acessível e fácil de controlar, tanto manualmente, via comandos seriais, quanto automaticamente, por meio de um sistema de visão computacional.

## Funcionalidades

- **Controle via Serial**: O braço pode ser controlado por comandos enviados via monitor serial.
- **Controle dos servos**: O código permite mover os servos para ângulos específicos ou ativar movimentos como "abrir", "fechar" e "testar".
- **Integração com Visão Computacional**: O código Python pode ser usado para capturar imagens e fornecer comandos para o Arduino baseado em processamento de imagem.

## Componentes

- **Arduino (Uno ou compatível)**: Para controlar o braço robótico e os servos.
- **PCA9685**: Controlador PWM para controlar múltiplos servos simultaneamente.
- **Servos**: Motores que movem as partes do braço robótico (como dedos e articulações).
- **Fonte de Alimentação**: Fonte adequada para alimentar tanto o Arduino quanto os servos.
- **Estrutura do Braço Robótico**: A estrutura do braço robótico, que pode ser impressa em 3D ou construída de outros materiais. Você pode obter o modelo 3D da mão [aqui no Thingiverse](https://www.thingiverse.com/thing:4807141).

## Instalação

### 1. Clonar o Repositório

Clone este repositório em sua máquina local:
```bash
git clone https://github.com/seuusuario/mao-robotica.git
cd mao-robotica
```

2. Controle Manual via Serial
Você pode controlar o braço robótico manualmente via comandos enviados pelo monitor serial do Arduino.

Comandos disponíveis:
```bash
abrir
fechar
testar```
