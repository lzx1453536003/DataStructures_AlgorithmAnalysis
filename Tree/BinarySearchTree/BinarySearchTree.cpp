#include "BinarySearchTree.h"
#include<iostream>
using namespace std;

TreeNode* CreateBinarySearchTree(TreeType rootKey)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (root == nullptr)
	{
		cout << "memory out" << endl;
		return nullptr;
	}
	root->key = rootKey;
	root->left_child = nullptr;
	root->right_child = nullptr;
	root->parent = nullptr;
	return root;
}

void DestroyTree(TreeNode* tree)
{
	if (tree == nullptr)
	{
		cout << "tree is nullptr" << endl;
		return;
	}
	DestroyTree(tree->left_child);
	DestroyTree(tree->right_child);
	free(tree);

	//implement method 2:
}

TreeNode* Insert(TreeNode* tree, TreeType key)
{
	if (tree == nullptr)
	{
		tree = CreateBinarySearchTree(key);
	}
	else if (tree->key > key)
	{
		if (tree->left_child == nullptr)
		{
			TreeNode* left_child = CreateBinarySearchTree(key);
			tree->left_child = left_child;
			left_child->parent = tree;
		}
		else
			Insert(tree->left_child, key);
	}
	else if (tree->key < key)
	{
		if (tree->right_child == nullptr)
		{
			TreeNode* right_child = CreateBinarySearchTree(key);
			tree->right_child = right_child;
			right_child->parent = tree;
		}
		else
			Insert(tree->right_child, key);
	}
	return tree;
}

TreeNode* Delete(TreeNode* tree, TreeType key)
{
	if (!tree)
		return nullptr;
	if (tree->key > key)
	{
		tree->left_child = Delete(tree->left_child, key);
		if(tree->left_child)
			tree->left_child->parent = tree;
	}
	else if (tree->key < key)
	{
		tree->right_child = Delete(tree->right_child, key);
		if (tree->right_child)
			tree->right_child->parent = tree;
	}
	else
	{
		if (tree->left_child&&tree->right_child)
		{
			TreeNode* nodeMax = FindMax(tree->left_child);
			tree->key = nodeMax->key;
			nodeMax->parent->right_child = nullptr;
			free(nodeMax);
		}
		else if(tree->left_child)
		{
			TreeNode* node = tree;
			tree = tree->left_child;
			free(node);
		}
		else if (tree->right_child)
		{
			TreeNode* node = tree;
			tree = tree->right_child;
			free(node);
		}
		else
		{
			free(tree);
			tree = nullptr;
		}
	}
	return tree;
}

TreeNode* Find(TreeNode* tree, TreeType key)
{
	if (tree == nullptr)
	{
		return nullptr;
	}
	if (tree->key == key)
		return tree;
	else if (tree->key > key)
	{
		return Find(tree->left_child, key);
	}
	else
	{
		return Find(tree->right_child, key);
	}
}


TreeNode* FindMin(TreeNode* tree)
{
	if (tree == nullptr)
	{
		return nullptr;
	}
	TreeNode* node = tree;
	while (node->left_child != nullptr)
	{
		node = node->left_child;
	}
	return node;
}
TreeNode* FindMax(TreeNode* tree)
{
	if (tree == nullptr)
	{
		return nullptr;
	}
	TreeNode* node = tree;
	while (node->right_child != nullptr)
	{
		node = node->right_child;
	}
	return node;
}

void Preorder(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	cout << "value == " << tree->key << endl;
	Preorder(tree->left_child);
	Preorder(tree->right_child);
}
void Inorder(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	Inorder(tree->left_child);
	cout << "value == " << tree->key << endl;
	Inorder(tree->right_child);
}
void Postorder(TreeNode* tree)
{
	if (tree == nullptr)
		return;
	Postorder(tree->left_child);
	Postorder(tree->right_child);
	cout << "value == " << tree->key << endl;
}


