#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of a node.
 *
 * @parent: Pointer to the parent node.
 * @value: Value to be stored in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);

	if (parent->left)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
