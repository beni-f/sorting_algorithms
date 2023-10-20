#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - sort an array of integers in ascending order using Bubble sort
 * @array: pointer to an array
 * @size: size of the array
 *
 * Return: returns nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (array == NULL || size == 0) {
    return;
  }

	for (i = 0; i < size - 1; i++)
	{
		int flag = 0;
	for (j = 0; j < size - 1 - i; j++)
	{
		if (array[j] > array[j + 1])
		{
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			flag = 1;
		}
		print_array(array, size);
	}
	if (flag == 0)
		break;
	}
}
