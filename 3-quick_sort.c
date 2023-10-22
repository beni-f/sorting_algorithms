#include <stdio.h>
#include "sort.h"
/**
 * swap - swaps two integers
 *
 * @a: integer input
 * @b: integer input
 *
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - uses Lomuto partition scheme to sort integers
 *
 * @array: pointer to an array
 * @low: the first entry of the array
 * @high: the last entry of the array
 *
 * Return: Returns the index of the sorted array position
*/
int partition(int *array, ssize_t low, ssize_t high)
{
	ssize_t pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
			if (array[j] < pivot)
			{
					i++;
					swap(&array[i], &array[j]);
			}
	}
	swap(&array[i + 1], &array[high]);
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
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pi;

	while (low < high)
	{
			pi = partition(array, low, high);

			quicksort(array, low, pi - 1, size);
			quicksort(array, pi + 1, high, size);
			print_array(array, size);
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
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
	print_array(array, size);
}
