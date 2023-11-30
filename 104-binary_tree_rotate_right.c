/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree.
 * @tree: A pointer to the root of the binary tree.
 *
 * Return: If the tree is NULL or has no left child, returns NULL.
 *         Otherwise, returns a pointer to the new root after rotation.
 *
 * Description: The left child of the input tree becomes the new root,
 *              and the original root becomes the right child of the new root.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *pivot, *tmp;

    if (tree == NULL || tree->left == NULL)
        return (NULL);

    pivot = tree->left;
    tmp = pivot->right;
    pivot->right = tree;
    tree->left = tmp;

    if (tmp != NULL)
        tmp->parent = tree;

    tmp = tree->parent;
    tree->parent = pivot;
    pivot->parent = tmp;

    if (tmp != NULL)
    {
        if (tmp->left == tree)
            tmp->left = pivot;
        else
            tmp->right = pivot;
    }

    return (pivot);
}