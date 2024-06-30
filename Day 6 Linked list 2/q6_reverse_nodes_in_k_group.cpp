class Solution
{
public:
    // reversing the linked list
    ListNode *reverseLinkedList(ListNode *temp)
    {
        ListNode *prev = NULL;
        ListNode *curr = temp;
        while (curr != NULL)
        {
            ListNode *front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    // getting the kth node
    ListNode *getKthNode(ListNode *temp, int k)
    {
        k -= 1;
        while (temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *kthNode = getKthNode(temp, k);
            // if the kth node is null, that means a kth group can't be formed
            if (kthNode == NULL)
            {
                // if previous groups was there before, link the last node to the curr node
                if (prev)
                {
                    prev->next = temp;
                }
                break;
            }
            // store the next node that is right after the kth node
            ListNode *nextNode = kthNode->next;

            // detach the kth node for reversal

            kthNode->next = NULL;

            // reverse the group(from current node to the kth node)
            reverseLinkedList(temp);

            // if this is the first group (that means temp will be equal to temp), make the kth node head
            if (temp == head)
            {
                head = kthNode;
            }
            else
            {
                prev->next = kthNode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};