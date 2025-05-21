/*
 * GLCD.h
 *
 *  Created on: May 21, 2025
 *      Author: 50015
 */

#ifndef INC_GLCD_H_
#define INC_GLCD_H_

#include <stdint.h>
#include "main.h"

#define GLCD_DATA_PORT 		GPIOC

#define GLCD_CTRL_PORT     GPIOC
#define GLCD_RS_Pin        GPIO_PIN_8
#define GLCD_RW_Pin        GPIO_PIN_9
#define GLCD_EN_Pin        GPIO_PIN_10
#define GLCD_CS2_Pin       GPIO_PIN_11
#define GLCD_CS1_Pin       GPIO_PIN_12


void GLCD_Enable(void);
void GLCD_WriteCommand(uint8_t cmd, uint8_t chip);
void GLCD_WriteData(uint8_t data, uint8_t chip);
void GLCD_Init(void);
void GLCD_Clear(void);
void GLCD_SetCursor(uint8_t x, uint8_t Line);


#endif /* INC_GLCD_H_ */
