//using merge Sort
class Solution {
public:
    ListNode*findMid(ListNode*p)
    {
        ListNode*x=p;
        ListNode*y=p->next;
        while(y!=NULL && y->next!=NULL)
        {
           x=x->next;
           y=y->next->next;
        }
        return x;
    }
    ListNode*merge(ListNode*left,ListNode*right)
    {
        ListNode*dummyNode=new ListNode(-1);
        ListNode*temp=dummyNode;
        while(left!=NULL && right!=NULL)
        {
            if(left->val<right->val)
            {
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        if(left)
        {
            temp->next=left;
        }
        else{
            temp->next=right;
        }
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL ||head->next==NULL)
        {
            return head;
        }
        ListNode*mid=findMid(head);
        ListNode*right=mid->next;
        mid->next=NULL;
        ListNode*left=head;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);

    }
};