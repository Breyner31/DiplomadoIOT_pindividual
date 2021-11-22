/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    K32L2B31A_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"

#include "led.h"
#include "sensor_de_luz.h"
#include "irq_lptmr0.h"
#include "botones.h"
#include "sensor_de_temperatura.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */


unsigned int test_global_var=100;
float dato_float=3.1416;
/*
 * @brief   Application entry point.
 */
int main(void) {
	float adc_sensor_de_luz;
	float adc_sensor_de_temperatura;

	bool boton1_oprimido,boton2_oprimido;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello World\r\n");
    printf("test_global_var:%d\r\n", test_global_var);
    printf("dato_float:%g\r\n",dato_float);
    /* Start counting */
       LPTMR_StartTimer(LPTMR0);

    /* Force the counter to be placed into memory. */
    /*volatile static int i = 0 ;
    //* Enter an infinite loop, just incrementing a counter. */


    while(1) {

    	if(lptmr0_irq_counter!=0){
    		lptmr0_irq_counter=0;

    		boton1_oprimido = !boton1leerestado();
    		boton2_oprimido = !boton2leerestado();

    		if( boton1_oprimido && !flag_boton1_presionado){
    			flag_boton1_presionado = 1;
    			adc_sensor_de_luz = SensorDeluzOptenerDatosADC();
    			printf("adc_sensor_de_luz:%.3f\r\n", adc_sensor_de_luz);
    		}

    		if( !boton1_oprimido){
    			flag_boton1_presionado = 0;
    		}

    		if( boton2_oprimido && !flag_boton2_presionado){
    		    			flag_boton2_presionado = 1;
    		    			adc_sensor_de_temperatura = SensorDeTemperaturaObtenerDatosADC();
    		 printf("temperatura:%.3f\r\n", adc_sensor_de_temperatura);
    		    		}

    		    		if( !boton2_oprimido){
    		    			flag_boton2_presionado = 0;
    		    		}
    	}
    		if( flag_led_rojo_iqr_counter == 1000){  //* Enciende el led rojo cada 1 segundo
    			flag_led_rojo_iqr_counter = 0;
    			toggle_led_rojo();
    		}

    }
    return 0 ;
}


