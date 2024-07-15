/*brute force mein you need to find the inorder, jab
inorder mil jayega then you can apply 2 sum jaise normal
array mein lagate the

Better Approach: Bst iterator use karenge, next function, inorder
ke sequence mein jo next element aata hai woh dega

Ek mein humein before find krni hai, ek mein next
Before means jo inorder ke sequence mein pehle aata hai,
next meants jo baad mein aata hai

Next mein: pehle toh saare left push karenge, jab hum next function ko
call krte hai tab jo top pe hai woh return krdenge and pop krdenge phir agar
uss element jo abhi humne pop kri uski right hai toh usko push krdenge and phir uski saare left ko bhi
push krdenge

Before mein: next ka opposit krni hai
*/

class BSTIterator
{
private:
    stack<TreeNode *> stk;
    bool fwd; // fwd->true means next, false means before
public:
    BSTIterator(TreeNode *root, bool isForward)
    {
        fwd = isForward;
        pushAll(root);
    }
    int next()
    {
        TreeNode *temp = stk.top();
        stk.pop();
        if (fwd == true)
        {
            pushAll(temp->right);
        }
        else
        {
            pushAll(temp->left);
        }
        return temp->val;
    }
    void pushAll(TreeNode *root)
    {
        while (root != NULL)
        {
            stk.push(root);
            if (fwd == true)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return false;
        }
        BSTIterator left(root, true);
        BSTIterator right(root, false);
        int i = left.next();
        int j = right.next();
        while (i < j)
        {
            if (i + j == k)
            {
                return true;
            }
            else if (i + j > k)
            {
                j = right.next();
            }
            else
            {
                i = left.next();
            }
        }
        return false;
    }
};