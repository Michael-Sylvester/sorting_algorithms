#include "sort.h"

/**
 * insertion_sort_list - uses Inserrtion sort to arrange a linked list
 *
 * @list: double pointer to the head of a doubley linked list
 *
 * Return: nothin
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list;
	listint_t *next = temp;
	listint_t *prev = temp;
	int swaped = 0;

	if (temp != NULL)
		next = temp->next;
	else
		next = NULL;
	while (next != NULL)
	{
		prev = temp;
		swaped = 0;

		while (prev != NULL && prev->n > next->n)
		{
			listswap(prev, next, list);
			prev = next->prev;
			print_list(*list);
			swaped = 1;
		}
		if (!swaped)
			temp = temp->next;
		next = temp->next;
	}
}

/**
 * listswap - swap the positions of 2 nodes in a double linked list
 *
 * @next_pos: pointer to the node furthest from the head
 * @prev_pos: pointer to the node closest to the head
 * @list: head pointer for the list
 * Return: nothin
 */
void listswap(listint_t *prev_pos, listint_t *next_pos, listint_t **list)
{
	listint_t *temp = next_pos->next;

	if (temp != NULL)
		temp->prev = prev_pos;
	prev_pos->next = temp;

	temp = prev_pos->prev;
	if (temp != NULL)
		temp->next = next_pos;
	else
		*list = next_pos;
	next_pos->prev = temp;

	next_pos->next = prev_pos;
	prev_pos->prev = next_pos;

}
