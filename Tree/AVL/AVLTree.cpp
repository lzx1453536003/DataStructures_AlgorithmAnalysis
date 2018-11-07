#include<stdio.h>
#include<stdlib.h>
#include "AVLTree.h"



#define HEIGHT(p) ((p==nullptr) ? 0 : p->height)
#define MAX_HEIGHT(a, b) (((a)>(b)) ? a : b) 
#define Abs(a) ((a>0)? a : -a)

static AVLTree llrotation_avltree(AVLTree tree)
{
	AVLTree _tree;
	if (!tree)
	{
		return tree;
	}
	if (!tree->left_child)
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
static AVLTree rrrotation_avltree(AVLTree tree)
{
	AVLTree _tree;
	if (!tree)
	{
		return tree;
	}
	if (!tree->right_child)
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

static AVLTree lrrotation_avltree(AVLTree tree)
{
	if (!tree)
		return nullptr;
	/*if (!tree->left_child || !tree->left_child->right_child)
		return tree;*/
	tree->left_child = rrrotation_avltree(tree->left_child);
	tree = llrotation_avltree(tree);
	return tree;
}
static AVLTree rlrotation_avltree(AVLTree tree)
{
	if (!tree)
		return nullptr;
	/*if (!tree->right_child || !tree->right_child->left_child)
		return tree;*/
	tree->right_child = llrotation_avltree(tree->right_child);
	tree = rrrotation_avltree(tree);
	return tree;
}


AVLTree create_avltree(KeyType key)
{
	AVLTree tree = (AVLTree)malloc(sizeof(AVLNode));
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
		tree->right_child = insert_avltree(tree->right_child, key);
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
				tree = lrrotation_avltree(tree);
			else
				tree = llrotation_avltree(tree);
		}
	}
	else
	{
		if (tree->left_child && tree->right_child)
		{
			if (HEIGHT(tree->left_child) > HEIGHT(tree->right_child))
			{
				//ÕÒµ½left_child max £¬¸³Öµ£¬É¾³ı
				AVLNode* node = find_max_avltree(tree->left_child);
				tree->key = node->key;
				tree->left_child = delete_avltree(tree->left_child, tree->key);
			}
			else
			{
				//ÕÒµ½right_child min £¬¸³Öµ£¬É¾³ı
				AVLNode* node = find_min_avltree(tree->right_child);
				tree->key = node->key;
				tree->right_child = delete_avltree(tree->right_child, tree->key);

			}
		}
		else
		{
			AVLNode* node = tree;
			tree = tree->left_child ? tree->left_child : tree->right_child;
			free(node);
		}
	}
	if(tree)
		tree->height = MAX_HEIGHT(HEIGHT(tree->left_child), HEIGHT(tree->right_child)) + 1;
	return tree;
}

AVLNode* find_avltree(AVLTree tree, KeyType key)
{
	if (!tree)
		return nullptr;
	if (key == tree->key)
		return tree;
	else if (key > tree->key)
		return find_avltree(tree->right_child, key);
	else
		return find_avltree(tree->left_child, key);
}
AVLNode* find_min_avltree(AVLTree tree)
{
	if (!tree)
		return nullptr;
	AVLNode* node = tree;
	while (node->left_child)
	{
		node = node->left_child;
	}
	return node;
	
}
AVLNode* find_max_avltree(AVLTree tree)
{
	if (!tree)
		return nullptr;
	AVLNode* node = tree;
	while (node->right_child)
	{
		node = node->right_child;
	}
	return node;

}

void preorder_avltree(AVLTree tree)
{
	if (!tree)
		return;
	printf("value %d \n", tree->key);
	preorder_avltree(tree->left_child);
	preorder_avltree(tree->right_child);
}
void inorder_avltree(AVLTree tree)
{
	if (!tree)
		return;
	inorder_avltree(tree->left_child);
	printf("value %d \n", tree->key);
	inorder_avltree(tree->right_child);
}
void postorder_avltree(AVLTree tree)
{
	if (!tree)
		return;
	postorder_avltree(tree->left_child);
	postorder_avltree(tree->right_child);
	printf("value %d \n", tree->key);
}