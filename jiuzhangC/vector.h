#pragma once
#include <stdio.h>
#include <stdlib.h>

// define vector
struct Vector {
	int*     data;
	int     size;
};
typedef struct Vector Vector;

// define functions/methods
void Vector_Init(Vector *V);
void Vector_PopBack(Vector *V);
void Vector_PushBack(Vector *V, int val);
void Vector_Free(Vector *V);