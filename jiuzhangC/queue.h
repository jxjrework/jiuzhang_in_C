#pragma once
// implement queue with array, need to define max size

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define QUEUE_MAX 100

// define queue
struct Queue {
	// array of pointers pointing to the tree nodes
	TreeNode*     data[QUEUE_MAX];
	int front;
	int rear;
	int size;
};
typedef struct Queue Queue;

// define functions/methods
void Queue_Init(Queue *Q);
TreeNode* Queue_Front(Queue *Q);
void Queue_Push(Queue *Q, TreeNode *node);
void Queue_Pop(Queue *Q);


