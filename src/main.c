#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define RED_LED_PIN 13 // GPIO que controla o LED vermelho
#define GREEN_LED_PIN 11 // GPIO que controla o LED verde
#define BLUE_LED_PIN 12 // GPIO que controla o LED azul
#define LED_MATRIX_PIN 7 // GPIO conectada a matriz de LED's
#define BUTTON_A_PIN 5 // GPIO conectada ao botão A
#define BUTTON_B_PIN 6 // GPIO conectada ao botão B
#define DEBOUNCING_INTERVAL 300000 // Intervalo de debouncing em microssegundos (300 ms)
#define I2C_PORT i2c1 // Porta I2C que será utilizada para a comunicação com o display
#define DISPLAY_I2C_SDA_PIN 14 // GPIO conectada ao pino Serial Data do display
#define DISPLAY_I2C_SCL_PIN  15 // GPIO conectada ao pino Serial Clock do display
#define DISPLAY_I2C_ADDRESS 0x3C // Endereço I2C do Display
#define DISPLAY_CLOCK_FREQUENCY 400 * 1000 // Define a frequência de clock do display em KHz (400KHz)

int main()
{
    stdio_init_all(); // Inicializa a comunicação serial via USB

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}