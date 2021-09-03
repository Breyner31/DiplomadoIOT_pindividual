/*! @file : led.h
 * @author  Breyner Lopez Granados
 * @version 1.0.0
 * @date    2/09/2021
 * @brief   Driver para controlar LEDS de tarjeta FRDM-K32L1B3
 * @details
 *
 */
#ifndef IOT_SDK_PERIPHERALS_LED_H_
#define IOT_SDK_PERIPHERALS_LED_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/


/*!
 * @addtogroup PERIPHERALS
 * @{
 */
/*!
 * @addtogroup LEDS
 * @{
 */
/*******************************************************************************
 * Public Definitions
 ******************************************************************************/

/*******************************************************************************
 * External vars
 ******************************************************************************/

/*******************************************************************************
 * Public vars
 ******************************************************************************/

/*******************************************************************************
 * Public Prototypes
 ******************************************************************************/

//@brief enciende led verde de la tarjeta FRMD-K32L2B3
 void encender_led_verde();

 //@brief apaga led verde de la tarjeta FRMD-K32L2B3
 void apagar_led_verde();


/** @} */ // end of X LEDS
/** @} */ // end of X PERIPHERALS

#endif /* IOT_SDK_PERIPHERALS_LED_H_ */
