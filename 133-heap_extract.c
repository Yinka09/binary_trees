#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height of the tree or 0 if the tree is NULL.
 */
size_t binary_tree_height(const heap_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
        return (0);

    if (tree->left)
        left_height = 1 + binary_tree_height(tree->left);

    if (tree->right)
        right_height = 1 + binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size_h - Measures the sum of heights of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Sum of heights or 0 if the tree is NULL.
 */
size_t binary_tree_size_h(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
        return (0);

    if (tree->left)
        left_height = 1 + binary_tree_size_h(tree->left);

    if (tree->right)
        right_height = 1 + binary_tree_size_h(tree->right);

    return (left_height + right_height);
}

/**
 * preorder_traversal - Goes through a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @last_node: Will be the last node in the traversal.
 * @height: Height of the tree.
 *
 * Return: No return.
 */
void preorder_traversal(heap_t *tree, heap_t **last_node, size_t height)
{
    if (!tree)
        return;

    if (!height)
        *last_node = tree;
    height--;

    preorder_traversal(tree->left, last_node, height);
    preorder_traversal(tree->right, last_node, height);
}

/**
 * heapify_max_heap - Heapifies a max binary heap.
 * @root: Pointer to the binary heap.
 */
void heapify_max_heap(heap_t *root)
{
    int value;
    heap_t *current, *max_child;

    if (!root)
        return;

    current = root;

    while (1)
    {
        if (!current->left)
            break;
        if (!current->right)
            max_child = current->left;
        else
            max_child = (current->left->n > current->right->n) ? current->left : current->right;

        if (current->n > max_child->n)
            break;

        value = current->n;
        current->n = max_child->n;
        max_child->n = value;
        current = max_child;
    }
}

/**
 * heap_extract_max - Extracts the root node from a Max Binary Heap.
 * @root: Pointer to the heap root.
 *
 * Return: Value of the extracted node.
 **/
int heap_extract_max(heap_t **root)
{
    int value;
    heap_t *heap_root, *last_node;

    if (!root || !*root)
        return (0);

    heap_root = *root;
    value = heap_root->n;

    if (!heap_root->left && !heap_root->right)
    {
        *root = NULL;
        free(heap_root);
        return (value);
    }

    preorder_traversal(heap_root, &last_node, binary_tree_height(heap_root));

    heap_root->n = last_node->n;

    if (last_node->parent->right)
        last_node->parent->right = NULL;
    else
        last_node->parent->left = NULL;

    free(last_node);
    heapify_max_heap(heap_root);
    *root = heap_root;

    return (value);
}

