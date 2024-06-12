// Time Complexity : O(n+k) or O(L/k + constant)
// Space Complexity : O(1)

class Solution
{
public:
    int Length(ListNode *temp)
    {
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {

        vector<ListNode *> ans(k, NULL);

        int L = Length(head);
        int nodesCount = L / k;
        int extra = L % k;

        ListNode *prev = NULL;
        ListNode *curr = head;

        for (int i = 0; i < k && curr != NULL; i++)
        {

            ans[i] = curr;
            for (int count = 0; count < nodesCount + (extra > 0 ? 1 : 0); count++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            extra--;
        }
        return ans;
    }
};