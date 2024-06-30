// brute force

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> mpp;
        ListNode *p = head;
        ListNode *ans = NULL;
        while (p != NULL)
        {
            if (mpp.find(p) != mpp.end())
            {
                ans = p;
                break;
            }
            mpp.insert(p);
            p = p->next;
        }
        return ans;
    }
};

// optimal approach

/*
Why does this work?
Intuition:
Let x1=distance from head to start of loop
    x2=distance from start of loop to where slow and fast pointer meets
    x3=distance from the point fast and slow meet to the start of the loop

then, distance slow moved=x1+x2
      distance fast moved=x1+x2+x3+x2

since, fast pointer runs twice the speed of slow ptr.Therefore, when they meet, 
distance travelled by fast ptr will be 2*(distance travelled by slow ptr)

now, 2(x1+x2)=x1+x2+x3=x2
     x1=x3
     i.e distance from the head to the start of loop == distance from the point fast and slow pointer meets to the start of loop
*/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) //there is a loop
            {
                slow = head;
                while (fast != slow) 
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};