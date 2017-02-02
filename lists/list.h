#ifndef SLL_H
#define SLL_H

#include <stdio.h>
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
	if (*node)	{
		free(*node);
		*node = 0;
	}
}

void free_list(struct node **head)
{
	struct node *tmp;	
	while (*head) {
		tmp = *head;	
		head = (*head)->next;
		free_node(&tmp);
	}
	*head = 0;
}

/*
	Prepend node to list 
 */
int prepend_node(struct node **head, struct node *node)
{
	node->next = *head;		
	*head = node;

	return 0;
}

/*
	Append node to list
 */
int append_node(struct node **head, struct node *node)
{
	while (*head) {
		head = &(*head)->next;	
	}

	*head = node;

	return 0;
}

/*
	Insert node in position index (starting at zero)
 */
int insert_node(struct node **head, struct node *node, size_t index)
{
	while (*head && index--) {
		head = &(*head)->next;	
	}

	node->next = *head;
	*head = node;

	return 0;
}

/*
	Remove node at index from the list 
 */
int remove_node(struct node **head, size_t index)
{
	struct node *tmp;	
	
	while (*head && index--) {
		head = &(*head)->next;	
	}

	if (*head) {
		tmp = *head;
		*head = (*head)->next;
		free_node(&tmp);
	}	

	return 0;
}

#endif
