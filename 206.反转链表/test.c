/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head) {
	Node* prev = NULL;
	Node* cur = head;
	Node* next = NULL;

	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	return prev;
}