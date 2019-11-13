/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _preorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	array[*pIndex] = root->val;
	++(*pIndex);
	_preorderTraversal(root->left, array, pIndex);
	_preorderTraversal(root->right, array, pIndex);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = TreeSize(root);
	int* array = (int*)malloc(*returnSize * sizeof(int));
	int index = 0;

	_preorderTraversal(root, array, &index);

	return array;
}

