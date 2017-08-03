#include "stack.h"

// new empty stack
void Stack_Init(Stack *S)
{
	S->size = 0;
}

// top
TreeNode* Stack_Top(Stack *S)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return -1;
	}

	return S->data[S->size - 1];
}

// push
void Stack_Push(Stack *S, TreeNode* node)
{
	if (S->size < STACK_MAX)
		S->data[S->size++] = node;
	else
		fprintf(stderr, "Error: stack full\n");
}

// pop
void Stack_Pop(Stack *S)
{
	if (S->size == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->size--;
}