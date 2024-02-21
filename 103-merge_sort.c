#include "sort.h"
/**
 * merge_sort - calles recursive merge sort
 *@array: the array to be sorted
 *@size: the size of the array
 *Return: the sorted array
 */
void merge_sort(int *array, size_t size)
{
	true_merge_sort(array, 0, size - 1);
}

/**
 * true_merge_sort - recursiveky calls itself to divide array and sort
 *@array: the array to be sorted
 *@low: The first index of the array
 *@high: the last index of the array
 *Return: the sorted array
 */
void true_merge_sort(int *array, int low, int high)
{
	int mid = (high + low) / 2;

	if (low < high)
	{
		true_merge_sort(array, low, mid);
		true_merge_sort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}

/**
 * merge - merges two arrays in sorted order
 *@array: the array to be sorted
 *@low: The first index of the array
 *@mid: The midle index of the array
 *@high: the last index of the array
 *Return: the sorted array
 */
void merge(int *array, int low, int mid, int high)
{
	int left, right, new;
	int const lsize = mid - low + 1;
	int const rsize = high - mid;
	int *larr = malloc((lsize + rsize) * sizeof(int));
	int *rarr = larr + lsize;

	if (larr == NULL)
		return;
	for (left = 0; left < lsize; left++)
	{
		larr[left] = array[low + left];
	}
	for (right = 0; right < rsize; right++)
	{
		rarr[right] = array[mid + 1 + right];
	}
	right = 0;
	left = 0;
	new = low;
	printf("Merging...\n");
	print_merge(larr, lsize, "left");
	print_merge(rarr, rsize, "right");
	while (left < lsize && right < rsize)
	{
		if (larr[left] <= rarr[right])
		{
			array[new] = larr[left];
			left++;
		}
		else
		{
			array[new] = rarr[right];
			right++;
		}
		new++;
	}
	finish_merge(larr, left, lsize, array, new);
	finish_merge(rarr, right, rsize, array, new);
	print_merge(larr, lsize + rsize, "done");
	free(larr);
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
