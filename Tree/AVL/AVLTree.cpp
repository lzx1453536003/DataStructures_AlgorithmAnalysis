#include <stdio.h>
#include<stdlib.h>
#include "AVLTree.h"

#define HEIGHT(TREE) ((p==nullptr) ? 0 : p->height)
#define MAX_HEIGHT(a, b) (((a)>(b)) ? a : b) 
#define Abs(a) ((a>0)? a : -a)

static AVLTree llrotation_avltree(AVLTree tree)
{
	AVLTree _tree;
	if (!tree)
	{
		return tree;
	}
	if (!tree->left_child || !tree->left_child->left_child)
	{
		return tree;
	}
	_tree = tree->left_child;
	tree->left_child = _tree->right_child;
	tree->height = MAX_HEIGHT(HEIGHT(tree->left_child), HEIGHT(tree->right_child)) + 1;
	_tree->right_child = tree;
	_tree->height = MAX_HEIGHT(HEIGHT(_tree->left_child), HEIGHT(_tree->right_child)) + 1;

	return _tree;
}
static AVLTree lrrotation_avltree(AVLTree tree)
{
	if (!tree)
		return nullptr;
	if (!tree->left_child || !tree->left_child->right_child)
		return tree;
	tree->left_child = rrrotation_avltree(tree->left_child);
	tree = llrotation_avltree(tree);
	return tree;
}
static AVLTree rlrotation_avltree(AVLTree tree)
{
	if (!tree)
		return nullptr;
	if (!tree->right_child || !tree->right_child->left_child)
		return tree;
	tree->right_child = llrotation_avltree(tree->right_child);
	tree = rrrotation_avltree(tree);
	return tree;
}
static AVLTree rrrotation_avltree(AVLTree tree)
{
	AVLTree _tree;
	if (!tree)
	{
		return tree;
	}
	if (!tree->right_child || !tree->right_child->right_child)
	{
		return tree;
	}
	_tree = tree->right_child;
	tree->right_child = _tree->left_child;
	tree->height = MAX_HEIGHT(HEIGHT(tree->left_child), HEIGHT(tree->right_child)) + 1;
	_tree->left_child = tree;
	_tree->height = MAX_HEIGHT(HEIGHT(_tree->left_child), HEIGHT(_tree->right_child)) + 1;

	return _tree;
}


AVLTree create_avltree(KeyType key)
{
	AVLTree tree = (AVLTree)malloc(sizeof(TreeNode));
	if (!tree)
	{
		puts("memory out \n");
		return nullptr;
	}
	tree->key = key;
	tree->height = 1;
	tree->left_child = nullptr;
	tree->right_child = nullptr;
	return tree;

}
void destroy_avltree(AVLTree tree)
{
	if (!tree)
		return;
	destroy_avltree(tree->left_child);
	destroy_avltree(tree->right_child);
	free(tree);

}

AVLTree insert_avltree(AVLTree tree, KeyType key)
{
	if (!tree)
		return create_avltree(key);
	if (tree->key > key)
	{
		tree->left_child = insert_avltree(tree->left_child, key);
		if (HEIGHT(tree->left_child) - HEIGHT(tree->right_child) >= 2)
		{
			if (key < tree->left_child->key)
				tree = llrotation_avltree(tree);
			else if (key > tree->left_child->key)
				tree = lrrotation_avltree(tree);
		}
	}
	else if (tree->key < key)
	{
		tree = insert_avltree(tree->right_child, key);
		if (HEIGHT(tree->right_child) - HEIGHT(tree->left_child) >= 2)
		{
			if (key < tree->right_child->key)
				tree = rlrotation_avltree(tree);
			else if (key > tree->right_child->key)
				tree = rrrotation_avltree(tree);
		}
	}
	tree->height = MAX_HEIGHT(HEIGHT(tree->left_child), HEIGHT(tree->right_child)) + 1;
	return tree;
}
AVLTree delete_avltree(AVLTree tree, KeyType key)
{
	if (!tree)
	{
		return nullptr;
	}
	if (tree->key > key)
	{
		tree->left_child = delete_avltree(tree->left_child, key);
		if (HEIGHT(tree->right_child) - HEIGHT(tree->left_child) >= 2)
		{
			if (HEIGHT(tree->right_child->left_child) > HEIGHT(tree->right_child->right_child))
				tree = rlrotation_avltree(tree);
			else
				tree = rrrotation_avltree(tree);
		}
	}
	else if (tree->key < key)
	{
		tree->right_child = delete_avltree(tree->right_child, key);
		if (HEIGHT(tree->left_child) - HEIGHT(tree->right_child) >= 2)
		{
			if (HEIGHT(tree->left_child->right_child) > HEIGHT(tree->left_child->left_child))
				lrrotation_avltree(tree);
			else
				llrotation_avltree(tree);
		}
	}
	else
	{
		if (tree->left_child && tree->right_child)
		{
			if (HEIGHT(tree->left_child) > HEIGHT(tree->right_child))
			{
				//ÕÒµ½left_child max £¬¸³Öµ£¬É¾³ý

			}
			else
			{
				//ÕÒµ½right_child min £¬¸³Öµ£¬É¾³ý

				
			}
		}
		else
		{
			TreeNode* node = tree;
			tree = tree->left_child ? tree->left_child : tree->right_child;
			free(node);
		}
	}

	return tree;
}
