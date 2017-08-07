#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "vector.h"
#include <stdbool.h>

// binary search:[LintCode] Last Position of Target
int lastPosition(int nums[], int numSize, int target);
// preorder traversal
int* preorderTraversal(TreeNode *root, int* returnSize);
// inorder traversal
int* inorderTraversal(TreeNode *root, int* returnSize);
// postorder traversal
int* postorderTraversal(TreeNode *root, int* returnSize);
// level order traversal (BFS)
int** levelOrder(TreeNode* root, int** columnSizes, int* returnSize);
// Bubble sort
void BubbleSort(Vector* x, int n);
//subset helper
void helper(Vector** results, int* returnSize, Vector* subset, Vector* nums, int start);
//subset(DFS) recursive
Vector* subsets(Vector* nums, int* returnSize);
//subset(DFS) non-recursive
Vector* subsets2(Vector* nums, int* returnSize);
//permutations
Vector* permute(Vector* nums, int* returnSize);



int main()
{
	//// test binary search
	//int nums[10] = { 0,1,1,1,3,4,5,5,6,7 };
	//int res;

	//// Get the array size
	//int numSize = sizeof(nums) / sizeof(nums[0]);
	//res = lastPosition(nums, numSize, 5);
	//printf("%d\n", res);
	

	//// test serialization/deserialization
	//char* string = "{12#5678#9##321}";
	//char* res;
	//TreeNode* tmp;
	//tmp = deserialize(string, 16);
	//printf("%d\n", tmp->left->val);
	//res = serialize(tmp);
	//printf("%s\n", res);
	


	//// test preorder/inorder/postorder traverssal of binary tree
	//char string[] = "{12345#6#78##90}";
	//int stringSize = sizeof(string) / sizeof(char) - 1;
	//// printf("%d\n", stringSize);
	//int* res;
	//TreeNode* tmp;
	//tmp = deserialize(string, stringSize);
	//int* returnSize = malloc(sizeof(int));
	//res = preorderTraversal(tmp, returnSize);
	//for (int i = 0; i < (*returnSize); i++) {
	//	printf("%d\n", res[i]);
	//}
	//printf("Return size: %d\n", *returnSize);
	//free(returnSize);
	

	//// test level order traverssal of binary tree
	//char string[] = "{12345#6#78##90}";
	//// sizeof includes '\n'
	//int stringSize = sizeof(string) / sizeof(char) - 1;
	//// printf("%d\n", stringSize);
	//int** res;
	//TreeNode* tmp;
	//tmp = deserialize(string, stringSize);
	//int* returnSize = malloc(sizeof(int));
	//int** columnSizes = malloc(sizeof(int*));
	//*columnSizes = malloc(sizeof(int));
	//res = levelOrder(tmp, columnSizes, returnSize);
	//for (int i = 0; i < (*returnSize); i++) {
	//	for (int j = 0; j < ((*columnSizes)[i]); j++) {
	//		printf("%d", res[i][j]);
	//	}
	//	printf("\n");
	//}
	//free(returnSize);
	//free(columnSizes);


	//test subset
	//int input[] = {6,2,3};
	//Vector* nums = NULL;
	//// initialize memory
	//Vector temp;
	//nums = &temp;
	//Vector_Init(nums);
	//nums->size = sizeof(input) / sizeof(input[0]);
	//for (int i = 0; i < nums->size; i++)
	//	nums->data[i] = input[i];
	//Vector* res = NULL;
	//int *returnSize;
	//// get memeory for this pointer
	//int tmp = 0;
	//returnSize = &tmp;
	//res = subsets(nums, returnSize);
	//for (int i = 0; i < (*returnSize); i++) {
	//	// empty set
	//	if (res[i].size == 0) {
	//		printf("{}\n");
	//		continue;
	//	}

	//	for (int j = 0; j < res[i].size; j++) {
	//		printf("%d", res[i].data[j]);
	//	}
	//	printf("\n");
	//}
	/*for (int j = 0; j < res[7].size; j++) {
		printf("%d", res[7].data[1]);
	}*/


	//test permutations
	int input[] = {6,1,7};
	Vector* nums = NULL;
	// initialize memory
	Vector temp;
	nums = &temp;
	Vector_Init(nums);
	nums->size = sizeof(input) / sizeof(input[0]);
	for (int i = 0; i < nums->size; i++)
		nums->data[i] = input[i];
	Vector* res = NULL;
	int *returnSize;
	// get memeory for this pointer
	int tmp = 0;
	returnSize = &tmp;
	res = permute(nums, returnSize);
	for (int i = 0; i < (*returnSize); i++) {
		// empty set
		if (res[i].size == 0) {
			printf("{}\n");
			continue;
		}

		for (int j = 0; j < res[i].size; j++) {
			printf("%d", res[i].data[j]);
		}
		printf("\n");
	}

    return 0;
}

