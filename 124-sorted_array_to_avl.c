#include "binary_trees.h"

/**
 * sorted_array_to_avl_builder - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl_builder(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);
	if (root == NULL)
		return (NULL);
	root->parent = parent;

	root->left = sorted_array_to_avl_builder(array, start, mid - 1, root);
	root->right = sorted_array_to_avl_builder(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (array == NULL || size <= 0)
		return (NULL);

	root = binary_tree_node(NULL, array[size / 2 - 1]);
	if (root == NULL)
		return (NULL);

	return (sorted_array_to_avl_builder(array, 0, size - 1, root));
}
