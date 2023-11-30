#include "binary_trees.h"

/**
 * create_tree - Recursively creates an AVL tree.
 *
 * @node: Pointer to the current node.
 * @array: Input array of integers.
 * @size: Size of the array.
 * @mode: 1 to add on the left, 2 to add on the right.
 *
 * Description: This function recursively creates an AVL tree based on the
 * input array, starting from the given node and following the specified mode.
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t mid;

	if (size == 0)
		return;

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		create_tree(&((*node)->left), array, mid, 1);
		create_tree(&((*node)->left), array + mid + 1, (size - 1 - mid), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		create_tree(&((*node)->right), array, mid, 1);
		create_tree(&((*node)->right), array + mid + 1, (size - 1 - mid), 2);
	}
}

/**
 * sorted_array_to_avl - Creates the root node and calls create_tree.
 *
 * @array: Input array of integers.
 * @size: Size of the array.
 *
 * Return: Pointer to the root of the AVL tree.
 *
 * Description: This function creates the root node for an AVL tree and then
 * calls create_tree to recursively build the AVL tree from the sorted array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t mid;

	root = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);
	mid = (size % 2 == 0) ? mid - 1 : mid;

	root = binary_tree_node(root, array[mid]);

	create_tree(&root, array, mid, 1);
	create_tree(&root, array + mid + 1, (size - 1 - mid), 2);

	return (root);
}

