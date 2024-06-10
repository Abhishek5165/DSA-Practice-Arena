// Time Complexity : O(2N)
// Space Complexity : O(1)

// Approch - 1 Using the Length of the Linked List.

class Solution
{
public:
    int length(ListNode *temp)
    {
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;

        int len = length(head);

        if (len == n)
        {
            ListNode *newNode = head->next;
            return newNode;
        }

        int count = 1;
        while (count < ((len - n) + 1) && temp->next != NULL)
        {
            count++;
            prev = temp;
            temp = temp->next;
        }
        ListNode *farzi = temp;
        prev->next = temp->next;
        temp->next = NULL;
        delete (farzi);
        return head;
    }
};

// Approch - 2 Using slow & fast Pointers;

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            ListNode *temp = head;
            head = head->next;
            delete (temp);
            return head;
        }
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *farzi = slow->next;
        slow->next = slow->next->next;
        delete (farzi);
        return head;
    }
};