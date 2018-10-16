#pragma once
typedef struct _Node LinkNode;

typedef struct _Node
{
	void* data;
	struct _Node* next;
};


LinkNode* CreateList(int num = 0);	//����һ������Ϊnum������
bool IsEmpty(LinkNode* list);
void Insert(LinkNode* list, LinkNode* node, int position);
int Length(LinkNode* list);
void Clear(LinkNode* list);
void DeleteByPos(LinkNode* list, int position);
void FreeList(LinkNode** list);
void PrintList(LinkNode* list);