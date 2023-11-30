#include "binary_trees.h"

/**
 * height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: If the tree is NULL, the function returns 0; otherwise,
 * it returns the height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = tree->left ? 1 + height(tree->left) : 1;
		size_t right_height = tree->right ? 1 + height(tree->right) : 1;

		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * balance - Calculates the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: If the tree is NULL, the function returns 0; otherwise,
 * it returns the balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Recursively inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		 avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to insert.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}

