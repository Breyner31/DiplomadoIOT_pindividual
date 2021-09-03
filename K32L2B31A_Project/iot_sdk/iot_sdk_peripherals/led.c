/*! @file : led.c
 * @author  Breyner Lopez Granados
 * @version 1.0.0
 * @date    2/09/2021
 * @brief   Driver para controlar LEDS de tarjeta FRDM-K32L1B3
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "led.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/


/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
 void encender_led_verde(){
	   //enciende led verde
	 GPIO_PinWrite(GPIOD,5,0);

 }
 /*----------------------------------------------------------------------------*/
 void apagar_led_verde(){
       //apaga led verde
	 GPIO_PinWrite(GPIOD,5,1);
 }
