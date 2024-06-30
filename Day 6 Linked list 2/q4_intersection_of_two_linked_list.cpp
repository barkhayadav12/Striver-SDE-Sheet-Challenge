class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> mpp;
        ListNode *p = headA;
        while (p != NULL)
        {
            mpp.insert(p);
            p = p->next;
        }
        ListNode *ans = NULL;
        ListNode *q = headB;
        while (q != NULL)
        {
            if (mpp.find(q) != mpp.end())
            {
                ans = q;
                break;
            }
            q = q->next;
        }
        return ans;
    }
};