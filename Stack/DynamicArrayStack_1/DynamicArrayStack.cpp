#include "DynamicArrayStack.h"
#include<iostream>
using namespace std;
Stack* create_stack(int capacity)
{
	Stack* stack = (Stack*)malloc((int)((Stack*)0)->data + sizeof(stack_type)*capacity);
	if (stack == nullptr)
	{
		cout << "memory out";
		return nullptr;
	}
	for (int i = 0; i < capacity; i++)
		stack->data[i] = 0;
	stack->capacity = capacity;
	stack->top_index = -1;
	return stack;
}

void push(Stack* stack, stack_type data)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return;
	}
	if (is_full(stack))
	{
		cout << "stack is full" << endl;
		return;
	}
	stack->top_index++;
	stack->data[stack->top_index] = data;
}

stack_type pop(Stack* stack)
{
	stack_type temp = peek(stack);
	stack->top_index--;
	return temp;
}

stack_type peek(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return -1;
	}
	if (isEmpty(stack))
	{
		cout << "stack isempty" << endl;
		return -1;
	}
	stack_type temp = stack->data[stack->top_index];
	return temp;
}

bool isEmpty(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return true;
	}
	if (stack->top_index < 0)
		return true;
	return false;
}

int get_cout(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return -1;
	}
	return stack->top_index;
}

bool is_full(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return false;
	}
	if (stack->top_index >= stack->capacity - 1)
		return true;
	return false;
}

void print(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return;
	}
	for (int i = 0; i <= stack->top_index; i++)
	{
		cout << "stack index == " << i << "    value == " << stack->data[i] <<endl;
	}
}

void destroy_stack(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack == nullptr" << endl;
		return;
	}
	free(stack);
	stack = nullptr;
}