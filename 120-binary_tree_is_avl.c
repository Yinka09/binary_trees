#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int avl_helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + height(tree->left) : 1;
		right_height = tree->right ? 1 + height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited thus far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t left_height, right_height, height_diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);

		left_height = height(tree->left);
		right_height = height(tree->right);
		height_diff = (left_height > right_height) ? left_height - right_height
			 : right_height - left_height;

		if (height_diff > 1)
			return (0);

		return (avl_helper(tree->left, low, tree->n - 1) &&
				avl_helper(tree->right, tree->n + 1, high));
	}

	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (avl_helper(tree, INT_MIN, INT_MAX));
}

