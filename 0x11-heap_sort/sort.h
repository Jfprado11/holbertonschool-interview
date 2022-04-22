#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdio.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int arr[], int n, int i, int size);
void swap(int *a, int *b);

#endif /* _SEARCH_H_ */
