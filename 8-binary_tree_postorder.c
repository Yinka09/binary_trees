#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a binary tree in inorder
 * @tree: pointer to the root node of the tree to traverse
 * Return: nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
