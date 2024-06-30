// brute force
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *p = head;
        unordered_set<ListNode *> mpp;
        while (p != NULL)
        {
            if (mpp.find(p) != mpp.end())
            {
                return true;
            }
            mpp.insert(p);
            p = p->next;
        }
        return false;
    }
};

// optimal approach
/*
Tortoise and Hare algo
fast pointer moves 2 steps
slow pinter moves 1 step

Intuition:

How are we so sure that slow and fast pointer will meet at a point if the linked list has a cycle?

jab slow and fast pointer jaha loop chl rhi waha pahunchenge and loop mein chlne lagenge,
slow pointer moves 1 step and fast moves 2 steps, so unki beech ki jo distance hai woh 1 se reduce ho rhi
hai, eventually woh distance after a point '0' bn jayegi, that's when they meet. Hum surely isiliye keh
skte hai kyunki unki beech ki distane 1 se reduce ho rhi hai, joh eventually '0' ho hi jayegi. Socho agar fast 
3 steps chl rha hota toh unki beech ki distance 2 se reduce hoti, tab unki beech ki distance eventually '0' na pahunche
aur fast cross kr jaaye slow pointer ko. So jab unki beech ki distance 1 se reduce ho rhi tab agar loop hogi
toh slow and fast pointer meet karenge.
*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};