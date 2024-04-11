#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *new_node;

	/* In Case the tree is empty */
	if (*tree == NULL)
	{
		new_node = binary_tree_node(*tree, value);
		*tree = new_node;
		return (new_node);
	}

	/* Insert to right if value is greater than n */
	if ((*tree)->n < value && (*tree)->right == NULL)
	{
		new_node = binary_tree_node(*tree, value);
		(*tree)->right = new_node;
		return (new_node);
	}
	else if ((*tree)->n < value && (*tree)->right != NULL)
		return (bst_insert(&(*tree)->right, value));

	/* Insert to left if value is greater than n */
	if ((*tree)->n > value && (*tree)->left == NULL)
	{
		new_node = binary_tree_node(*tree, value);
		(*tree)->left = new_node;
		return (new_node);
	}
	else if ((*tree)->n > value && (*tree)->left != NULL)
		return (bst_insert(&(*tree)->left, value));

	/* Return NULL if value is equal to n */
	return (NULL);
}
