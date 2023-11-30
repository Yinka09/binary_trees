#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_queue_node - Creates a new node for a level-order traversal queue.
 *
 * @node: Pointer to the binary tree node to be stored in the new queue node.
 *
 * Return: If an error occurs or malloc fails, returns NULL.
 *         Otherwise, returns a pointer to the newly created queue node.
 */
levelorder_queue_t *create_queue_node(binary_tree_t *node)
{
    levelorder_queue_t *new;

    new = malloc(sizeof(levelorder_queue_t));
    if (new == NULL)
        return (NULL);

    new->node = node;
    new->next = NULL;

    return (new);
}

/**
 * free_queue - Frees memory allocated for a level-order traversal queue.
 *
 * @head: A pointer to the head of the queue to be freed.
 */
void free_queue(levelorder_queue_t *head)
{
    levelorder_queue_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

/**
 * pint_push - Applies a function to a binary tree node and enqueues its children.
 *
 * @node: The binary tree node to be processed and enqueued.
 * @head: Pointer to the head of the level-order traversal queue.
 * @tail: Double pointer to the tail of the level-order traversal queue.
 * @func: Pointer to the function to call on each node's value.
 *
 * Description: Enqueues the children of the given node into the queue
 *              after applying the specified function to the node's value.
 *              Exits with a status code of 1 upon malloc failure.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
               levelorder_queue_t **tail, void (*func)(int))
{
    levelorder_queue_t *new;

    func(node->n);
    if (node->left != NULL)
    {
        new = create_queue_node(node->left);
        if (new == NULL)
        {
            free_queue(head);
            exit(1);
        }
        (*tail)->next = new;
        *tail = new;
    }
    if (node->right != NULL)
    {
        new = create_queue_node(node->right);
        if (new == NULL)
        {
            free_queue(head);
            exit(1);
        }
        (*tail)->next = new;
        *tail = new;
    }
}

/**
 * pop - Removes the head of a level-order traversal queue.
 *
 * @head: Double pointer to the head of the queue.
 *
 * Description: Dequeues the front node of the level-order traversal queue
 *              and updates the head pointer accordingly.
 */
void pop(levelorder_queue_t **head)
{
    levelorder_queue_t *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree.
 *
 * @tree: Pointer to the root of the binary tree.
 * @func: Pointer to the function to call on each node's value.
 *
 * Description: Traverses the binary tree in level-order, applying the
 *              specified function to each node's value.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    levelorder_queue_t *head, *tail;

    if (tree == NULL || func == NULL)
        return;

    head = tail = create_queue_node((binary_tree_t *)tree);
    if (head == NULL)
        return;

    while (head != NULL)
    {
        pint_push(head->node, head, &tail, func);
        pop(&head);
    }
}
