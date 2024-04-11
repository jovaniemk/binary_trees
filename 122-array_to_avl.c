#include "binary_trees.h"

/**
 * array_to_avl - Builds a Binary Search Tree from an array.
 *
 * @array: Pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: Pointer to the root node of the created avl, or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (array == NULL || size <= 0)
		return (NULL);

	root = avl_insert(&root, array[0]);

	for (i = 1; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
