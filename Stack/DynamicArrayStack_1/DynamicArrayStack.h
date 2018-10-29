#pragma once
//一旦创建好不可变长栈 其实与StaticArrayStack差不多，只不过一个capacity是宏定义给的， 一个是创建栈的时候传参数的
typedef int stack_type;

typedef struct _stack
{
	int capacity;
	int top_index;
	stack_type data[1];	//结构体中的数组大小为1 在结构体尾部可实现变长数组，申请内存的时候多申请一些数组类型的内存就可以实现。
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

