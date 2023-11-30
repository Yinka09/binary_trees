/**
 * binary_tree_preorder - Applies a function to each node in a binary tree
 *                        using preorder traversal.
 *
 * @tree: Pointer to the root of the binary tree.
 * @func: Pointer to the function to be applied to each node's value.
 *
 * Description: Traverses the binary tree in a preorder fashion and applies
 *              the given function to each node's value.
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
