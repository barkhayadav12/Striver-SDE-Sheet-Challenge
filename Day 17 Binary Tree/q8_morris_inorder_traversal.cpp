/*
Step 1: Initialize current as root

Step 2: While current is not NULL,

If current does not have left child

    a. Add current’s value

    b. Go to the right, i.e., current = current.right

Else

    a. In current's left subtree, make current the right child of the rightmost node

    b. Go to this left child, i.e., current = current.left
*/

vector<int> inorderTraversal(TreeNode *root)
{
    TreeNode *curr = root;
    vector<int> ans;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // print and go right
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *leftChild = curr->left;
            // extreme right pe jao
            while (leftChild->right != NULL)
            {
                leftChild = leftChild->right;
            }
            // right ko curr se connect krdo
            leftChild->right = curr;
            // detach krdo link between curr and curr->left, but uske pehle go to current's left
            TreeNode *temp = curr;
            // go to curr's left
            curr = curr->left;
            // detach
            temp->left = NULL;
        }
    }
    return ans;
}
}
;