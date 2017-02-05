#include <stdio.h>
#include "queues.h"

void print_queue(char *title, struct queue *queue)
{
	struct node *tmp;

	if (queue) { 
		tmp = queue->front;
		printf("%s\n", title);
		while (tmp) {
			printf("%d, ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}
}

int main()
{
	struct node *tmp = 0;
	struct queue *queue = 0;
	
	enqueue(&queue, 0);
	enqueue(&queue, 2);
	enqueue(&queue, 5);
	enqueue(&queue, 7);
	enqueue(&queue, 10);

	print_queue("After enqueue", queue);

	while (queue->front) {
		tmp = dequeue(&queue);
		print_queue("After dequeue", queue);
		free_node(&tmp);
	}	

	return 0;
}
