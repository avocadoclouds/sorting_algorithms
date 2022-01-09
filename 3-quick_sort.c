#include "sort.h"

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quickSort_recursion(array, 0, (int)size - 1);
}

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
 *
 * Return:  return index if the pivot
 */

int partition(int array[], int low, int high)
{

	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * quickSort_recursion - recursive function for quicksort
 * @array: array to be sorted
 * @high: index of the right element
 * @low: index of the left element
 */

void quickSort_recursion(int array[], int low, int high)
{
	if (low < high)
	{
		if (low < high)
		{
			int pivot = partition(array, low, high);

			quickSort_recursion(array, low, pivot - 1);
			quickSort_recursion(array, pivot + 1, high);
		}
	}
}
