/*
Dry run to understand better
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // insert copy nodes in between

        Node *temp = head;
        while (temp != NULL)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }

        // connect random pointers

        temp = head;
        while (temp != NULL)
        {
            Node *copyNode = temp->next;

            // checking if temp->random is pointing to NULL
            if (temp->random)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }

        // connect next pointer

        Node *dummy = new Node(-1);
        Node *res = dummy;
        temp = head;
        while (temp != NULL)
        {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};