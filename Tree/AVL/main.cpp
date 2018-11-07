#include<stdio.h>
#include "AVLTree.h"

void main()
{
	AVLTree avl_tree = create_avltree(100);

	for (int i = 0; i < 20; i++)
		avl_tree = insert_avltree(avl_tree, i);
	preorder_avltree(avl_tree);
	puts("===================\n");
	inorder_avltree(avl_tree);
	puts("===================\n");
	postorder_avltree(avl_tree);
	puts("===================\n");
	for (int i = 0; i < 10; i++)
		avl_tree = delete_avltree(avl_tree, i);

	preorder_avltree(avl_tree);
	puts("===================\n");
	inorder_avltree(avl_tree);
	puts("===================\n");
	postorder_avltree(avl_tree);

	getchar();
}