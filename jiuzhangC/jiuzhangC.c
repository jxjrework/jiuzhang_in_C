#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "tree.h"

// binary search:[LintCode] Last Position of Target
int lastPosition(int nums[], int numSize, int target);
// preorder traversal
int* preorderTraversal(TreeNode *root);

int main()
{
	/*// test binary search
	int nums[10] = { 0,1,1,1,3,4,5,5,6,7 };
	int res;

	// Get the array size
	int numSize = sizeof(nums) / sizeof(nums[0]);
	res = lastPosition(nums, numSize, 5);
	printf("%d\n", res);
	*/

	/*// test serialization/deserialization
	char* string = "{12#5678#9##321}";
	char* res;
	TreeNode* tmp;
	tmp = deserialize(string, 16);
	printf("%d\n", tmp->left->val);
	res = serialize(tmp);
	printf("%s\n", res);
	*/


	// test preorder traverssal of binary tree
	char* string = "{12#56789}";
	int* res;
	TreeNode* tmp;
	tmp = deserialize(string, 10);
	res = preorderTraversal(tmp);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", res[i]);
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
int* preorderTraversal(TreeNode *root) {
	int* res = NULL;

	// edge case
	if (root == NULL)
		return res;
	
	int returnSize = 0;
    // using stack
	Stack *holder = malloc(sizeof(Stack));
	Stack_Init(holder);
	Stack_Push(holder, root);
	while (holder->size != 0) {
		TreeNode *tmp = Stack_Top(holder);
		res = (int *)realloc(res, (returnSize + 1) * sizeof(int));
		*(res + returnSize) = tmp->val;
		returnSize += 1;
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
