#include<iostream>
#include"DynamicArrayStack.h"
using namespace std;
void main()
{
	Stack* stack = create_stack(9);
	for (int i = 0; i < 10; i++)
	{
		push(stack, i);
	}
	print(stack);
	cout << "peek == " << peek(stack) << endl;
	cout << "is_full == " << is_full(stack) << endl;
	int count = get_cout(stack);
	for (int i = 0; i < count; i++)
	{
		pop(stack);
	}
	print(stack);
	cout << "is_empty == " << isEmpty(stack) << endl;

	destroy_stack(stack);

	getchar();
}