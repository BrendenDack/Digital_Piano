/*
 * Sound.c
 *
 *  Created on: Dec 4, 2024
 *      Author: brend
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "DAC.h"
#include "SysTickInts.h"

// 4-bit 32-element sine wave
const uint8_t wave[32] = {
8,9,11,12,13,14,14,15,15,15,14,
14,13,12,11,9,8,7,5,4,3,2,
2,1,1,1,2,2,3,4,5,7
};

void Sound_Init() {

    DAC_Init();

    SysTick_Init(80000000);
}

void Sound_Play(char note) {

    uint16_t Counts = 0;
    // Function to set frequency of the sine wave
    if (note == 'O') {Counts = 0;} // OFF note to stop playback
    else if (note == 'C') {
        // Set sine wave with frequency of note C
        Counts = ((double) 80000000/523)/32;
    }
    else if (note == 'G') {
        // Set sine wave with frequency of note B
        Counts = ((double) 80000000/392)/32;
    }
    else if (note == 'D') {
        // Set sine wave with frequency of note A
        Counts = ((double) 80000000/294)/32;
    }
    else {
        // Default catch for invalid note
        Counts = 0;
    }
    //Counts = ((double) 80000000/440)/32;
    SysTick_SetReload(Counts);

}
