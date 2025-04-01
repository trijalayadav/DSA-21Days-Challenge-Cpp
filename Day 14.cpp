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
class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min-heap (smallest element at top)
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

        int k = lists.size();
        if (k == 0)
        {
            return NULL;
        }
        for (int i = 0; i < k; i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(lists[i]);
            }
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (!minHeap.empty())
        {
            ListNode *top = minHeap.top();
            minHeap.pop();
            if (head == NULL)
            {
                head = top;
                tail = top;
                if (top->next)
                {
                    minHeap.push(top->next);
                }
            }
            else
            {
                tail->next = top;
                tail = top;
                if (tail->next)
                {
                    minHeap.push(tail->next);
                }
            }
        }
        return head;
    }
};