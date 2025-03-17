/*
 * DAC.h
 *
 *  Created on: Nov 29, 2024
 *      Author: brend
 */

#ifndef DAC_H_
#define DAC_H_

// Initialize DAC function
void DAC_Init();

// Pass 4 bit data to function, outputs to DAC
void DAC_Out(uint8_t Data);



#endif /* DAC_H_ */
