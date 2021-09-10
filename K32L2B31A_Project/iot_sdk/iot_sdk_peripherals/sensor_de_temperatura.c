/*! @file : sensor_de_temperatura.c
 * @author  Breyner Lopez Granados
 * @version 1.0.0
 * @date    9/09/2021
 * @brief   Driver para 
 * @details
 *
*/
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include"sensor_de_temperatura.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Private Prototypes
 ******************************************************************************/
void SensorDetemperaturaOptenerDatos(void);
 void sensorDetemperaturaEsperarResultado(void);

/*******************************************************************************
 * External vars
 ******************************************************************************/


/*******************************************************************************
 * Local vars
 ******************************************************************************/


/*******************************************************************************
 * Private Source Code
 ******************************************************************************/
 void SensorDeTemperaturaIniciarCaptura(void) {
       ADC16_SetChannelConfig(
      		 SENSOR_DE_TEMPERATURA_ADC16_BASE,
  			 SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP,
  			 &ADC0_channelsConfig[1]);
    }
   /*------------------------------------------------------------------ */
  void SensorDeTemperaturaEsperarResultado(void) {
  	 while (0U == (kADC16_ChannelConversionDoneFlag &
  	                      ADC16_GetChannelStatusFlags(SENSOR_DE_TEMPERATURA_ADC16_BASE, SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP)))
  	 {

  	 }
  }


/*******************************************************************************
 * Public Source Code
 ******************************************************************************/
  float SensorDeTemperaturaOptenerDatosADC() {
  	float resultadoADC;

  	  SensorDeTemperaturaIniciarCaptura();
  	  SensorDeTemperaturaEsperarResultado();

  	  	  resultadoADC=ADC16_GetChannelConversionValue(SENSOR_DE_TEMPERATURA_ADC16_BASE, SENSOR_DE_TEMPERATURA_ADC16_CHANNEL_GROUP);
  	  	  resultadoADC=(3*resultadoADC)/4095;
  	  	  resultadoADC=(resultadoADC*90)/3.3;
  	  	  return(resultadoADC);
  }
