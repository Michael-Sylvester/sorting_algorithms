#include "sort.h"
/**
 * quick_sort -  calls the recursive function that sorts array
 *@array: the array to be sorted
 *@size: the size of the array
 *Return: the sorted array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 0)
		true_quick_sort(array, 0, size - 1, size);

}

/**
 * true_quick_sort -  sorts an array of integers in ascending
 *               order using the Quick sort algorithm
 *@array: the array to be sorted
 *@low: lowest unsorted member of array
 *@high: the last member of the array
 *@size: the size of the array
 *Return: nothing
 */
void true_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot_index = 0;

	if (low < high)
	{
		pivot_index = Lomuto_partition(array, low, high, size);
		true_quick_sort(array, low, pivot_index - 1, size);
		true_quick_sort(array, pivot_index + 1, high, size);
	}
}

/**
 * Lomuto_partition - uses Lomuto partition to
 *                    divide array for quick sort
 *@array: the array to be sorted
 *@low: lowest unsorted member of array
 *@high: the last member of the array
 *@size: the size of the array
 *Return: the sorted array
 */
int Lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(array, i + 1, high);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * swap - exchange the positions of 2 elemnts of an array
 *@array: the array to be sorted
 *@pos1: the first position
 *@pos2: the 2nd position
 *Return: the sorted array
 */
void swap(int *array, size_t pos1, size_t pos2)
{
	int temp = array[pos1];

	array[pos1] = array[pos2];
	array[pos2] = temp;

}
