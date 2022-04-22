#include "sort.h"

void siftdown(int array[], int root, int last);
void build_heap_max(int array[], int end);
void heapify(int arr[], int n, int i, int size);
void swap(int *a, int *b);

/**
 * heap_sort - obtain the heap sort of a array
 * @array: the array to sort
 * @size: the size of the array
 */

void heap_sort(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
      heapify(array, size, i, size);
    // Heap sort
    for (int i = size - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
	  print_array(array, size);
      // Heapify root element to get highest element at root again
      heapify(array, i, 0, size);
    }
}

void siftdown(int array[], int root, int last)
{
	int largest = root, l = 2 * root + 1, r = 2 * root + 1, temp = 0;

	if (l <= last && array[largest] < array[l])
		largest = l;

	if (r <= last && array[largest] < array[r])
		largest  = r;

	if (largest != root)
	{
		temp = array[largest];
		array[largest] = array[root];
		array[root] = temp;

		siftdown(array, largest, last);
	}
}


void build_heap_max(int array[], int end)
{
	int i = (end - 1) / 2;

	while (i >= 0)
	{
		siftdown(array, i, end);
		i--;
	}
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

void heapify(int arr[], int n, int i, int size) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
	largest = left;

	if (right < n && arr[right] > arr[largest])
	largest = right;

	if (largest != i) {
	swap(&arr[i], &arr[largest]);
	print_array(arr, size);
	heapify(arr, n, largest, size);
	}
}
