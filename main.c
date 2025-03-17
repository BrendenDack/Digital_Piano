

/**
 * main.c
 */

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "Sound.h"
//#include "DAC.h"

#include "Piano.h"


int main(void)
{
    //uint8_t Data = 0xF;  // 0 to 15 DAC output
    uint32_t keys;
    PLL_Init(Bus80MHz);  // set system clock to 80 MHz

    char note = 'O';

    Sound_Init();
    //DAC_Init();
    Piano_Init();

    while(1) {

        //Take in input from Piano Keys
        keys = Piano_in();

        if (keys == 0x6) { // Default value of no keys pressed is 0x6
            note = 'O';
        }
        else if (keys == 0x7) {
            note = 'C';
        }
        else if (keys == 0x2) {
            note = 'D';
        }
        else if (keys == 0x4) {
            note = 'G';
        }
        else { // Default case if more than one key is pressed
            note = 'O';
        }

        Sound_Play(note);
    }
}
