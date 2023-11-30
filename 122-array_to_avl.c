#include "binary_trees.h"

/**
 * array_to_avl - Converts an array of integers into an AVL tree.
 * @array: Pointer to the array of integers.
 * @size: Number of elements in the array.
 *
 * Return: A pointer to the root of the resulting AVL tree, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t m, n;

	if (array == NULL)
		return (NULL);

	for (m = 0; m < size; m++)
	{
		for (n = 0; n < m; n++)
		{
			if (array[n] == array[m])
				break;
		}
		if (n == m)
		{
			if (avl_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}

