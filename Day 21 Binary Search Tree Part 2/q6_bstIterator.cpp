/*
Inorder ki sequence mein next kya aayega wahi return krni hai

Left push krte jao, jab next function ko call lagayenge tab top
ko pop krdenge and agar top ki koi right hogi toh usko aur uske left ko push krdenge

Agar stack empty hai toh koi next nhi hoga
*/

class BSTIterator
{
private:
    stack<TreeNode *> stk;
    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            stk.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = stk.top();
        stk.pop();
        if (temp->right)
        {
            pushAll(temp->right);
        }
        return temp->val;
    }

    bool hasNext()
    {
        if (!stk.empty())
        {
            return true;
        }
        return false;
    }
};