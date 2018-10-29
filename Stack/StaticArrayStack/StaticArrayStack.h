#pragma once

#define STACK_SIZE 20

typedef int stack_type;

typedef struct _stack Stack;

struct _stack
{
	stack_type data[STACK_SIZE];
	int top_index;
};

Stack* create_stack();

void push(Stack* stack, stack_type data);

stack_type pop(Stack* stack);

stack_type peek(Stack* stack);

bool isEmpty(Stack* stack);

int get_cout(Stack* stack);

int is_full(Stack* stack);

void print(Stack* stack);

void destroy_stack(Stack* stack);