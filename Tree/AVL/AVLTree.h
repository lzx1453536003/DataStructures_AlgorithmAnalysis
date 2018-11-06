#pragma once

typedef int KeyType;
typedef struct _tree_node
{
	KeyType key;
	int height;
	AVLTree left_child;
	AVLTree right_child;

}TreeNode, *AVLTree;

AVLTree create_avltree(KeyType key);
void destroy_avltree(AVLTree tree);

AVLTree insert_avltree(AVLTree tree, KeyType key);
AVLTree delete_avltree(AVLTree tree, KeyType key);
