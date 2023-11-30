#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root of the binary tree.
 *
 * Return: If the tree is NULL or has no right child, returns NULL.
 *         Otherwise, returns a pointer to the new root after rotation.
 *
 * Description: The right child of the input tree becomes the new root,
 *              and the original root becomes the left child of the new root.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *start, *temp;

    if (tree == NULL || tree->right == NULL)
        return (NULL);

    start = tree->right;
    temp = start->left;
    start->left = tree;
    tree->right = temp;

    if (temp != NULL)
        temp->parent = tree;

    temp = tree->parent;
    tree->parent = start;
    start->parent = temp;

    if (temp != NULL)
    {
        if (temp->left == tree)
            temp->left = start;
        else
            temp->right = start;
    }

    return (start);
}
