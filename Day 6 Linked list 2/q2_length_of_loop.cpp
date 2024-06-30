// optimal approach (Tortoise and hare algo)
class Solution
{
public:
    int lengthOfCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) // has cycle
            {
                int cnt = 1;
                slow = slow->next;
                while (slow != fast)
                {
                    cnt++;
                    slow = slow->next;
                }
                return cnt;
            }
        }
        // does not have cycle
        return 0;
    }
};
