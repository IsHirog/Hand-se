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
git clone https://github.com/IsHirog/Hande-se.git
cd mao-robotica
```

### 2. Controle Manual via Serial
Você pode controlar o braço robótico manualmente via comandos enviados pelo monitor serial do Arduino pelo codigo .

Comandos disponíveis:

```bash
  abrir
```
```bash
  fechar
```
```bash
  testar
```
Ajustar os ângulos dos servos:
Envie um comando no formato:

```bash
<canal> <ângulo>
```
onde:

<canal> é o canal do servo (0-4).
<ângulo> é o ângulo desejado (0-180 graus).
Exemplo: 0 90 irá mover o servo no canal 0 para 90 graus.

## Código em Python

O código em Python é responsável pela interface de visão computacional e controle do braço robótico. Ele permite que o sistema interaja com o ambiente e envie comandos para o Arduino, baseado em processamento de imagem.

### Funcionalidade

- **Visão Computacional**: O código em Python captura imagens usando uma câmera conectada ao seu computador e processa essas imagens para identificar objetos ou gestos, enviando comandos ao Arduino com base nesse processamento.
- **Envio de Comandos**: Quando um gesto ou objeto é identificado, o código em Python envia os comandos correspondentes para o Arduino via comunicação serial. O braço robótico então executa as ações definidas, como abrir ou fechar os dedos.

### Como Usar

1. **Baixar as bibliotecas necessárias**:
    Antes de rodar o código Python, é necessário instalar as bibliotecas que são utilizadas para comunicação serial e processamento de imagem. Execute os seguintes comandos para instalar as bibliotecas necessárias:

    ```bash
    pip install pyserial opencv-python
    ```

    - `pyserial`: Biblioteca para comunicação serial entre o Python e o Arduino.
    - `opencv-python`: Biblioteca para processamento de imagem, usada para capturar e processar as imagens da câmera.

2. **Conectar o Arduino**:
    Conecte o Arduino à porta serial do seu computador. Certifique-se de que o código do Arduino esteja rodando, pois o Python irá enviar comandos para ele via serial.

3. **Executar o código Python**:
    Execute o script Python no seu ambiente local:

    ```bash
    codigoDeControle_V-0.1.py
    ```

    O código Python começará a capturar imagens e processá-las. Com base nas imagens, ele irá gerar comandos para controlar o braço robótico, enviando-os via serial para o Arduino.

### Observações

O código final do Arduino ainda está em desenvolvimento e pode estar sujeito a alterações. No momento, a funcionalidade básica de controle dos servos via comandos seriais está funcionando, mas melhorias e otimizações estão sendo feitas.

A interface de visão computacional em Python pode ser aprimorada para adicionar mais gestos e interações, tornando o sistema mais inteligente e responsivo.

## Contribuições

Contribuições são bem-vindas! Se você tiver melhorias ou correções para o código, sinta-se à vontade para abrir uma **pull request** ou um **issue** para discutir melhorias.

1. Faça um fork deste repositório.
2. Crie uma nova branch (`git checkout -b feature/nome-da-sua-feature`).
3. Faça as alterações desejadas.
4. Commit suas mudanças (`git commit -m 'Adicionando nova feature'`).
5. Envie para o seu fork (`git push origin feature/nome-da-sua-feature`).
6. Abra uma pull request para o repositório original.

Se precisar de ajuda ou quiser discutir algo sobre o projeto, entre em contato comigo no Instagram: [christian_gah](https://www.instagram.com/christian_gah).
