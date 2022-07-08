#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int place);

#endif /*_SORT_h_*/
