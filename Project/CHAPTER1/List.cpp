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
	LinkNode* pNode = head;
	for (int i = 0; i < num; i++)
	{
		LinkNode* node = (LinkNode*)malloc(sizeof(linkNode));
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
		cout << "��������":
		return;
	}
	if (position > Length(list) || position < 0)
	{
		cout << "������ == " << Length(List) << "   ����Ԫ�ص�λ�� == " << position << "   ���ܲ���";
		return;
	}
	LinkNode* p = list;
	int pPos = -1;//����ͷ�ڵ�
	while ((pPos ++) != position && p->next != nullptr)
	{
		p = p->next;
	}
	if (pPos == position)
	{
		node->next = p->next;
		p->next - node;
	}
}
int Length(LinkNode* list)
{
	if (list == nullptr)
	{
		cout << "��������":
		return;
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
		cout << "��������":
		return;
	}
	LinkNode* p = list->next;
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
		cout << "��������":
		return;
	}
	if (position >= Length(list) || position < 0)
	{
		cout << "������ == " << Length(List) << "   ɾ��Ԫ�ص�λ�� == " << position << "   ���ܲ���";
		return;
	}

}