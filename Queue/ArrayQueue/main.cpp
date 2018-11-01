#include <iostream>
#include"ArrayQueue.h"
using namespace std;

void main()
{
	Queue* queue = create(10);
	for (int i = 0; i < 11; i++)
	{
		en_queue(queue, i);
	}
	print(queue);

	for (int i = 0; i < 5; i++)
	{
		de_queue(queue);
	}
	print(queue);

	for (int i = 10; i < 16; i++)
	{
		en_queue(queue, i);
	}
	print(queue);
	getchar();
}