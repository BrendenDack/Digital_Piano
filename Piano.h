/*
 * Piano.h
 *
 *  Created on: Dec 4, 2024
 *      Author: brendendack
 */

#ifndef PIANO_H_
#define PIANO_H_

// Initializes the Piano Module
void Piano_Init();


/* When called, checks for what keys are pressed and returns the note code */
uint32_t Piano_in();



#endif /* PIANO_H_ */
