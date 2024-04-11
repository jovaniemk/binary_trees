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
 * avl_insert - Inserts a value in an AVL Tree.
 *              (if the address stored in tree is NULL,
 *               the created node must become the root node).
 *
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 *
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	new_node = bst_insert(tree, value);
	*tree = bst_balance(*tree, value, 1);
	return (new_node);
}
