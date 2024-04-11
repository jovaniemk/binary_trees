#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete - Helper function to check if a tree is complet.
 *
 * @tree: Pointer to the current node in the binary tree.
 * @i: Index of the current node in the array representation of the binary tree
 * @s: Total number of nodes in the binary tree.
 *
 * Return: 1 if tree is comlete and 0 if not.
 */
int is_complete(const binary_tree_t *tree, size_t i, size_t s)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (1);

	if (i >= s)
		return (0);

	left = tree->left;
	right = tree->right;

	return (is_complete(left, 2 * i + 1, s) * is_complete(right, 2 * i + 2, s));
}

/**
 * binary_tree_is_complete - hecks if a binary tree is complete.
 *
 * @tree: Pointer to the root node of the tree to traverse.
 *
 * Return: 1 if the tree is compler 0 if not complet or NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size;

	if (tree == NULL)
		return (0);

	tree_size = binary_tree_size(tree);

	return (is_complete(tree, 0, tree_size));
}
