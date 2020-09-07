/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);


/**
 * @brief Moves a length of bytes from the source pointer to a destination pointer
 *
 * Given two pointers, a source and a destination, moves a predefined
 * amount of bytes, handling overlap without data corruption
 *
 * @param src Pointer to the source 
 * @param dest Pointer to the destination
 * @param length Length in bytes to move from source to destination
 *
 * @return pointer to the destination
 */

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies a length of data from source to destination
 *
 * Copies a set amount of bytes from a pointer source to a 
 * destination. Copy occurs even if data overlaps.
 *
 * @param src Pointer to the source 
 * @param dest Pointer to the destination
 * @param length Length in bytes to move from source to destination
 *
 * @return pointer to the destination
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Sets a length of memory to a specified value
 *
 * Given a pointer, sets all memory positions to the value 
 * return a pointer to the source.
 *
 * @param src Pointer to the source 
 * @param length Length in bytes to set values
 * @param value Value to be set
 *
 * @return pointer to the source
 */

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets a length of memory to zero
 *
 * Given a pointer, sets all memory positions in length to zero 
 * return a pointer to the source.
 *
 * @param src Pointer to the source 
 * @param length Length in bytes to set values
 *
 * @return pointer to the source
 */

uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of all bytes in a given length
 *
 * Given a pointer, reorder all the memory possitions in
 * an predefined length
 *
 * @param src Pointer to the source 
 * @param length Length in bytes to reorder
 *
 * @return pointer to the source
 */

uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reserves a number of words in dinamic memory
 * 
 * @param length Length in bytes to reserve
 *
 * @return pointer to memory if successful or a null pointer if unsuccessful
 */

int32_t * reserve_words(size_t length);


/**
 * @brief Frees memory space using the pointer as index
 * 
 * @param src pointer where memory should be freed
 *
 * @return void
 */

void free_words(int32_t * src);




#endif /* __MEMORY_H__ */
