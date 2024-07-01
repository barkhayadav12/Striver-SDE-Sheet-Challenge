/*
1. Tail pointer is pointing to head
2. (Totalnode-k+1)th node becomes the head
3. (Totalnode-k)th node will now point to NULL

Dry run and see to understand better
*/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        int total_node = 1;
        ListNode *temp = head;
        //finding the total number of nodes and the tail pointer
        while (temp->next != NULL)
        {
            total_node++;
            temp = temp->next;
        }
        ListNode *tail = temp;

        //if k is a multiple of k, there would be no change i.e if k=5 and total number of nodes is 5, after 5th rotation, we will get the same linked list w/o any change.

        if (k % total_node == 0)
        {
            return head;
        }

        //given k could be greater than the total no. of nodes, in that case, k would be k % total_node

        k = k % total_node;
        int reqd = total_node - k;

        //last tail ptr will point to the head

        tail->next = head;
        temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            //if we have reached (total-k)th node, (total-k+1)th node will be the new head, (total-k)th node will point to NULL
            if (cnt == reqd)
            {
                head = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};