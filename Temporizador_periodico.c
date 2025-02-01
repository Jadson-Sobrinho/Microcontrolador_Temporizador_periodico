#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint LED_PIN_GREEN = 11;
const uint LED_PIN_BLUE = 12;
const uint LED_PIN_RED = 13;

bool led_sequence_active = false;
bool led_state = false;
uint current_led = 0;

// Callback do temporizador repetitivo
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna entre os LEDs
    if (current_led == 0) {
        gpio_put(LED_PIN_RED, led_state);
    } else if (current_led == 1) {
        gpio_put(LED_PIN_BLUE, led_state);
    } else if (current_led == 2) {
        gpio_put(LED_PIN_GREEN, led_state);
    }
    
    if (!led_state) {
        current_led = (current_led + 1) % 3; // Alterna entre os LEDs
    }
    
    led_state = !led_state; // Alterna o estado do LED
    
    printf("LED %d %s\n", current_led, led_state ? "ON" : "OFF");
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);

    current_led = 2; // Inicia com o LED vermelho
    struct repeating_timer timer;
    add_repeating_timer_ms(1000, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(1000); // Mantém o programa rodando e imprime status
        printf("Sistema rodando...\n");
    }

    return 0;
}
