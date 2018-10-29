#pragma once
#include<iostream>
#include "StaticArrayStack.h"

using namespace std;


Stack* create_stack()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == nullptr)
	{
		cout << "memory out";
		return nullptr;
	}
	stack->top_index = -1;	//创建空栈，初始化栈顶指针
	return stack;
}

void push(Stack* stack, stack_type data)
{
	if (stack == nullptr)
	{
		cout << "stack  == nullptr";
		return;
	}
	if (stack->top_index > STACK_SIZE)
	{
		cout << "栈已经满了";
		return;
	}
	stack->top_index++;
	stack->data[stack->top_index] = data;
}

stack_type pop(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack  == nullptr";
		return -1;
	}
	if (stack->top_index < 0)
	{
		cout << "栈是空的";
		return -1;
	}
	stack_type temp = stack->data[stack->top_index];
	stack->top_index--;
	return temp;
}

stack_type peek(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack  == nullptr";
		return -1;
	}
	if (stack->top_index < 0)
	{
		cout << "栈是空的";
		return -1;
	}
	return stack->data[stack->top_index];
}

bool isEmpty(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack  == nullptr";
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
		cout << "stack  == nullptr";
		return -1;
	}
	return stack->top_index + 1;
}

int is_full(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack  == nullptr";
		return -1;
	}
	return (stack->top_index + 1) == STACK_SIZE;
}

void print(Stack* stack)
{
	if (stack == nullptr)
	{
		cout << "stack  == nullptr";
		return;
	}
	for (int i = 0; i <= stack->top_index; i++)
	{
		cout << "index == i" << i << "    value == " << stack->data[i] << endl;
	}
}

void destroy_stack(Stack* stack)
{
	free(stack);
	stack = nullptr;
}