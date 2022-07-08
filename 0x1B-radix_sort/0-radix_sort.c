#include "sort.h"
/**
 * radix_sort - a function that resolver a sort array
 * @array: the array to be sorted
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int max = 0, exp;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}

/**
 * getMax - get the max int of the array
 * @arr: the array to be searched for
 * @n: the size of the array
 *
 * Return: the max number of the array
 */

int getMax(int arr[], int n)
{
	int mx = arr[0];
	int i;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > mx)
			mx = arr[i];
	}
	return (mx);
}


/**
 * countSort- the part where the sorting take place
 * @arr: the array to be sorted
 * @n: the size of the array
 * @exp: the idx where the idx is envolving
 */

void countSort(int arr[], int n, int exp)
{
	int *output;
	int i, count[10] = { 0 };

	output = malloc(sizeof(*output) * (n + 1));

	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}

	free(output);
}
