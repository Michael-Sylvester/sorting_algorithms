#include "sort.h"
/**
 * bubble_sort - a bubble sort function for arrays
 *@array: the array to be sorted
 *@size: the size of the array
 *Return: the sorted array
 */
void bubble_sort(int *array, size_t size)
{
	int sorted = 0;
	size_t n = 0;

	while (sorted == 0 && array != NULL)
	{
		sorted = 1;
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap(array, n, n + 1);
				print_array(array, size);
				sorted = 0;
			}
		}

	}
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
