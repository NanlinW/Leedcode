/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
	Node* cur = head;
	int sum = 0;
	while (cur->next)
	{
		cur = cur->next;
		sum++;
	}
	cur = head;
	for (int i = 0; i < sum - k + 1; i++)
	{
		cur = cur->next;
	}

	return cur;
}
