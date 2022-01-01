#include <stdio.h>
#include <string.h> // Inclui biblioteca de funções de manipulação de strings

#include "esp_system.h" // Biblioteca de funções do sistema
#include "esp_event.h" // Biblioteca de eventos
#include "esp_log.h" // Biblioteca de log

#include "freertos/FreeRTOS.h" // Biblioteca de sistema de tarefas
#include "freertos/task.h" // Biblioteca de tarefas
#include "freertos/semphr.h" // Biblioteca de sistema de mutex
#include "freertos/queue.h" // Biblioteca de filas

#include "ssd1306.h" // Biblioteca de comunicação com o display

static const char * TAG = "ESP_DISPLAY"; // Tag de log

void app_main(void)
{

    SSD1306_t dev; // Cria estrutura de dados do display

    // Inicializa o display
    i2c_master_init(&dev, 33, 34, 1);

    ssd1306_clear_screen(&dev, false);

    ssd1306_init(&dev, 128, 64); // Inicializa o display

    for (size_t i = 0; i < 8; i++)
    {
        ssd1306_display_text(&dev, i, "                          ", 16, false);
    }
    

    ssd1306_display_text(&dev, 0, "Hello, world!", 14, false); // Exibe texto na tela
    ssd1306_display_text(&dev, 1, "Hello, world!", 14, false); // Exibe texto na tela
    ssd1306_display_text(&dev, 2, "Hello, world!", 14, false); // Exibe texto na tela
}
