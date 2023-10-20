#include <stdio.h>
#include "sort.h"
/**
 * insertion_sort_list - sorts a linked list of integers using insertion sort
 * @list: a doubly linked list
 *
 * returns: returns nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
			return;

	current = (*list)->next;


	while (current != NULL)
	{
			temp = current->next;
			while (current->prev != NULL && current->n < current->prev->n)
			{
					current->prev->next = current->next;
					if (current->next != NULL)
					{
							current->next->prev = current->prev;
					}

					current->next = current->prev;
					current->prev = current->prev->prev;

					if (current->prev != NULL)
					{
							current->prev->next = current;
					}
					else
							*list = current;
					current->next->prev = current;
					print_list(*list);
			}
			current = temp;
	}
}

