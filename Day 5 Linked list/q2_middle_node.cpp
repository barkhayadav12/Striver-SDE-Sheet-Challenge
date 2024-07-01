/*
Tortoise and Hare algorithm
->slow and fast pointer
slow pointer 1 step move karegi at a time
fast pointer 2 step move karegi at a time

detect cycle,delete nth node, middle of a node mein use hoti hai

Intution:

Why this works?

Suppose a person 'P1' moves with speed 'x' , another person 'P2' moves with speed '2*x',
toh obvious hai ki jab the person that moves 2x reaches the end, P1 middle hi pahuncha hoga tab.

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
