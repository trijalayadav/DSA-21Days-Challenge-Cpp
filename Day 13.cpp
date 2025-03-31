/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }

        int countNodes = 0;
        ListNode *temp = head;
        while (temp)
        {
            countNodes++;
            temp = temp->next;
        }

        if (countNodes < k)
        {
            return head;
        }
        ListNode *next = NULL;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int count = 0;
        while (curr != NULL && count++ < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};