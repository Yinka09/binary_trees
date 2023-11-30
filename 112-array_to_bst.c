#include "binary_trees.h"

/**
 * array_to_bst - Converts an array of integers to a Binary Search Tree (BST).
 *
 * @array: Pointer to the array of integers.
 * @size: Size of the array.
 *
 * Return: A pointer to the root of the created BST.
 *         If the array is NULL or if an error occurs during insertion,
 *         returns NULL.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t m, n;

	if (array == NULL)
		return (NULL);

	for (m = 0; m < size; m++)
	{
		for (n = 0; n < i; n++)
		{
			if (array[n] == array[m])
				break;
		}
		if (n == m)
		{
			if (bst_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
