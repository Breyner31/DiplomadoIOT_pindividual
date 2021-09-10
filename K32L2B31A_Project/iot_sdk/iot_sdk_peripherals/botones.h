/*! @file : botones.h
 * @author  Breyner Lopez Granados
 * @version 1.0.0
 * @date    7/09/2021
 * @brief   Driver para lectura de botones en FRDM-K32L2B
 * @details
 *
 */
#ifndef IOT_SDK_PERIPHERALS_BOTONES_H_
#define IOT_SDK_PERIPHERALS_BOTONES_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "peripherals.h"
#include "fsl_gpio.h"
/*!
 * @addtogroup PERIPHERALS
 * @{
 */
/*!
 * @addtogroup BOTONES
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
bool boton1leerestado();
bool boton2leerestado();

/** @} */ // end of BOTONES group
/** @} */ // end of PERIPHERALS group

#endif /* IOT_SDK_PERIPHERALS_BOTONES_H_ */
