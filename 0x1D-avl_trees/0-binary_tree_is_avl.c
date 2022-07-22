#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if a binary tree is AVL
 * @tree: the root node of the tree
 * Return: 1 if is AVl 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_l, height_r, d;

	if (tree == NULL)
		return (0);

	height_l = height(tree->left);
	height_r = height(tree->right);

	d = height_l > height_r ? height_l - height_r : height_r - height_l;
	if (d <= 1 && binary_tree_is_avl(tree->left) &&
				(binary_tree_is_avl(tree->right)))
		return (1);

	return (0);

}
/**
 * height - the height of each part of the node
 * @ptr: the node to check
 * Return: the numer of node to check if balanced
 */
int height(binary_tree_t *ptr)
{
	int h_left, h_right;

	if (ptr == NULL)
		return (0);

	h_left = height(ptr->left);
	h_right = height(ptr->right);

	if (h_left > h_right)
	{
		return (1 + h_left);
	}
	return (1 + h_right);
}