/**
 binary search
 [LintCode ] Last Position of Target
 Find the last position of a target number in a sorted array. Return -1 if target does not exist.
 The array passed to function will decay to a pointer, so we have to give the length of the array to the function**
 @param nums: An integer array sorted in ascending order
 @param numSize: length of array
 @param target: An integer
 @return an integer
*/
int lastPosition(int nums[], int numSize, int target) {
	if (numSize == 0) {
		return -1;
	}

	int start = 0, end = numSize - 1;

	while (start + 1 < end) {
		int mid = start + (end - start) / 2;
		// last position: start = mid when == 
		// first position: end = mid when ==
		if (nums[mid] <= target) {
			start = mid;
		}
		else {
			end = mid;
		}
	}

	if (nums[end] == target) {
		return end;
	}

	if (nums[start] == target) {
		return start;
	}

	return -1;

}

/**
[LeetCode] 144. Binary Tree Preorder Traversal
/**
* Return an array of size returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* preorderTraversal(TreeNode *root, int* returnSize) {
	int* res = NULL;

	// edge case
	if (root == NULL)
		return res;
	
	*returnSize = 0;

    // using stack
	Stack *holder = malloc(sizeof(Stack));
	Stack_Init(holder);
	Stack_Push(holder, root);
	while (holder->size != 0) {
		TreeNode *tmp = Stack_Top(holder);
		res = (int *)realloc(res, (*returnSize + 1) * sizeof(int));
		res[*returnSize] = tmp->val;
		*returnSize += 1;
		Stack_Pop(holder);
		if (tmp->right != NULL) {
			Stack_Push(holder,tmp->right);
		}
		if (tmp->left != NULL) {
			Stack_Push(holder,tmp->left);
		}
	}

    // free the memory; clear the pointer
	free(holder);
	holder = NULL;

	return res;
}

/*
[LeetCode] 94. Binary Tree Inorder Traversal
non-recursion
/**
* Return an array of size returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* inorderTraversal(TreeNode* root, int* returnSize) {
	int* res = NULL;

	// edge case
	if (root == NULL)
		return res;

	*returnSize = 0;

	// using stack
	Stack *holder = malloc(sizeof(Stack));
	Stack_Init(holder);
	TreeNode* curr = root;
	while ((curr != NULL) || (holder->size != 0)) {
		//keep pushing left to the end
		while (curr != NULL) {
			Stack_Push(holder, curr);
			curr = curr->left;
		}
		TreeNode* top = Stack_Top(holder);
		// C++: res.push_back(top->val);
		res = (int *)realloc(res, (*returnSize + 1) * sizeof(int));
		res[*returnSize] = top->val;
		*returnSize += 1;
		Stack_Pop(holder);
		curr = top->right;
	}

	// free the memory; clear the pointer
	free(holder);
	holder = NULL;

	return res;
}

/*
[LeetCode]145. Binary Tree Postorder Traversal
non-recursion
/**
* Return an array of size returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* postorderTraversal(TreeNode *root, int* returnSize) {

	int* res = NULL;

	// edge case
	if (root == NULL)
		return res;

	*returnSize = 0;

	// using stack
	Stack *holder = malloc(sizeof(Stack));
	Stack_Init(holder);
	TreeNode* curr = root;
	TreeNode *prev = NULL;
	while (curr != NULL || holder->size != 0) {
		//keep pushing left to the end
		while (curr != NULL) {
			Stack_Push(holder, curr);
			curr = curr->left;
		}
		curr = Stack_Top(holder);
		//if it's leaf node or tracing up from right branch
		// pop and save it to the result
		if (curr->right == NULL || curr->right == prev) {
			Stack_Pop(holder);
			// C++: res.push_back(top->val);
			res = (int *)realloc(res, (*returnSize + 1) * sizeof(int));
			res[*returnSize] = curr->val;
			*returnSize += 1;
			prev = curr;
			curr = NULL; // needed to skip the inner while loop in the next round
		}
		// tracing up from left branch
		else {
			curr = curr->right;
		}
	}
	// free the memory; clear the pointer
	free(holder);
	holder = NULL;

	return res;
}

// [LeetCode] 102. Binary Tree Level Order Traversal
// Breadth First Search, BFS
/**
* Return an array of arrays of size *returnSize.
* The sizes of the inner arrays are *columnSizes.
* Note: Both returned array and columnSizes array must be malloced, assume caller calls free().
*/
int** levelOrder(TreeNode* root, int** columnSizes, int* returnSize) {
	int** res = NULL;

	//edge case
	if (root == NULL)
		return res;

	*returnSize = 0;
	**columnSizes = 0;

	// using queue
	Queue* Q = malloc(sizeof(Queue));
	Queue_Init(Q);
	Queue_Push(Q, root);

	int levelIndex = 0;
	while (Q->size != 0) {
		// remember this level's breadth, so inside for loop, only search the same level
		int QSize = Q->size;
		int* level = malloc(sizeof(int)); // store the vector of nodes in this level
		int size = 0;
		for (int i = 0; i < QSize; i++) {
			TreeNode *head = Queue_Front(Q); Queue_Pop(Q); //get the first element, then pop it
			
			// C++: level.push_back(head->val);
			level = (int*) realloc(level, (size + 1) * sizeof(int));
			level[size] = head->val;
			size += 1;
			if (head->left != NULL) {
				Queue_Push(Q, head->left);
			}
			if (head->right != NULL) {
				Queue_Push(Q, head->right);
			}
		}
		
		*columnSizes = realloc(*columnSizes, (levelIndex + 1) * sizeof(int));
		(*columnSizes)[levelIndex] = size;
		levelIndex += 1;
		
		// res.push_back(level);
		res = (int **)realloc(res, (*returnSize + 1) * sizeof(int*));
	
		res[*returnSize] = level;
		*returnSize += 1;
		int tmp = res[0][0];
		//!!DO NOT free level, because res[] =level, they are pointing to the same memory.
		/*free(level);
		level = NULL;*/

	}

	// free the memory; clear the pointer
	free(Q);
	Q = NULL;
	
	
	return res;

}

