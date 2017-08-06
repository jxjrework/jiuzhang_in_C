#include "vector.h"

// new empty vector with size of 0
void Vector_Init(Vector *V)
{
	V->data = malloc(sizeof(int));
	V->size = 0;
}

// Pop back
void Vector_PopBack(Vector *V)
{
	if (V->size == 0)
		fprintf(stderr, "Error: vector empty\n");
	else {
		//free(&(V->data[V->size - 1]));
		//V->data = realloc(V->data, (V->size - 1) * sizeof(int));
		V->size--;
	}
}

// push back
void Vector_PushBack(Vector *V, int val)
{
	if ((V->size == 0 ) || (V->size == (sizeof(V->data) / sizeof(V->data[0])))) {
		V->data = realloc(V->data, (V->size + 1) * sizeof(int));
	}
	V->data[V->size] = val;
	V->size += 1;
}

// free
void Vector_Free(Vector *V)
{
	free(V->data);
	V->data = NULL;
	V->size = 0;
}