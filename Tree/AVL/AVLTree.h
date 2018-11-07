#pragma once

typedef int KeyType;

typedef struct _avl_tree
{
	KeyType key;
	int height;
	struct  _avl_tree* left_child;
	struct  _avl_tree* right_child;
}AVLNode, *AVLTree;


AVLTree create_avltree(KeyType key);
void destroy_avltree(AVLTree tree);

AVLTree insert_avltree(AVLTree tree, KeyType key);
AVLTree delete_avltree(AVLTree tree, KeyType key);

AVLNode* find_avltree(AVLTree tree, KeyType key);
AVLNode* find_min_avltree(AVLTree tree);
AVLNode* find_max_avltree(AVLTree tree);

void preorder_avltree(AVLTree tree);
void inorder_avltree(AVLTree tree);
void postorder_avltree(AVLTree tree);