//冒泡排序
//时间复杂度为 0(n*n); 
void BubbleSort(Vector* x, int n) {
	//int i, j;
	//bool exchange; //记录交换标志
	//int temp;
	//for (i = 1; i < n; i++) {
	//	exchange = false;
	//	for (j = 0; j < n - i; j++)
	//	{
	//		if (x->data[j] > x->data[j + 1]) {
	//			temp = x->data[j];
	//			x->data[j] = x->data[j + 1];
	//			x->data[j + 1] = temp;
	//			exchange = true;
	//		}
	//	}
	//	if (!exchange)
	//		return;
	//}

	int m = n - 1;
	int i, j;
	int temp;

	while (m > 0)
	{
		for (j = 0; j < m; j++)
		{
			i = 0;
			if (x->data[j] > x->data[j + 1])
			{
				temp = x->data[j];
				x->data[j] = x->data[j + 1];
				x->data[j + 1] = temp;
				i = j; //记录每次交换的位置
			}
		}
		m = i;        //记录最后一个交换的位置
	}

}
/*helper for subset (combination) recursion
 在 Nums 中找到所有以 subset 开头的的集合，并放到 results
 *returnSize: size of results
 int numSize: size of nums
 int subsetSize: size of subset
*/
void helper(Vector** results,	int* returnSize, Vector* subset, Vector* nums, int start) {

	//results.push_back(subset);
	//initialize memory for Vector*
	*results = realloc(*results, (*returnSize + 1) * sizeof(Vector));
	//make a copy	
	(*results)[*returnSize] = *subset;
	//results[*returnSize] = subset;this is wrong; need copy not point to the same address
	*returnSize += 1;

	for (int i = start; i < nums->size; i++) {
		Vector_PushBack(subset, nums->data[i]);
		helper(results, returnSize, subset, nums, i + 1);
		Vector_PopBack(subset);
	}
}

