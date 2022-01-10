#include "sort.h"


/**
 * swap - swaps number
 * @a: variable to swap
 * @b: variable to swap
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - gives a pivot index for Quicksort
 * @array: array to find the pivot for
 * @high: index of the right element
 * @low: index of the left element
 * @size: size of array
 *
 * Return:  return index if the pivot
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = (low - 1);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quickSort_recursion - recursive function for quicksort
 * @array: array to be sorted
 * @high: index of the right element
 * @low: index of the left element
 * @size: size of the array
 */

void quickSort_recursion(int array[], int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort_recursion(array, low, pivot - 1, size);
		quickSort_recursion(array, pivot + 1, high, size);
	}

}

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quickSort_recursion(array, 0, (int)size - 1, size);
}

