# Documentação do Código - Controle de LEDs com Raspberry Pi Pico

## Introdução
Este código implementa um sistema de controle de LEDs utilizando o microcontrolador Raspberry Pi Pico. Ele gerencia a ativação de três LEDs (vermelho, azul e verde) em sequência, utilizando um temporizador repetitivo para alternar os estados dos LEDs a cada segundo.

## Hardware Utilizado
- Raspberry Pi Pico
- LED Vermelho (conectado ao pino 13)
- LED Azul (conectado ao pino 12)
- LED Verde (conectado ao pino 11)
- Resistores apropriados para LEDs

## Bibliotecas Utilizadas
- `<stdio.h>`: Para entrada e saída de dados via terminal.
- `pico/stdlib.h`: Para controle dos pinos GPIO.
- `pico/time.h`: Para gerenciamento de temporizadores.

## Definições de Pinos
```c
const uint LED_PIN_GREEN = 11;
const uint LED_PIN_BLUE = 12;
const uint LED_PIN_RED = 13;
```
Essas constantes definem os pinos GPIO do Raspberry Pi Pico aos quais os LEDs estão conectados.

## Variáveis Globais
```c
bool led_sequence_active = false;
bool led_state = false;
uint current_led = 0;
```
Essas variáveis controlam o estado dos LEDs e a lógica de alternância.

## Função de Callback do Temporizador
```c
bool repeating_timer_callback(struct repeating_timer *t) {
```
Essa função é chamada automaticamente a cada segundo para alternar os LEDs.
- Liga e desliga o LED atual.
- Alterna para o próximo LED na sequência (vermelho → azul → verde → vermelho).
- Exibe uma mensagem no terminal indicando o estado do LED.

## Função `main()`
A função principal inicializa o sistema e configura os pinos dos LEDs:
1. Inicializa a comunicação serial.
2. Define os pinos GPIO como saídas.
3. Define o LED vermelho como o primeiro a ser acionado.
4. Configura um temporizador repetitivo para chamar `repeating_timer_callback()` a cada 1000 ms.
5. Mantém o programa em execução imprimindo mensagens no terminal a cada segundo.

## Exemplo de Saída no Terminal
```
LED 0 ON
LED 1 OFF
LED 2 ON
Sistema rodando...
```

## Conclusão
Este código demonstra um sistema simples de controle de LEDs utilizando o Raspberry Pi Pico. Ele pode ser expandido para aplicações como semáforos, sistemas de sinalização ou projetos interativos

