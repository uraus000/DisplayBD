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
    for (uint8_t page = 0; page < 4; page++) {
        for (uint8_t chip = 1; chip <= 2; chip++) {
            GLCD_WriteCommand(0xB8 | page, chip);  // Page address
            GLCD_WriteCommand(0x40, chip);         // Column address = 0
            for (uint8_t col = 0; col < 50; col++) {
                GLCD_WriteData(0x00, chip);        // Clear byte
            }
        }
    }
}

void GLCD_SetPixel(uint8_t x, uint8_t y, uint8_t on) {
    if (x >= 100 || y >= 32) return;

    uint8_t page = y / 8;
    uint8_t bit = y % 8;

   // if (on)
   //     glcd_buffer[x][page] |= (1 << bit);
   // else
    //    glcd_buffer[x][page] &= ~(1 << bit);

    uint8_t chip = (x < 50) ? 1 : 2;
    uint8_t col = x % 50;

    GLCD_WriteCommand(0xB8 | page, chip);
    GLCD_WriteCommand(0x40 | col, chip);
  //  GLCD_WriteData(glcd_buffer[x][page], chip);
}

void GLCD_DrawPixel(uint8_t x, uint8_t y) {
    uint8_t chip = (x < 50) ? 1 : 2;
    uint8_t col = x % 50;
    uint8_t page = y / 8;
    uint8_t bit = y % 8;

    static uint8_t buffer[100][4] = {0}; // 단순 버퍼

    buffer[x][page] |= (1 << bit);

    GLCD_WriteCommand(0xB8 | page, chip);
    GLCD_WriteCommand(0x40 | col, chip);
    GLCD_WriteData(buffer[x][page], chip);
}

void GLCD_SetCursor(uint8_t x, uint8_t Line, uint8_t chip) {
   uint8_t temp = 0x80;
   temp |= (Line == 0)?0x00:0x40;
   temp |= x;
	//GLCD_WriteCommand(0x80 | page, chip);      // Set page
    //GLCD_WriteCommand(0x40 | x, chip);         // Set column
   GLCD_WriteCommand(temp,2);
}

void GLCD_PutChar(uint8_t x, uint8_t page, char ch) {
    if (ch < 32 || ch > 127) return;

    // GLCD_SetCursor(col, page, chip);

}
