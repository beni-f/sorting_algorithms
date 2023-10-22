#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
    print_array(array, size);
}

int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}