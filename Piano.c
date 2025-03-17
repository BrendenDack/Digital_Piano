/*
 * Piano.c
 *
 *  Created on: Dec 4, 2024
 *      Author: brendendack
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"

void GPIOPortF_Init() {


        // 1) Activate clock for Port F
        SYSCTL_RCGCGPIO_R |= 0x20; // Set bit 5 to turn on clock for Port F
        //SysTick_Wait10ms(1); // Allow time for clock to stabilize

        // 2) Unlock the lock register for Port F
        GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // Unlock GPIO Port F Commit Register
        GPIO_PORTF_CR_R = 0xFF; // Enable commit for Port F

        // 3) Disable analog functionality
        GPIO_PORTF_AMSEL_R = 0x00; // Disable analog functionality

        // 4) Configure as GPIO
        GPIO_PORTF_PCTL_R = 0x00000000; // Configure Port F as GPIO

        // 5) Set direction register
        GPIO_PORTF_DIR_R = 0x0E; // PF0 and PF4 input, PF3-1 output

        // 6) Regular port function
        GPIO_PORTF_AFSEL_R = 0x00; // Disable alternate function

        // Enable weak pull-up on PF0 and PF4
        GPIO_PORTF_PUR_R = 0x11;

        // 7) Enable Port F digital port
        GPIO_PORTF_DEN_R = 0xFF; // Enable digital I/O on Port F
}

void Piano_Init() {

    GPIOPortF_Init();
}

uint32_t Piano_in() {
    uint32_t PortF = GPIO_PORTF_DATA_R & 0b10001;
    uint32_t PortE = GPIO_PORTE_DATA_R & 0x10;
    uint32_t keys = ((PortF&0x1)<<1)|((PortF&0x10)>>2)|PortE>>4;
    return keys;
}


