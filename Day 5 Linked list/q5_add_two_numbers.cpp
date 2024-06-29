class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1;
        ListNode *q = l2;
        int ans = p->val + q->val;
        int rem = 0;
        ListNode *head;
        ListNode *temp;
        if (ans >= 10)
        {
            rem = ans / 10;
            head = new ListNode(ans % 10);
        }
        else
        {
            head = new ListNode(ans);
        }
        head->next = NULL;
        p = p->next;
        q = q->next;
        ListNode*k=head;
        while (p != NULL && q != NULL)
        {
            ans = p->val + q->val;
            ans += rem;
            rem = 0;
            if (ans >= 10)
            {
                rem = ans / 10;
                temp = new ListNode(ans % 10);
            }
            else
            {
                temp = new ListNode(ans);
            }
            temp->next = NULL;
            k->next = temp;
            k = temp;
            p = p->next;
            q = q->next;
        }
        while (p != NULL)
        {
            ans = p->val;
            ans += rem;
            rem = 0;
            if (ans >= 10)
            {
                rem = ans / 10;
                temp = new ListNode(ans % 10);
            }
            else
            {
                temp = new ListNode(ans);
            }
            temp->next = NULL;
            k->next = temp;
            k = temp;
            p = p->next;
        }
        while (q != NULL)
        {
            ans = q->val;
            ans += rem;
            rem = 0;
            if (ans >= 10)
            {
                rem = ans / 10;
                temp = new ListNode(ans % 10);
            }
            else
            {
                temp = new ListNode(ans);
            }
            temp->next = NULL;
            k->next = temp;
            k = temp;
            q = q->next;
        }
        if (rem != 0)
        {
            ListNode *last = new ListNode(rem);
            last->next = NULL;
            temp->next = last;
        }
        return head;
    }
};