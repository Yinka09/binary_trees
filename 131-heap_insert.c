#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root node of the Heap for value insertion.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node.
 *         NULL on failure.
 *
 * Description: This function inserts a new node with the given value into the
 * Max Binary Heap pointed to by root. It ensures the max heap property and
 * returns the pointer to the newly inserted node.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *turn;
	int size, leaf, substitute, byte, lev, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaf = size;
	for (lev = 0, substitute = 1; leaf >= substitute; substitute *= 2, lev++)
		leaf -= substitute;

	for (byte = 1 << (lev - 1); byte != 1; byte >>= 1)
		tree = leaf & byte ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	leaf & 1 ? (tree->right = new_node) : (tree->left = new_node);

	turn = new_node;
	for (; turn->parent && (turn->n > turn->parent->n); turn = turn->parent)
	{
		temp = turn->n;
		turn->n = turn->parent->n;
		turn->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Tree to measure the size of.
 *
 * Return: Size of the tree.
 *         0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

