#include <stdio.h>
#include "sort.h"
/**
 * partition - uses Lomuto partition scheme to sort integers
 *
 * @array: pointer to an array
 * @low: the first entry of the array
 * @high: the last entry of the array
 *
 * Return: Returns the index of the sorted array position
*/
int partition(int *array, int low, int high, size_t size)
{
	int i, j, temp;

	i = low - 1;

	for (j = low; j < high; j++)
	{
			if (array[j] < array[high])
			{
					i++;
					if (i != j)
					{
							temp = array[i];
							array[i] = array[j];
							array[j] = temp;
							print_array(array, size);
					}	
			}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	
	return (i + 1);
}
/**
 * quicksort - sorts the integers in Quick sort algorithm
 *
 * @array: pointer to an array
 * @high: last entry of the array
 * @low: first entry of the array
 * @size: size of the array
*/
void quicksort(int *array, int low, int high, size_t size)
{
	ssize_t pi;

	if (high > low)
	{
			pi = partition(array, low, high, size);

			quicksort(array, low, pi - 1, size);
			quicksort(array, pi + 1, high, size);
	}
}
/**
 * quick_sort - sorts the integers
 *
 * @array: pointer to an array
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quicksort(array, 0, size - 1, size);
}
