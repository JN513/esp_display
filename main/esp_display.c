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
    i2c_master_init(&dev, 4, 15, 16);

    ssd1306_init(&dev, 128, 64); // Inicializa o display

    ssd1306_clear_screen(&dev, false); // Limpa o display

    ESP_LOGI(TAG, "Display inicializado");

    ssd1306_display_text(&dev, 0, "Hello, world!", 14, false); // Exibe texto na tela
    ssd1306_display_text(&dev, 1, "Hello, world!", 14, false); // Exibe texto na tela
    ssd1306_display_text(&dev, 2, "Hello, world!", 14, false); // Exibe texto na tela

    ESP_LOGI(TAG, "Display exibindo texto");

    vTaskDelay(5000 / portTICK_PERIOD_MS); // Espera 5 segundos

    ssd1306_clear_screen(&dev, false); // Limpa o display

    ESP_LOGI(TAG, "Display limpo");

    for (int i = 0; i < 10000; i++) {
        char str[19];
        sprintf(str, "Hello, %d", i); // Formata string
        ssd1306_display_text(&dev, 0, str, strlen(str), false); // Exibe texto na tela
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Espera 1 segundo
    }
    
}
