#include "sort.h"

/**
 *_swapnodes - Swaps nodes of a linked list.
 *@h: Pointer to the head of a linked list.
 *@n: The first  element to be swapped.
 *@m: The second element to be swapped.
 *
 *Return: void
 */

void _swapnodes(listint_t **h, listint_t **n, listint_t *m)
{
	(*n)->next = m->next;
	if (m->next != NULL)
		m->next->prev = *n;
	m->prev = (*n)->prev;
	m->next = *n;
	m->next = *n;
	if ((*n)->prev != NULL)
		(*n)->prev->next = m;
	else
		*h = m;
	(*n)->prev = m;
	*n = m->prev;
}

/**
 *insertion_sort_list - sorts a doubly linked list of
 *                      integers in ascending order
 *@list: Pointer to the doubly-linked list of integers
 *
 *Description: Prints the list after each swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *s, *t;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i != NULL; i = t)
	{
		t = i->next;
		s = i->prev;

		while (s != NULL && i->n < s->n)
		{
			_swapnodes(list, &s, i);
			print_list((const listint_t *)*list);
		}
	}
}
