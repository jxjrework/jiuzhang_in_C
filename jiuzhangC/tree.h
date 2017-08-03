#pragma once

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

char* serialize(TreeNode* root);
TreeNode* deserialize(char *data);
