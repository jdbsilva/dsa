#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef void (*func_node)(struct node *);

struct node * make_node(int data)
{
	struct node *node;

	node = malloc(sizeof(struct node));
	node->data = data;
	node->left = 0;
	node->right= 0;

	return node;
}

void free_node(struct node *node)
{
	if (node) {	
		free(node);
	}
}

void print_node(struct node *node)
{
	printf("%d, ", node->data);
}

/*
	Smaller to the left; larger to the right 
 */
int insert(struct node **root, int data)
{
	if (*root) {	
		if (data < (*root)->data) {
			return insert(&(*root)->left, data);
		} else {
			return insert(&(*root)->right, data);
		}
	} else {
		*root = make_node(data);
	}	
	return 0;
}

/*
	pre = left + right + root 
 */
int foo_preorder(struct node *root, func_node foo)
{	
	if (root) {
		foo(root);	
		foo_preorder(root->left, foo);
		foo_preorder(root->right, foo);
	}	
	
	return 0;
}

/*
	in = left + root + right 
 */
int foo_inorder(struct node *root, func_node foo)
{	
	if (root) {
		foo_inorder(root->left, foo);
		foo(root);
		foo_inorder(root->right, foo);
	}	
	
	return 0;
}

/*
	post = root + left + right
 */
int foo_postorder(struct node *root, func_node foo)
{	
	if (root) {
		foo_postorder(root->left, foo);
		foo_postorder(root->right, foo);
		foo(root);
	}	
	
	return 0;
}

#endif
