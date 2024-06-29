/*
Hare & tortoise algorithm
->slow and fast pointer
slow pointer ek node move karegi at a time
fast pointer 2 node move karegi at a time

detect cycle,delete nth node, middle of a node mein use hoti hai
*/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
