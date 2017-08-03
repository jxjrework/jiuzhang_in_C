// implement stack with array, need to define max size
// http://groups.csail.mit.edu/graphics/classes/6.837/F04/cpp_notes/stack1.html
// we can also implement it with linked list like
// http://www.sanfoundry.com/c-program-stack-using-linked-list/
// we only deal with tree, so define a stack with treenode as element
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define STACK_MAX 100

// define stack
struct Stack {
	// array of pointers pointing to the tree nodes
	TreeNode*     data[STACK_MAX];
	int     size;
};
typedef struct Stack Stack; 

// define functions/methods
void Stack_Init(Stack *S);
TreeNode* Stack_Top(Stack *S);
void Stack_Push(Stack *S, TreeNode *node);
void Stack_Pop(Stack *S);

