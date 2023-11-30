#include "binary_trees.h"

/**
 * calculate_tree_size - Measures the sum of heights of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: Height or 0 if the tree is NULL.
 */
size_t calculate_tree_size(const binary_tree_t *tree)
{
    size_t left_height = 0;
    size_t right_height = 0;

    if (!tree)
        return (0);

    if (tree->left)
        left_height = 1 + calculate_tree_size(tree->left);

    if (tree->right)
        right_height = 1 + calculate_tree_size(tree->right);

    return (left_height + right_height);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array of integers.
 * @heap: Pointer to the root node of the heap to convert.
 * @size: Address to store the size of the array.
 *
 * Return: Pointer to the array sorted in descending order.
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int i, *sorted_array = NULL;

    if (!heap || !size)
        return (NULL);

    *size = calculate_tree_size(heap) + 1;

    sorted_array = malloc(sizeof(int) * (*size));

    if (!sorted_array)
        return (NULL);

    for (i = 0; heap; i++)
        sorted_array[i] = heap_extract(&heap);

    return (sorted_array);
}

