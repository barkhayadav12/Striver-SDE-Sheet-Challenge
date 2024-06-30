class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *p = head;
        while (p != NULL)
        {
            int x = p->val;
            v.push_back(x);
            p = p->next;
        }
        vector<int> res;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            res.push_back(v[i]);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != res[i])
            {
                return false;
            }
        }
        return true;
    }
};