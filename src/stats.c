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
 * @file stats.c 
 * @brief Perfoms analysis on an array
 *
 * This program prints a pre-selected data set, its maximum and minimum value and also its mean and median values. Lastly the array is reorganized from highest to lowest value and then printed again.
 *
 * @author Gabriel Oliveira
 * @date 16/05/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


//void main() {}


void print_statistics(unsigned char array[], unsigned int size){
 

  printf("The array has a maximum value of %d and a minimum value of %d\n", find_maximum(array, size),find_minimum(array, size));

  printf("The mean value of the array is %d and the median is %d\n", find_mean(array, size), find_median(array, size));
  
}

void print_array(unsigned char array[], unsigned int size){

    #ifdef VERBOSE
    printf("Printing all the %d elements of the array\n [", size);
    for(int i=0; i < size; i++){
      printf("%d ", array[i]);
    }
    
    printf("]\n");
    #endif 
}


void sort_array(unsigned char array[], unsigned int size){
  unsigned char aux[size];
  unsigned char maximum = 0;

  int maximum_index = 0;

  printf("Sorting the array from maximum to minimum\n");

  for(int i=0; i < size; i++){

    for(int j=0; j < size; j++){
      if(array[j] > maximum){
        maximum = array[j];
        maximum_index = j;
      }
    }

    aux[i] = maximum;
    array[maximum_index] = 0;
    maximum = 0;
  }

  for(int k=0; k<size; k++){
  array[k] = aux[k];
  }

}


int find_median(unsigned char array[], unsigned int size){
  int sum = 0;

  sum = (array[19] + array[20])/2;

  return sum;
}


int find_mean(unsigned char array[], unsigned int size){
  int sum = 0;

  for(int i=0; i < size; i++){
    sum += array[i];
  }

  return sum/size;
}


int find_maximum(unsigned char array[], unsigned int size){
  int maximum = array[0];

  for(int i=0; i < size; i++){
    if(array[i] > maximum)
      maximum = array[i];
  }
return maximum;
}


int find_minimum(unsigned char array[], unsigned int size){
  int minimum = array[0];

  for(int i=0; i < size; i++){
    if(array[i] < minimum)
      minimum = array[i];
  }
return minimum;

}




