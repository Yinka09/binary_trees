#include "binary_trees.h"
/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST).
 *
 * @tree: A pointer to the root of the BST.
 * @value: The value to insert into the BST.
 *
 * Return: If the insertion is successful, returns a pointer to the new node.
 *         Otherwise, returns NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *current, *new;

    if (tree != NULL)
    {
        current = *tree;

        if (current == NULL)
        {
            new = binary_tree_node(current, value);
            if (new == NULL)
                return (NULL);
            return (*tree = new);
        }

        if (value < current->n) /* Insert in the left subtree */
        {
            if (current->left != NULL)
                return (bst_insert(&current->left, value));

            new = binary_tree_node(current, value);
            if (new == NULL)
                return (NULL);
            return (current->left = new);
        }

        if (value > current->n) /* Insert in the right subtree */
        {
            if (current->right != NULL)
                return (bst_insert(&current->right, value));

            new = binary_tree_node(current, value);
            if (new == NULL)
                return (NULL);
            return (current->right = new);
        }
    }

    return (NULL);
}

