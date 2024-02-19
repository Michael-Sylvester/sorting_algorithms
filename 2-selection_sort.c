#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 *                  ascending order using the Selection sort algorithm
 *@array: The array of integers
 *@size: the size of the array
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	/*the 1st unsorted member of the array*/
	size_t s_head = 0;
	size_t index = 0;
	size_t smallest = 0;
	int sorted = 0;

	while (array != NULL && s_head < size)
	{
		smallest = s_head;
		sorted = 1;
		for (index = s_head + 1; index < size; index++)
		{
			if (array[smallest] >= array[index])
				smallest = index;
		}
		/*Check if array is fullly ordered*/
		for (index = 0; index < size - 1; index++)
		{
			if (array[index] >= array[index + 1])
				sorted = 0;
		}

		if (sorted)
			break;
		if (s_head != smallest)
		{
			swap(array, s_head, smallest);
			print_array(array, size);
		}
		s_head++;

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
