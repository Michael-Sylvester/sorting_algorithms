#include "sort.h"
/**
 * cocktail_sort_list - a sorting algorithm with bidirectional bubble sorting
 *@list:head pointer to first node
 *Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	listint_t *next = NULL;
	listint_t *prev = NULL;
	listint_t *leftsort = NULL;
	listint_t *rightsort = NULL;
	int sorted = 0;

	if (list != NULL && *list != NULL)
		{
			temp = *list;
			prev = temp;
			next = temp->next;
		}
	else
		return;

	while (!sorted)
	{
		sorted = 1;
		next = temp->next;
		while (next != NULL && next != rightsort)
		{

			if (temp->n > next->n)
			{
				listswap(temp, next, list);
				sorted = 0;
				next = temp->next;
				print_list(*list);
			}
			else
			{
				temp = next;
				next = temp->next;
			}
		}
		rightsort = temp;
		prev = temp->prev;
		while (prev != NULL && prev != leftsort)
		{
			if (temp->n < prev->n)
			{
				listswap(prev, temp, list);				
				sorted = 0;
				prev = temp->prev;
				print_list(*list);
			}
			else
			{
				temp = prev;
				prev = temp->prev;
			}
		}
		leftsort = temp;
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
