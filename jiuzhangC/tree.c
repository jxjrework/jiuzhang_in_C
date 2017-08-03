#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

// {LeetCode] 297. Serialize and Deserialize Binary Tree
// use # to present NULL
// BFS
// val of node has to be single digit
char* serialize(TreeNode* root) {
	TreeNode** output = NULL;
	output = (TreeNode**)malloc(sizeof(TreeNode*));
	int outputLength = 1;
	output[outputLength - 1] = root;
	// outputLength keeps updated
	// this will BFS the tree, no need to use queue
	for (int i = 0; i < outputLength; i++) {
		if (output[i] == NULL) {
			continue;
		}
		output = realloc(output, (outputLength + 1) * sizeof(TreeNode*));
		output[outputLength] = output[i]->left;
		outputLength += 1;
		output = realloc(output, (outputLength + 1) * sizeof(TreeNode*));
		output[outputLength] = output[i]->right;
		outputLength += 1;
	}

	// until now the child level of leaves (all NULLs) have been stored
	// use the following while loop to delete NULLs at the end
	while (outputLength > 0 && output[outputLength - 1] == NULL) {
		free(output[outputLength - 1]);
		output[outputLength - 1] = NULL;
		outputLength -= 1;
	}

	if (outputLength == 0) {
		return "{}";
	}
	else {
		//convert nodes to string
		char* res = malloc((outputLength + 2) * sizeof(char));
		*res = '{';
		*(res + outputLength + 1) = '}';
		for (int i = 0; i < outputLength; i++) {
			if (output[i] == NULL) {
				*(res + i + 1) = '#';
			}
			else {
				*(res + i + 1) = output[i]->val + '0';
			}
		}
		free(output);
		output = NULL;
		return res;
	}
}

TreeNode* deserialize(char *data, int dataLength) {
	// edge case
	if (data == "{}") {
		return NULL;
	}

 	TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
	root->val = data[1] - '0';
	root->left = NULL;
	root->right = NULL;


	Queue *Q = malloc(sizeof(Queue));
	Queue_Init(Q);
	Queue_Push(Q, root);

	// for binary tree, vector [root, left, right, left, right, ...]
	bool isLeftChild = true;
	for (int i = 2; i < dataLength - 1; i++) {
		if (data[i] != '#') {
			TreeNode *node = (TreeNode*) malloc(sizeof(TreeNode));
			node->left = NULL;
			node->right = NULL;
			node->val = data[i] - '0';
			if (isLeftChild) {
				
				Queue_Front(Q)->left = node;
			}
			else {
				Queue_Front(Q)->right = node;
			}
			Queue_Push(Q, node);
		}
		if (!isLeftChild) {
			Queue_Pop(Q);
		}

		isLeftChild = !isLeftChild;
	}
	return root;
}