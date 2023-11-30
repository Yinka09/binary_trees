#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * check_max - Recursively checks if all nodes in a binary tree have max values.
 * @tree: Pointer to the root node.
 *
 * Return: 1 if all nodes have max values, 0 otherwise.
 *
 * Description: This function recursively checks if all nodes in the binary tree
 * have values greater than their children, indicating a max heap property.
 */
int check_max(const binary_tree_t *tree)
{
	int temp1 = 1, temp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		temp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		temp2 = check_max(tree->right);
	}
	return (temp1 && temp2);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: Pointer to the root node.
 *
 * Return: 1 if the tree is a max heap, 0 otherwise.
 *
 * Description: This function checks if the binary tree is a complete binary
 * tree (using binary_tree_is_complete) and then verifies the max heap
 * property by calling check_max.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int temp;

	if (!tree)
		return (0);

	temp = binary_tree_is_complete(tree);
	if (!temp)
		return (0);
	return (check_max(tree));
}

