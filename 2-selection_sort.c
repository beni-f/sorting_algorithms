#include <stdio.h>
#include "sort.h"
/**
 * selection_sort - sorts an array of integers using Selection sort
 * @array: pointer to an integer array
 * @size: size of the array
 *
 * return: Returns nothing
*/
void selection_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
			return;

	else
	{
			size_t i, j, min = 0, temp;

			for (i = 0; i < size - 1; i++)
			{
					min = i;
					for (j = i + 1; j < size; j++)
					{
							if (array[j] < array[min])
							{
									min = j;
							}
					}
					if (min != i)
					{
							temp = array[min];
							array[min] = array[i];
							array[i] = temp;
							print_array(array, size);
					}
			}
	}
}
