#include "sort.h"

void heapify(int arr[], int n, int i, int size);

/**
 * heap_sort - obtain the heap sort of a array
 * @array: the array to sort
 * @size: the size of the array
 */

void heap_sort(int *array, size_t size)
{
	int i = 0;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i], array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * swap - swap two values
 * @a: integer to do swap
 * @b: to do the swap
 */
void swap(int *a, int *b, int arr[], int size)
{
	int temp = *a;

	print_array(arr, size);
	*a = *b;
	*b = temp;

}

/**
 * heapify - swap the value acording
 * @arr: the array
 * @n: the salt node
 * @i: the first node
 * @size: the size of the array
 */
void heapify(int arr[], int n, int i, int size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
	largest = left;

	if (right < n && arr[right] > arr[largest])
	largest = right;

	if (largest != i)
	{
	swap(&arr[i], &arr[largest], arr, size);
	heapify(arr, n, largest, size);
	}
}
