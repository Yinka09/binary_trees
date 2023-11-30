#include "binary_trees.h"

/**
 * bal - Calculates the balance factor of an AVL tree.
 * @tree: Pointer to the AVL tree to calculate the balance factor.
 *
 * Description: Recursively checks and balances the AVL tree based on its
 * balance factor. Performs rotations if necessary to maintain balance.
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the minimum node value in the right subtree.
 * @node: Node to check for the next successor.
 *
 * Return: The minimum value in the right subtree.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);
	else
	{
		left = successor(node->left);
		if (left == 0)
			return (node->n);
		return (left);
	}
}

/**
 * remove_type - Removes a node from a BST tree based on its children.
 * @root: Node to remove from the BST tree.
 *
 * Return: 0 if the node has no children, or the new value if it has children.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		/** Node has no children **/
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		/** Node has one child **/
		if (!root->left)
		{
			/** Node has only a right child **/
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			/** Node has only a left child **/
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		/** Node has two children **/
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: Root of the BST tree.
 * @value: Value of the node to remove.
 *
 * Return: The modified BST tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Root of the AVL tree.
 * @value: Value of the node to remove.
 *
 * Return: The modified AVL tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}

