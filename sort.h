#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Functions defined by ALX*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/*Functions defines by myself*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);

void swap(int *array, size_t pos1, size_t pos2);
void listswap(listint_t *prev_pos, listint_t *next_pos, listint_t **list);
int Lomuto_partition(int *array, int low, int high, size_t size);
void true_quick_sort(int *array, int low, int high, size_t size);
void true_merge_sort(int *array, int low, int high);
void merge(int *array, int *larr, int *rarr, int lsize, int rsize);
void print_merge(int *array, int size, char *msg);
int checkleft(listint_t **list, listint_t **temp,listint_t *leftsort);
void finish_merge(int *temp_array, int tindex,
				  int tsize, int *array, int *index);

#endif
