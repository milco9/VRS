/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"
#include <stdbool.h>
int add = 0;
uint8_t prevPinstate;
int main(void)
{
  /*
   *  DO NOT WRITE TO THE WHOLE REGISTER!!!
   *  Write to the bits, that are meant for change.
   */
   
  //Systick init
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(8000000);	

  /*
   * TASK - configure MCU peripherals so that button state can be read and LED will blink.
   * Button must be connected to the GPIO port A and its pin 3.
   * LED must be connected to the GPIO port A and its pin 4.
   *
   * In header file "assignment.h" define macros for MCU registers access and LED blink application.
   * Code in this file must use these macros for the peripherals setup.
   * Code of the LED blink application is already given so just the macros used in the application must be defined.
   */

  /* Enable clock for GPIOA*/
    RCC_AHBENR_REG |= (uint32_t)(1 << 17);
    /* GPIOA pin 3 and 4 setup */
    // set mode PIN 3 input - PA3
    GPIOA_MODER_REG &= ~(uint32_t)(1 << 6);
    GPIOA_MODER_REG &= ~(uint32_t)(1 << 7);
    // set mode PIN 4 output - PA2, 0x3=11 o 8 miest do lava
    GPIOA_MODER_REG &= ~(uint32_t)(0x3 << 8);
    GPIOA_MODER_REG |= (uint32_t)(1 << 8);
    /*GPIO OTYPER register 1 to output open-drain*/
    GPIOA_OTYPER_REG &= ~(1 << 4);
    /*GPIO OSPEEDR register*/
    //Set for GPIOB pin 4 - x0 LOW speed, 0x3=11 o 8 miest do lava
    GPIOA_OSPEEDER_REG &= ~(1 << 8);
    GPIOA_OSPEEDER_REG &= ~(1 << 9);
    /*GPIO PUPDR register, reset*/
      //Set pull up for GPIOB pin 3 (in)
    GPIOA_PUPDR_REG |= (1 << 6);
    //Set no pull for GPIOB pin 4 (out)
    GPIOA_PUPDR_REG &= ~(1 << 8);
    GPIOA_PUPDR_REG &= ~(1 << 9);
    int get ;
    bool pom = false;
    bool led = false;
    uint8_t pin_state;

  while (1)
  {
	  pin_state=BUTTON_GET_STATE;
	  get =edgeDetect(pin_state,20);
	  if (get == 1){
		  if (led==false){
			  pom = true;
		  }else if (led==true){
			  pom = false;
		  }
	  }



	  if(pom == true)
	  {
		  //LED ON
		  LED_ON;
		  led=true;
	  }
	  else if(pom ==false)
	  {
		  //LED OFF
		  LED_OFF;
		  led=false;
	  }
  }

}

enum EDGE_TYPE edgeDetect(uint8_t pin_state, uint8_t samples){
	uint8_t off=0x8;
	uint8_t on=0x0;
if(prevPinstate == pin_state){
	add=add+1;
}else {
	add = 1;
}

		if ((add == samples)&& pin_state == off){
			prevPinstate=pin_state;
			return fall;
		}

		if ((add == samples)&& pin_state == on){
			prevPinstate=pin_state;
			return rise;
		}

	prevPinstate=pin_state;
	return none;
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
