#pragma once
//implement binary search tree.

typedef int TreeType;

typedef struct _tree_node TreeNode;

struct _tree_node
{
	TreeType key;
	struct _tree_node* parent;
	struct _tree_node* left_child;
	struct _tree_node* right_child;
};

TreeNode* CreateBinarySearchTree(TreeType rootKey);
void DestroyTree(TreeNode* tree);
TreeNode* Insert(TreeNode* tree, TreeType key);
TreeNode* Delete(TreeNode* tree, TreeType key);

TreeNode* Find(TreeNode* tree, TreeType key);
TreeNode* FindMin(TreeNode* tree);
TreeNode* FindMax(TreeNode* tree);

void Preorder(TreeNode* tree);
void Inorder(TreeNode* tree);
void Postorder(TreeNode* tree);
