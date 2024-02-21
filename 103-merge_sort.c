#include "sort.h"
/**
 * merge_sort - calles recursive merge sort
 *@array: the array to be sorted
 *@size: the size of the array
 *Return: the sorted array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2;
	int *temp = NULL;

	if (array == NULL || size <= 1)
		return;
	
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	
	memcpy(temp, array, size * sizeof(int));

	merge_sort(temp, mid);
	merge_sort(temp + mid, size - mid);
	merge(array, temp, temp + mid, mid, size - mid);
	free(temp);
}

/**
 *merge - merges two arrays in sorted order
 *@array: the array to be sorted
 *@larr: the left array
 *@rarr: The right array
 *@lsize: size of left array
 *@rsize: size of right array
 *Return: the sorted array
 */
void merge(int *array, int *larr, int *rarr, int lsize, int rsize)
{
	int i = 0;
	int j = 0;
	int k = 0;

	printf("Merging...\n");
	print_merge(larr, lsize, "left");
	print_merge(rarr, rsize, "right");

	while (i < lsize && j < rsize)
	{
		if (larr[i] <= rarr[j])
		{
			array[k] = larr[i];
			i++;
		}
		else
		{
			array[k] = rarr[j];
			j++;
		}
		k++;
	}
	finish_merge(larr, i, lsize, array, k);
	finish_merge(rarr, j, rsize, array, k);
	print_merge(larr, lsize + rsize, "Done");
}

/**
 *finish_merge - checks for more members in
 *               temp sorted array to add to main array
 *@temp_array: sorted array
 *@tsize: the size of the sorted array
 *@tindex: current working index of temp array
 *@array: the parent array
 *@index: the current working index of parent array
 *Return: the sorted array
 */
void finish_merge(int *temp_array, int tindex,
				  int tsize, int *array, int index)
{
	while (tindex < tsize)
	{
		array[index] = temp_array[tindex];
		tindex++;
		index++;
	}
}

/**
 *print_merge - print the progress of the merge sort
 *@array: the array to be sorted
 *@size: the size of the array
 *@msg: the mesgage to be displayed
 *Return: the sorted array
 */
void print_merge(int *array, int size, char *msg)
{
	int n = 0;

	printf("[%s]: ", msg);
	for (n = 0; n < size; n++)
	{
		printf("%d", array[n]);
		if (n < size - 1)
			printf(", ");
		else
			printf("\n");
	}
}
