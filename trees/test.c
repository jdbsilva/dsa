#include <stdio.h>
#include "tree.h"

int main()
{
	struct node *root;

	insert(&root, 10);
	insert(&root, 1);
	insert(&root, 4);
	insert(&root, 10);
	insert(&root, 43);
	insert(&root, 0);
	insert(&root, 7);
	insert(&root, 98);
	insert(&root, 39);
	insert(&root, 3);

	printf("Preorder: ");
	foo_preorder(root, print_node);
	printf("\n");

	printf("Inorder: ");
	foo_inorder(root, print_node);
	printf("\n");

	printf("Postorder: ");
	foo_postorder(root, print_node);
	printf("\n");



	foo_inorder(root, free_node);

	return 0;
}

