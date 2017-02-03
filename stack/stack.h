#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

struct node {
	int data;
	struct node *next;
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

void push(struct node **top, int data)
{
	struct node *node;

	node = make_node(data);
	node->next = *top;
	*top = node;
}

struct node * pop(struct node **top)
{
	struct node *tmp;

	tmp = *top;
	if (*top)
		*top = (*top)->next;

	return tmp;
}

void free_stack(struct node **top)
{
	struct node *tmp;	
		
	while (*top) {
		tmp = *top;
		*top = (*top)->next;
		free_node(&tmp);
	}
}

#endif
