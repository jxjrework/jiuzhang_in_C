#pragma once
#include <stdio.h>
#include <stdlib.h>

#define VECTOR_MAX 100

// define vector
struct Vector {
	int     data[VECTOR_MAX];
	int     size;
};
typedef struct Vector Vector;

// define functions/methods
void Vector_Init(Vector *V);
void Vector_PopBack(Vector *V);
void Vector_PushBack(Vector *V, int val);
void Vector_Free(Vector *V);