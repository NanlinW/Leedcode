/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;//后面只需要使用Node*

struct ListNode* removeElements(struct ListNode* head, int val)
{
	Node* cur = head;
	Node* prev = NULL;

	while (cur)
	{
		if (cur->val == val)
		{
			if (cur == head)//删除的节点是第一个节点
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else//删除非第一个节点
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}
