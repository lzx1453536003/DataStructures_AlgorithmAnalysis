#include "ArrayQueue.h"
#include <iostream>

using namespace std;


Queue* create(int capacity)
{
	Queue* queue = (Queue*)malloc(((int)(((Queue*)0)->datas)) + sizeof(QueueType)*capacity);
	if (queue == nullptr)
	{
		cout << "memeory out" << endl;
		return nullptr;
	}
	queue->capacity = capacity;
	queue->front = queue->rear = 0;
	queue->count = 0;
	return queue;

}

void destroy(Queue* queue)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return;
	}
	free(queue);
	queue = nullptr;
}

bool is_full(Queue* queue)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return false;
	}
	if (queue->count == queue->capacity)
		return true;
	return false;
}
bool isEmpty(Queue* queue)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return false;
	}
	if (queue->count == 0)
		return true;
	return false;
}

void en_queue(Queue* queue, QueueType data)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return;
	}
	if (is_full(queue))
	{
		cout << "queue is full" << endl;
		return;
	}
	queue->datas[queue->front] = data;
	if (queue->front + 1 == queue->capacity)
		queue->front = 0;
	else
		queue->front++;
	queue->count++;
}
QueueType de_queue(Queue* queue)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return -1;
	}
	if (isEmpty(queue))
	{
		cout << "queue is empty" << endl;
		return -1;
	}
	QueueType temp = queue->datas[queue->rear];
	if (queue->rear + 1 == queue->capacity)
		queue->rear = 0;
	else
		queue->rear++;
	queue->count--;
}

QueueType peek_queue(Queue* queue)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return -1;
	}
	if (isEmpty(queue))
	{
		cout << "queue is empty" << endl;
		return -1;
	}
	if (queue->front - 1 < 0)
		return queue->datas[queue->capacity - 1];
	else
		return queue->datas[queue->front - 1];
}

void print(Queue* queue)
{
	if (queue == nullptr)
	{
		cout << "queue == nullptr" << endl;
		return;
	}
	
	for (int i = 0; i < queue->count; i++)
	{
		int index = 0;
		if (queue->front - 1 - i < 0)
		{
			index = queue->capacity + queue->front - 1 - i;

		}
		else
			index = queue->front - 1 - i;
		cout << "index == " << i << "      value<<" << queue->datas[index]<<endl;
	}
}