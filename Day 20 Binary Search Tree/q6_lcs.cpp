/*
2 cases:
1st case: dono node ek hi side pe ho, either left ya right, tab ussi direction mein 
jaana hai, left mein hai toh left jaana hai, right pe hai toh right pe jaana hai

2nd case: agar dono nodes different direction pe hai toh root hi humara answer hoga
*/

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)   {
        if(root==NULL)
        {
            return NULL;
        }
        int curr=root->val;
        if(curr>p->val && curr>q->val) //left pe hai dono toh move left
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(curr<p->val && curr<q->val)  //right pe hai dono toh move right
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;  //else diff direction pe hai toh root is our answer
        
    }
};