#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
/**
 * is_avl - Utility function to recursively check if a tree is a valid AVL.
 *
 * @node: Current node being checked.
 * @min: Minimum value the node's data can take (inclusive).
 * @max: Maximum value the node's data can take (inclusive).
 *
 * Return: 1 if the tree rooted at 'node' is a valid avl, 0 otherwise.
 */
int is_avl(const binary_tree_t *node, int min, int max)
{
	int height_left, height_right;

	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	height_left = binary_tree_height(node->left);
	height_right = binary_tree_height(node->right);

	if (height_left - height_right != 0)
		return (0);

	return (is_avl(node->left, min, node->n - 1) *
		is_avl(node->right, node->n + 1, max));
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 if not or if tree is NULL.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl(tree, INT_MIN, INT_MAX));
}