Vector* subsets(Vector* nums, int* returnSize) {
	Vector** results = malloc(sizeof(Vector*));
	*results = malloc(sizeof(Vector));
	Vector* subset;
	Vector* res;
	// Initialize memory
	Vector tmp2;
	subset = &tmp2;
	Vector_Init(subset);
	//using qsort?
	BubbleSort(nums, nums->size);
	helper(results, returnSize, subset, nums, 0);
	res = *results;
	return res;
}

Vector* subsets2(Vector* nums, int* returnSize) {
	Vector* res;
	res = calloc(1 << (nums->size), sizeof(Vector));
	*returnSize = 1 << (nums->size);
	//res = malloc(sizeof(Vector));
	for (int i = 0; i < (1 << (nums->size)); i++) {
		Vector* subset;
		// Initialize memory
		Vector tmp;
		//tmp.data[0] = 0;
		//tmp.size = 0;
		subset = &tmp;
		Vector_Init(subset);
		int m = 0;
		for (int j = 0; j < nums->size; j++) {
			// check whether the jth digit in i's binary representation is 1
			
			if ((i & (1 << j)) != 0) {
				Vector_PushBack(subset, nums->data[j]);
				/*if (i == 7) {
					printf("subset: %d at %d from nums:%d\n", subset->data[m], m, j);
					m++;
				}*/
			}
			/*if (i == 7) {
				printf("subset: %d at 1\n", subset->data[1]);
			}*/
		}
		//res = realloc(res, (*returnSize + 1) * sizeof(Vector));
		//res[*returnSize] = *subset;
		//*returnSize += 1;
		/*if (i == 7) {
			printf("subset: %d at 1\n", subset->data[1]);
		}*/
		res[i] = *subset;
		/*if (i == 7) {
			printf("subset: %d at 1\n", subset->data[1]);
		}*/
	}
	return res;
}

/*
Purmuations
no duplicatged numbers
removing the duplicates requires sorting
*/
Vector* permute(Vector* nums, int* returnSize) {
	Vector* permutations;
	permutations = malloc(sizeof(Vector));
	permutations->size = 0;

	if (nums->size == 0) {
		return permutations;
	}
	
	int n = nums->size;
	Stack_Int* stack = malloc(sizeof(Stack_Int));
	Stack_Int_Init(stack);
	bool* inStack;
	inStack = calloc(nums->size, sizeof(bool));
	for (int i = 0; i < n; i++) {
		inStack[i] = false;
	}

	Stack_Int_Push(stack, -1);
	while (stack->size != 0) {
		// pop the last 
		int last = Stack_Int_Top(stack);
		Stack_Int_Pop(stack);
		if (last != -1) {
			inStack[last] = false;
		}

		// increase the last, find the next bigger & avaiable number
		int next = -1;
		for (int i = last + 1; i < n; i++) {
			if (inStack[i] == false) {
				next = i;
				break;
			}
		}
		if (next == -1) {
			continue;
		}

		// generate the next permutation
		Stack_Int_Push(stack, next);
		inStack[next] = true;
		for (int i = 0; i < n; i++) {
			if (!inStack[i]) {
				Stack_Int_Push(stack,i);
				inStack[i] = true;
			}
		}

		// generate real permutation from index
		Vector permutation;
		Vector_Init(&permutation);
		for (int i = 0; i < n; i++) {
			Vector_PushBack(&permutation, nums->data[stack->data[i]]);
		}

		permutations = realloc(permutations, (*returnSize + 1) * sizeof(Vector));
		permutations[*returnSize] = permutation;
		*returnSize += 1;

	}

	free(stack);
	free(inStack);

	return permutations;
}
