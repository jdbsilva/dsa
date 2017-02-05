#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct queue {
	struct node *front;
	struct node *rear;
};

struct node * make_node(int data)
{
	struct node *node;
	
	node = malloc(sizeof(struct node));
	node->data = data;
	node->next = 0;

	return node;
}

void free_node(struct node **node)
{
	if (*node) { 
		free(*node);
		*node = 0;
	}
}

struct queue * make_queue(struct node *front, struct node *rear)
{
	struct queue *queue;

	queue = malloc(sizeof(struct queue));
	queue->front = front;
	queue->rear = rear;

	return queue;	
}

/*
	Enqueue, i.e. insert last
 */
void enqueue(struct queue **queue, int data)
{
	struct node *tmp;	

	tmp = make_node(data); 
	
	if (!*queue) { 
		*queue = make_queue(tmp, tmp);
		return;
	}
	
	(*queue)->rear->next = tmp;
	(*queue)->rear = tmp;
}

/*
	Dequeue, i.e. insert first 
 */
struct node * dequeue(struct queue **queue)
{ 
	struct node *tmp;

	if (*queue) {
		tmp = (*queue)->front;
		(*queue)->front = tmp->next;	
		return tmp;	
	}

	return 0;
}

#endif





