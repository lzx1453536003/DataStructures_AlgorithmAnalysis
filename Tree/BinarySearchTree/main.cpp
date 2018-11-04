#include<iostream>
#include"BinarySearchTree.h"
using namespace std;
void main()
{
	TreeNode* tree = CreateBinarySearchTree(100);

	for (int i = 90; i < 110; i++)
		tree = Insert(tree, i);
	tree = Insert(tree, 89);
	Preorder(tree);
	cout << "=============" << endl;
	Inorder(tree);
	cout << "=============" << endl;
	Postorder(tree);

	TreeNode* node = Find(tree, 105);
	cout << "value = " << node->key << endl;

	node = FindMin(tree);
	cout << "value = " << node->key << endl;

	node = FindMax(tree);
	cout << "value = " << node->key << endl;
	cout << "=============" << endl;

	tree = Delete(tree, 100);
	Inorder(tree);
	cout << "=============" << endl;
	TreeNode* tree_1 = CreateBinarySearchTree(100);
	tree_1 = Insert(tree_1, 50);
	tree_1 = Insert(tree_1, 150);
	tree_1 = Insert(tree_1, 25);
	tree_1 = Insert(tree_1, 75);
	tree_1 = Insert(tree_1, 20);
	tree_1 = Insert(tree_1, 24);
	tree_1 = Insert(tree_1, 70);
	tree_1 = Insert(tree_1, 80);
	tree_1 = Insert(tree_1, 125);
	tree_1 = Insert(tree_1, 175);
	tree_1 = Insert(tree_1, 124);
	tree_1 = Insert(tree_1, 126);
	tree_1 = Insert(tree_1, 174);
	tree_1 = Insert(tree_1, 176);
	Preorder(tree_1);
	cout << "=============" << endl;
	Inorder(tree_1);
	cout << "=============" << endl;
	Postorder(tree_1);


	getchar();
}