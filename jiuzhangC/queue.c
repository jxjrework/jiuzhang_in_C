#include "queue.h"

// new empty stack
void Queue_Init(Queue *Q)
{
	Q->front = -1;
	Q->rear = -1;
	Q->size = 0;
}

// front
TreeNode* Queue_Front(Queue *Q)
{
	if (Q->size == 0) {
		fprintf(stderr, "Error: queue empty\n");
		return -1;
	}

	return Q->data[Q->front];
}

// push
void Queue_Push(Queue *Q, TreeNode* node)
{
	if (Q->rear < QUEUE_MAX) {
		Q->data[++Q->rear] = node;
		if (Q->front == -1) {
			Q->front = 0;
		}
		Q->size += 1;
	}
	else
		fprintf(stderr, "Error: queue full\n");
}

// pop
void Queue_Pop(Queue *Q)
{
	if (Q->size == 0)
		fprintf(stderr, "Error: queue empty\n");
	else {
		Q->size--;
		Q->front += 1;
	}

}