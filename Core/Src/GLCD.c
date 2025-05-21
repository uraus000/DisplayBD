/*
 * GLCD.c
 *
 *  Created on: May 21, 2025
 *      Author: 50015
 */

#include "glcd.h"

void GLCD_Enable(void) {
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_EN_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_EN_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
}

void GLCD_WriteCommand(uint8_t cmd, uint8_t chip) {

    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_RS_Pin, GPIO_PIN_RESET); // RS=0 (Command)
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_RW_Pin, GPIO_PIN_RESET); // RW=0 (Write)

    // 칩 선택
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_CS1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_CS2_Pin, GPIO_PIN_RESET);

    GLCD_DATA_PORT->ODR = (GLCD_DATA_PORT->ODR & 0xFF00) | cmd; // Data pins = cmd
    GLCD_Enable();
}

void GLCD_WriteData(uint8_t data, uint8_t chip) {
   //HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_EN_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_RS_Pin, GPIO_PIN_SET); // RS=1 (Data)
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_RW_Pin, GPIO_PIN_RESET); // RW=0 (Write)

    // 칩 선택
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_CS1_Pin, chip == 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GLCD_CTRL_PORT, GLCD_CS2_Pin, chip == 2 ? GPIO_PIN_SET : GPIO_PIN_RESET);

    GLCD_DATA_PORT->ODR = (GLCD_DATA_PORT->ODR & 0xFF00) | data;
    GLCD_Enable();
}

void GLCD_Init(void) {

   HAL_Delay(500);
   GLCD_Enable();

   GLCD_WriteCommand(0x3b, 0); // Display ON
   HAL_Delay(10);
   GLCD_WriteCommand(0x0F, 0); // Display ON
   HAL_Delay(10);
   GLCD_WriteCommand(0x01, 0); // Display ON
   HAL_Delay(10);
   GLCD_WriteCommand(0x06, 0); // Display ON
   HAL_Delay(10);
   GLCD_WriteCommand(0x02, 0); // Display ON
   HAL_Delay(10);
}

void GLCD_Clear(void) {
    GLCD_WriteCommand(0x01, 0); // Display ON
}

void GLCD_SetCursor(uint8_t x, uint8_t Line) {
   uint8_t temp = 0x80;
   temp |= (Line == 0)?0x00:0x40;
   temp |= x;
	//GLCD_WriteCommand(0x80 | page, chip);      // Set page
    //GLCD_WriteCommand(0x40 | x, chip);         // Set column
   GLCD_WriteCommand(temp,2);
}

