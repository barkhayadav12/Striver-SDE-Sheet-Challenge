
//brute force

//if(cnt==n), that means we need to delete the head

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        if(cnt==n)
        {
            ListNode*newHead=head->next;
            return newHead;
        }
        ListNode*p=head;
        int res=cnt-n;
        while(p!=NULL)
        {
            res--;
            if(res==0)
            {
                break;
            }
            p=p->next;
        }
        ListNode*q=p->next;
        p->next=q->next;
        return head;
    }
};


//optimised approach using 2 pointer
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*fast=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            return head->next;
        }
        ListNode*slow=head;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*temp=slow->next;
        slow->next=temp->next;
        return head;
    }
};