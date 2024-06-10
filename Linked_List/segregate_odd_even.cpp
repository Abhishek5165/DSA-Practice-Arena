// Time Complexity: O(N).
// space Space: O(1).

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *odd = head;
        ListNode *temp = head->next;
        ListNode *even = head->next;

        while (even != NULL && even->next != NULL)
        {

            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = temp;
        return head;
    }
};