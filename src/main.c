#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "interruption.h"

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
#define LED_RGB_MASK 1 << RED_LED_PIN | 1 << GREEN_LED_PIN | 1 << BLUE_LED_PIN // Mascara de bits para inicializar o LED RGB
#define LED_RGB_GPIO_DIR_MASK 1 << RED_LED_PIN | 1 << GREEN_LED_PIN | 1 << BLUE_LED_PIN // Mascara de bits para configurar o LED RGB como saída

// Função que será disparada quando a interrupção for atendida
void buttons_irq_handler(uint gpio, uint32_t events){
    // Obtém o tempo atual em microssegundos
    uint64_t current_time = to_us_since_boot(get_absolute_time());

    // Cria uma variável para armazenar o tempo, microssegundos, que o último evento aconteceu
    static volatile uint64_t last_event_time = 0;

    // Verifica se já se passaram 300 ms desde o último evento de acionamento do botão, prevenindo o debouncing
    if (current_time - last_event_time > DEBOUNCING_INTERVAL){
        last_event_time = current_time;

        // Verifica qual botão foi pressionado para controlar o LED RGB
        switch (gpio){
            case BUTTON_A_PIN:
                static volatile bool green_led_on = false; // Variável que controla o estado do LED verde

                printf("Botão A pressionado! Alterando o estado do LED verde...\n");

                gpio_put(GREEN_LED_PIN,!green_led_on); // Acendendo/Desligando o LED verde

                green_led_on = !green_led_on; // Atualizando o estado da variável de controle
            break;

            case BUTTON_B_PIN:
                static volatile bool blue_led_on = false; // Variável que controla o estado do LED verde

                printf("Botão B pressionado! Alterando o estado do LED azul...\n");

                gpio_put(BLUE_LED_PIN,!blue_led_on); // Acendendo/Desligando o LED verde

                blue_led_on = !blue_led_on; // Atualizando o estado da variável de controle
            break;

            default:
            break;
        }
    }
}

int main(){
    stdio_init_all(); // Inicializa a comunicação serial via USB

    gpio_init_mask(LED_RGB_MASK); // Inicializa o LED RGB
    gpio_set_dir_masked(LED_RGB_MASK,LED_RGB_GPIO_DIR_MASK); // Coloca todos os pinos do LED RGB como saída em nível baixo

    initialize_buttons(BUTTON_A_PIN,BUTTON_B_PIN,buttons_irq_handler); // Inicializa e configura a interrupção para os botões A e B

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}