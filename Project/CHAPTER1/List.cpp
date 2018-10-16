#include "List.h"
#include<iostream>
using namespace std;

LinkNode* CreateList(int num)
{
	LinkNode* head = (LinkNode*)malloc(sizeof(LinkNode));
	if (head == nullptr)
	{
		cout << "memory error";
		return nullptr;
	}
	head->next = nullptr;
	head->data = nullptr;
	LinkNode* pNode = head;
	for (int i = 0; i < num; i++)
	{
		LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
		node->data = nullptr;
		node->next = nullptr;
		if (node == nullptr)
		{
			cout << "memory error";
			return nullptr;
		}
		pNode->next = node;
		pNode = pNode->next;
	}
	return head;
}

bool IsEmpty(LinkNode* list)
{
	if (list == nullptr)
	{
		cout << "��������";
		return true;
	}
	if (list->next == nullptr)
		return true;
	else
		return false;
}
void Insert(LinkNode* list, LinkNode* node, int position)
{
	if (list == nullptr)
	{
		cout << "��������";
		return;
	}
	if (position > Length(list) || position < 0)
	{
		cout << "������ == " << Length(list) << "   ����Ԫ�ص�λ�� == " << position << "   ���ܲ���";
		return;
	}
	LinkNode* p = list;
	int pPos = -1;//����ͷ�ڵ�
	while ((pPos+1) != position && p->next != nullptr)
	{
		p = p->next;
		pPos++;
	}
	if ((pPos+1) == position)
	{
		node->next = p->next;
		p->next = node;
	}
}
int Length(LinkNode* list)
{
	if (list == nullptr)
	{
		cout << "��������";
		return 0;
	}
	int i = 0;
	LinkNode * p = list;
	while (p->next != nullptr)
	{
		i += 1;
		p = p->next;
	}
	return i;
}
//������Ϊ��
void Clear(LinkNode* list)
{
	if (list == nullptr)
	{
		cout << "��������";
		return;
	}
	LinkNode* p = list->next;
	list->next = nullptr;
	while (p != nullptr)
	{
		LinkNode* q = p;
		p = q->next;
		free(q);
	}
}
void DeleteByPos(LinkNode* list, int position)
{
	if (list == nullptr)
	{
		cout << "��������";
		return;
	}
	if (position >= Length(list) || position < 0)
	{
		cout << "������ == " << Length(list) << "   ɾ��Ԫ�ص�λ�� == " << position << "   û�и�λ�ýڵ�";
		return;
	}
	LinkNode* p = list;
	int pos = -1;
	while (p->next != nullptr && (pos+1) < position)
	{
		p = p->next;
		pos++;
	}
	if (p->next != nullptr && pos+1 == position)
	{
		LinkNode* q = p->next;
		p->next = p->next->next;
		free(q);
	}
}

void FreeList(LinkNode** list)
{
	if (*list == nullptr)
	{
		cout << "��������";
		return;
	}
	LinkNode* p = *list;
	while (p != nullptr)
	{
		LinkNode* q = p;
		p = q->next;
		free(q);
	}
	*list = nullptr;
}

void PrintList(LinkNode* list)
{
	if (list == nullptr)
	{
		cout << "��������";
		return;
	}
	LinkNode* p = list;
	cout << "head->";
	int i = -1;
	while (p->next != nullptr)
	{
		cout << "node_" << ++i << "_addr==" << p->next << "->";
		p = p->next;
	}
	cout << endl;
}