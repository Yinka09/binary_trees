/**
 * bst_search - Searches for a value in a Binary Search Tree (BST).
 *
 * @tree: A pointer to the root of the BST.
 * @value: The value to search for in the BST.
 *
 * Return: If the value is found, returns a pointer to the matching node.
 *         Otherwise, returns NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree != NULL)
    {
        if (tree->n == value)
            return ((bst_t *)tree);
        if (tree->n > value)
            return (bst_search(tree->left, value));
        return (bst_search(tree->right, value));
    }

    return (NULL);
}

