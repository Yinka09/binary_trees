#include "binary_trees.h"

/**
 * binary_tree_size - measures the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: number of nodes in the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_branch, right_branch;

	if (!tree)
		return (0);
	left_branch = binary_tree_size(tree->left);
	right_branch = binary_tree_size(tree->right);
	return (left_branch + right_branch + 1);
}
