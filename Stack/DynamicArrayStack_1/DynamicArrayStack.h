#pragma once
//һ�������ò��ɱ䳤ջ ��ʵ��StaticArrayStack��ֻ࣬����һ��capacity�Ǻ궨����ģ� һ���Ǵ���ջ��ʱ�򴫲�����
typedef int stack_type;

typedef struct _stack
{
	int capacity;
	int top_index;
	stack_type data[1];	//�ṹ���е������СΪ1 �ڽṹ��β����ʵ�ֱ䳤���飬�����ڴ��ʱ�������һЩ�������͵��ڴ�Ϳ���ʵ�֡�
}Stack;


Stack* create_stack(int capacity);

void push(Stack* stack, stack_type data);

stack_type pop(Stack* stack);

stack_type peek(Stack* stack);

bool isEmpty(Stack* stack);

int get_cout(Stack* stack);

bool is_full(Stack* stack);

void print(Stack* stack);

void destroy_stack(Stack* stack);

