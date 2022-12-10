/**
 * @autor   Jesus Rojas
 * @file    MKL25Z4_Project.c
 * @brief   Application entry point.
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "FreeRTOS.h"
#include "task.h"


/* TODO: insert other definitions and declarations here. */
void Blink (void *arg){
	while(1){
	GPIO_TogglePinsOutput(GPIOB, 1U << 18);
	vTaskDelay(1000);
	}
}

void Blink2 (void *arg){
	while(1){
	GPIO_TogglePinsOutput(GPIOB, 1U << 19);
	vTaskDelay(900);
	}
}

void Blink3 (void *arg){
	while(1){
	GPIO_TogglePinsOutput(GPIOD, 1U << 1);
	vTaskDelay(800);
	}
}

/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\n");
    xTaskCreate(Blink, "my_task", configMINIMAL_STACK_SIZE + 10, NULL, configMAX_PRIORITIES - 1, NULL);
    xTaskCreate(Blink2, "my_task2", configMINIMAL_STACK_SIZE + 10, NULL, configMAX_PRIORITIES - 1, NULL);
    xTaskCreate(Blink3, "my_task3", configMINIMAL_STACK_SIZE + 10, NULL, configMAX_PRIORITIES - 1, NULL);

    vTaskStartScheduler();
    /* Force the counter to be placed into memory. */

    return 0 ;
}
