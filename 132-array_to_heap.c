#include "binary_trees.h"

/**
 * array_to_heap - Constructs a Max Binary Heap tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created Binary Heap.
 *         NULL on failure.
 *
 * Description: This function builds a Max Binary Heap tree from
 * the given array.
 * It iterates through each element in the array and inserts them
 * into the heap
 * using the heap_insert function. The resulting root node of the
 * Binary Heap is
 * returned, or NULL in case of failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int m;
	heap_t *root = NULL;

	for (m = 0; m < size; m++)
		heap_insert(&root, array[m]);

	return (root);
}

