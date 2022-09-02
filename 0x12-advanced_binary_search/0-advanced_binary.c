#include "search_algos.h"

/**
 * @brief 
 * 
 */
int search_advanced(int *array, int first, int last, int value)
{
	int index = 0, splitArr = 0;

	splitArr = first + (last - first) / 2;
	if (first == last)
	{
		if (value > array[last] || value < array[first])
		{
			printf("Searching in array: %d\n", array[splitArr]);
			return -1;
		}
		return first;
	}
	printf("Searching in array:");
	for (index = first; index <= last; index++)
	{
		if (index == last)
			printf(" %d\n", array[index]);
		else
			printf(" %d,", array[index]);	
	}
	// Recursive mode
	if (array[splitArr] > value)
		return (search_advanced(array, first, splitArr, value));
	else
		return (search_advanced(array, splitArr + 1, last, value));
}

/**
 * advanced_binary - Entry point
 * @array: Pointer to the first element of the array to search
 * @size: Is the number of elements in array
 * @value: Is the value to search for
 *
 * Return: Always EXIT_SUCCESS
 */
int advanced_binary(int *array, size_t size, int value) {
	if (array)
		return (search_advanced(array, 0, size - 1, value));
	return (-1);
}
