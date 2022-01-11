#include "sort.h"

/**
* max_number - This function is used to find the
*              max number in array
*
* @array: the array to be checked
*
* @size: size of the array
*
* Return: the maximum number
*/

int max_number(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* radix_sort_count - this function is used to sort
*                    using counting sort algorithm
*                    for radix algorithm
*
* @array: the array to be sorted
*
* @size: the size of the array
*
* @div: the factor by which maximum number is divided
*
* Return: Nothing
*/

void radix_sort_count(int *array, size_t size, int div)
{
	int j;
	int *digit, *store;
	size_t i;

	digit = malloc(sizeof(int) * 10);
	store = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		digit[(array[i] / div) % 10]++;
	}
	for (j = 1; j < 10; j++)
	{
		digit[j] += digit[j - 1];
	}
	for (j = size - 1; j >= 0; j--)
	{
		store[digit[(array[j] / div) % 10] - 1] = array[j];
		digit[(array[j] / div) % 10]--;
	}
	print_array(store, size);
	for (i = 0; i < size; i++)
	{
		array[i] = store[i];
	}
}

/**
* radix_sort - this function is used to sort array
*              using radix sort algorithm
*
* @array: the array to be sorted
*
* @size: the size of the array
*
* Return: Nothing
*/

void radix_sort(int *array, size_t size)
{
	int max, div;

	max = max_number(array, size);
	for (div = 1; (max / div) > 0; div *= 10)
		radix_sort_count(array, size, div);
}
