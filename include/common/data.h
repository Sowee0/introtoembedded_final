/******************************************************************************
 * Copyright (C) 2020 - Gabriel Oliveira 
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief This file holds the data functions for the final assignment.
 *
 * @author Gabriel Oliveira
 * @date September 1st, 2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief converts an integer to ASCII 
 *
 * Converts an integer from bases 2 to 16 and saves it back 
 * on the pointer location 
 *
 * @param data Pointer to data array
 * @param ptr Index into pointer array to set value
 * @param base base the number is in
 *
 * @return length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)

/**
 * @brief converts an ASCII to integer 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param digits Number of digits
 * @param base base the number is in
 *
 * @return the 32-bit signed converted integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)