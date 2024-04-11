#include "binary_trees.h"

/**
 * is_bst - Utility function to recursively check if a binary tree
 *          is a valid Binary Search Tree.
 *
 * @node: Current node being checked.
 * @min: Minimum value the node's data can take (inclusive).
 * @max: Maximum value the node's data can take (inclusive).
 *
 * Return: 1 if the tree rooted at 'node' is a valid BST, 0 otherwise.
 */
int is_bst(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (is_bst(node->left, min, node->n - 1) *
		is_bst(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 *
 * @tree: Phecks if a binary tree is a valid Binary Search Tree.
 *
 * Return: 1 if tree is a valid BST and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}
