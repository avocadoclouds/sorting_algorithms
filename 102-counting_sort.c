#include "sort.h"

/**
* max_number - finds the maximum number in array
*
* @array: array to be checked
*
* @size: size of the array
*
* Return: maxiumum nuber
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
* counting_sort - this function is used to sort
*                 array using counting algorithm
*
* @array: the array to be sorted
*
* @size: the size of array
*
* Return: Nothing
*/

void counting_sort(int *array, size_t size)
{
	size_t i;
	int max, j;
	int *new, *output;

	if (size < 2)
		return;
	max = max_number(array, size);
	new = malloc(sizeof(int) * (max + 1));
	if (new == 0)
		return;
	output = malloc(sizeof(int) * (size + 1));
	if (output == 0)
		return;
	for (j = 0; j <= max; j++)
	{
		new[j] = 0;
	}
	for (i = 0; i < size; i++)
	{
		new[array[i]]++;
	}
	for (j = 1; j <= max; j++)
	{
		new[j] += new[j - 1];
	}
	print_array(new, max + 1);
	for (i = 0; i < size; i++)
	{
		output[new[array[i] - 1]] = array[i];
		new[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(new);
	free(output);
}
