#include<stdio.h>
#include"List.h"
#include<iostream>
using namespace std;
void main()
{

	LinkNode* list = CreateList(10);
	cout << "list length == " << Length(list);
	PrintList(list);
	bool isEmpty = IsEmpty(list);
	if (isEmpty)
		cout << "¿Õ";
	else
		cout << "·Ç¿Õ";
	
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	int a = 10;
	node->data = &a;
	Insert(list, node, Length(list));
	PrintList(list);

	LinkNode* node1 = (LinkNode*)malloc(sizeof(LinkNode));
	int b = 100;
	node->data = &b;
	Insert(list, node1, 2);
	PrintList(list);
	
	DeleteByPos(list, Length(list) - 1);
	PrintList(list);

	DeleteByPos(list, 5);
	PrintList(list);

	/*
	Clear(list);
	PrintList(list);*/

	cout << Length(list) << endl;

	FreeList(&list);
	//list = nullptr;
	PrintList(list);
	getchar();
}