#include "binary_trees.h"
#include "limits.h"

/**
 * bst_helper - Determines if a binary tree is a valid binary search tree.
 *
 * @tree: A pointer to the root node of the tree to examine.
 * @low: The value of the smallest node encountered so far.
 * @high: The value of the largest node encountered so far.
 *
 * Return: Returns 1 if the tree is a valid BST, and 0 otherwise.
 */
int bst_helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		return (bst_helper(tree->left, low, tree->n - 1) &&
				bst_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid binary search tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: Returns 1 if the tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}

