#include "sort.h"

/**
 * merge_sort - a merge to start the serach of the array
 *@array: the array to do the sorting
 *@size: the size of the array
 */

void merge_sort(int *array, size_t size)
{
	merge_sort_res(array, 0, size -1);
}


/**
 * mergeSort_res - a merge to start the serach of the array
 *@array: the array to do the sorting
 *@left: the idx of the left size of the array
 *@right: the idx of the right size of the array
 */

void merge_sort_res(int *array, int left, int right)
{
	int middle = 0;

	if (left < right)
	{
		middle = left + (right - left) / 2;

		merge_sort_res(array, left, middle);
		merge_sort_res(array, middle + 1, right);

		merge(array, left, middle, right);
	}
}

/**
 * mergeSort_res - a merge to start the serach of the array
 *@array: the array to do the sorting
 *@left: the idx of the left size of the array
 *@middle: the midle of the aray
 *@right: the idx of the right size of the array
 */
void merge(int *array, int left, int middle, int right)
{
	int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
	int left_tmp[n1];
	int right_tmp[n2];


	for (i = 0; i < n1; i++)
        left_tmp[i] = array[left + i];
    for (j = 0; j < n2; j++)
	{
        right_tmp[j] = array[middle + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (left_tmp[i] <= right_tmp[j]) {
            array[k] = left_tmp[i];
            i++;
        }
        else {
			array[k] = right_tmp[j];
			j++;
		}
		k++;
	}

    while (i < n1) {
        array[k] = left_tmp[i];
        i++;
        k++;
	}
	while (j < n2) {
        array[k] = right_tmp[j];
        j++;
        k++;
    }
}
