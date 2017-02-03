#include <stdio.h>
#include "stack.h"

int main()
{
	struct node *top;	
	struct node *temp;	

	push(&top, 0);
	push(&top, 1);
	push(&top, 2);
	push(&top, 3);
	push(&top, 4);
	push(&top, 5);
	push(&top, 6);
	push(&top, 7);

	while (top) {
		temp = pop(&top);
		printf("%d, ", temp->data);
		free_node(&temp);
	}
	
	printf("\n");
	return 0;
}
