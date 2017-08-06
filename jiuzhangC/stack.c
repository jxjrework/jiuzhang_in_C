#include "stack.h"

//tree
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

//int
// new empty stack
void Stack_Int_Init(Stack_Int *S)
{
	S->size = 0;
}

// top
int Stack_Int_Top(Stack_Int *S)
{
	if (S->size == 0) {
		fprintf(stderr, "Error: stack empty\n");
		return -1;
	}

	return S->data[S->size - 1];
}

// push
void Stack_Int_Push(Stack_Int *S, int node)
{
	if (S->size < STACK_MAX)
		S->data[S->size++] = node;
	else
		fprintf(stderr, "Error: stack full\n");
}

// pop
void Stack_Int_Pop(Stack *S)
{
	if (S->size == 0)
		fprintf(stderr, "Error: stack empty\n");
	else
		S->size--;
}