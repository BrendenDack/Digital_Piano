/*
 * DAC.c
 *
 *  Created on: Nov 29, 2024
 *      Author: brend
 */
#include "tm4c123gh6pm.h"
#include <stdint.h>

void DAC_Init() {
    // Initialize Port E pins 0-3

    SYSCTL_RCGC2_R |= 0b10000; // Set clock for port E

    // Port E
    GPIO_PORTE_AMSEL_R &= ~(0xF);
    GPIO_PORTE_PCTL_R &= ~(0xF);
    GPIO_PORTE_DIR_R |= 0xF;
    GPIO_PORTE_AFSEL_R &= ~(0xF);
    GPIO_PORTE_DEN_R |= 0x1F;

}

void DAC_Out(uint8_t Data) {
    // Clear data on port E
    GPIO_PORTE_DATA_R &= ~(0xF);

    // Write data to port E
    GPIO_PORTE_DATA_R |= Data;
}

