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
 * @file stats.h 
 * @brief Function deaclarations for the stats
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

void print_statistics(unsigned char array[], unsigned int size);

/**
 * @brief Prints the statistics of the array
 *
 * Prints the the maximum, minimum, mean and median values of the array. The array is passed by reference as a way to decrease memory usage, avoiding unecessary copies.
 *
 * @param *array The array to be analyzed
 *
 * @return This function doesn't return anything, the results are shown on-screen
 */

void print_array(unsigned char array[], unsigned int size);

/**
 * @brief Prints the array
 *
 * Prints all the components of the array one by one
 *
 * @param *array The array to be printed
 *
 * @return This function doesn't return anything, the components of the array are printed sequentially.
 */

void sort_array(unsigned char array[], unsigned int size);

/**
 * @brief Sorts the array
 *
 * Analises the array and consecutively builds another array with the values of the first one ordered from highest to lowest. After that the array is copied back to the original one.
 *
 * @param *array The array to be sorted
 * @param size The size of the array passed as an argument
 *
 * @return Returns nothing, the original array is rewritten.
 */

int find_median(unsigned char array[], unsigned int size);

/**
 * @brief Finds and returns the median value
 *
 * After the analysis of the entire array, the value closer to the median is returned.
 *
 * @param *array The array to have the median searched for
 * @param size The size of the array passed as an argument
 *
 * @return The median value
 */



int find_mean(unsigned char array[], unsigned int size);

/**
 * @brief Finds and returns the mean value of the array
 *
 * After the analysis of the entire array, its mean value is returned.
 *
 * @param *array The array to have the mean searched for
 * @param size The size of the array passed as an argument
 *
 * @return The mean value
 */

int find_maximum(unsigned char array[], unsigned int size);

/**
 * @brief Finds and returns the maximum value of the array
 *
 * After the analysis of the entire array, its maximum value is returned.
 *
 * @param *array The array to have the maximum searched for
 * @param size The size of the array passed as an argument
 *
 * @return The maximum value
 */

int find_minimum(unsigned char array[], unsigned int size);

/**
 * @brief Finds and returns the minimum value of the array
 *
 * After the analysis of the entire array, its minimum value is returned.
 *
 * @param *array The array to have the minimum searched for
 * @param size The size of the array passed as an argument
 *
 * @return The minimum value
 */




#endif __STATS_H__ 
