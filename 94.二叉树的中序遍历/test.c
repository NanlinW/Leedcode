/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int TreeSize(struct TreeNode* root)//计算节点数量方便开辟空间
{
	if (root == NULL)
	{
		return 0;
	}
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}

int* _inorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
	{
		return;
	}
	_inorderTraversal(root->left, array, pIndex);
	array[*pIndex] = root->val;
	++(*pIndex);
	_inorderTraversal(root->right, array, pIndex);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	int* array = (int*)malloc(*returnSize * sizeof(int));

	int index = 0;
	_inorderTraversal(root, array, &index);
	return array;
}

