#pragma once

typedef int QueueType;
typedef struct _queue Queue;

struct _queue
{
	int capacity;
	int front;
	int rear;
	int count;
	QueueType datas[1];
};

Queue* create(int capacity);

void destroy(Queue* queue);

bool is_full(Queue* queue);

bool isEmpty(Queue* queue);

void en_queue(Queue* queue, QueueType data);
QueueType de_queue(Queue* queue);

void print(Queue* queue);
QueueType peek_queue(Queue* queue);






