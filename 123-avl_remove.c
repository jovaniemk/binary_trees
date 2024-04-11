#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree,
 *              If the node to be deleted has two children,
 *              it must be replaced with its first in-order successor
 *              (not predecessor).
 *
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the node.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	else if (value > root->n)
		root->right = bst_remove(root->right, value);

	else
	{
		/* If the value found in a leaf or a node with one child */
		if (root->left == NULL)
		{
			tmp = root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (tmp);
		}

		/* It the vakue found in a node with two childs */
		tmp = root->right;
		while (tmp != NULL && tmp->left != NULL)
			tmp = tmp->left;
		root->n = tmp->n;

		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}

/**
 * bst_balance - Balance a binary search tree to get AVL tree.
 *
 * @tree: Double pointer to the root of the bst tree.
 * @key: Node key to balance on it.
 * @mode: 1 for using the function while inserting and 0 while deleting.
 *
 * Return: Pointer to the balance tree.
 */
binary_tree_t *bst_balance(binary_tree_t *tree, int key, int mode)
{
	int balance;

	if (tree == NULL)
		return (NULL);

	tree->left = bst_balance(tree->left, key, mode);
	tree->right = bst_balance(tree->right, key, mode);

	balance = binary_tree_balance(tree);
	if (balance > 1)
	{
		if (key > tree->left->n && mode)
			tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	else if (balance < -1)
	{
		if (key < tree->right->n && mode)
			tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

/**
 * avl_remove - Removes a node from an AVL tree,
 *              If the node to be deleted has two children,
 *              it must be replaced with its first in-order successor
 *              (not predecessor).
 *
 * @root: Pointer to the root node of the tree where you will remove a node.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the node.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = bst_remove(root, value);
	root = bst_balance(root, value, 0);
	return (root);
}
