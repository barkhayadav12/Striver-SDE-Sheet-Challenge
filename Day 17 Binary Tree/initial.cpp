#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <numeric>

using namespace std;

// creating a node

struct node
{
    node *lchild;
    int val;
    node *rchild;
};

class tree
{
public:
    node *root;
    tree()
    {
        root = NULL;
    }
    node *newNode(int data);
    node *insertNode(node *root, int data);
    bool isPresent(node *root, int target);
    int minElement(node *root);
    int maxElement(node *root);
    void preOrder(node *root);
    void inOrder(node *root);
    void postOrder(node *root);
    void levelOrder(node *root);
    vector<vector<int>> verticalOrderTraversal(node *root);
    vector<int>topView(node*root);
    vector<int>bottomView(node*root);
    void leftView(node*root,int level,vector<int>&leftview);
};
// creating a new node
node *tree::newNode(int data)
{
    node *temp = new node();
    temp->val = data;
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}
// inserting a node
node *tree::insertNode(node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    if (root->val > data)
    {
        return root->lchild = insertNode(root->lchild, data);
    }
    else
    {
        return root->rchild = insertNode(root->rchild, data);
    }
}

// searching whether an element exists or not
bool tree::isPresent(node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == target)
    {
        return true;
    }
    return isPresent(root->lchild, target) || isPresent(root->rchild, target);
}

// finding the min element

int tree::minElement(node *root)
{
    if (root->lchild == NULL)
    {
        return root->val;
    }
    return minElement(root->lchild);
}

// finding the max element

int tree::maxElement(node *root)
{
    if (root->rchild == NULL)
    {
        return root->val;
    }
    return minElement(root->rchild);
}

// pre order traversal

void tree::preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preOrder(root->lchild);
    preOrder(root->rchild);
}

// inOrder traversal

void tree::inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->lchild);
    cout << root->val << " ";
    inOrder(root->rchild);
}

// post order

void tree::postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    cout << root->val << " ";
}

// level order

void tree::levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->lchild)
        {
            q.push(temp->lchild);
        }
        if (temp->rchild)
        {
            q.push(temp->rchild);
        }
    }
}

// vertical order traversal

// need to traverse vertically

vector<vector<int>> tree::verticalOrderTraversal(node *root)
{
    //[vertical,[level,node value]]
    map< int, map<int, multiset<int>>> mpp;
    //{node,{vertical,level}}
    queue < pair<node *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *temp = it.first;
        int vert = it.second.first;
        int level = it.second.second;
        // inserting node value
        mpp[vert][level].insert(temp->val);
        // going left
        if (temp->lchild)
        {
            q.push({temp->lchild,{vert - 1, level + 1}});
        }
        // going right
        if (temp->rchild)
        {
            q.push({temp->rchild,{ vert + 1, level + 1}});
        }
    }
    // printing
    vector<vector<int>> ans;
    //it map ko point kr rhi
    for (auto it : mpp)
    {
        vector<int> v;
        //abhi i, map<int,multiset> ko point kr rhi
        for (auto i : it.second)
        {
            //abhi j, multiset ko point kr rhi
            for (auto j : i.second)
            {
                v.push_back(j);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

//top view

vector<int>tree::topView(node*root)
{
    //[vertical,node value]
    map<int,int>mpp;
    //{node, vertical}
    queue<pair<node*,int>>q;
    vector<int>ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        node*temp=it.first;
        int val=temp->val;
        int vert=it.second;
        if(mpp.find(vert)==mpp.end())
        {
            mpp[vert]=val;
        }
        if(temp->lchild)
        {
            q.push({temp->lchild,vert-1});
        }
        if(temp->rchild)
        {
            q.push({temp->rchild,vert+1});
        }
    }
    for(auto it:mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//bottom view

vector<int>tree::bottomView(node*root)
{
    //[vertical,node value]
    map<int,int>mpp;
    //{node, vertical}
    queue<pair<node*,int>>q;
    vector<int>ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        node*temp=it.first;
        int val=temp->val;
        int vert=it.second;
        mpp[vert]=val;
        if(temp->lchild)
        {
            q.push({temp->lchild,vert-1});
        }
        if(temp->rchild)
        {
            q.push({temp->rchild,vert+1});
        }
    }
    for(auto it:mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

//left view 
void tree::leftView(node*root,int level,vector<int>&leftview)
{
    if(root==NULL)
    {
        return;
    }
    if(leftview.size()==level)
    {
        leftview.push_back(root->val);
    }
    leftView(root->lchild,level+1,leftview);
    leftView(root->rchild,level+1,leftview);
}

int main()
{
    tree t;
    t.root = t.newNode(10);
    t.insertNode(t.root, 20);
    t.insertNode(t.root, 5);
    cout << "Pre Order Traversal: ";
    t.preOrder(t.root);
    cout << endl;
    cout << "In Order Traversal: ";
    t.inOrder(t.root);
    cout << endl;
    cout << "Post Order Traversal: ";
    t.postOrder(t.root);
    cout << endl;
    cout << "Level Order Traversal: ";
    t.levelOrder(t.root);
    cout << endl;
    vector<vector<int>> ans = t.verticalOrderTraversal(t.root);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout<<endl;
    cout<<"Top View ";
    vector<int>topview=t.topView(t.root);
    for(int i=0;i<topview.size();i++)
    {
        cout<<topview[i]<<" ";
    }
    cout<<endl;
    cout<<"Bottom View ";
    vector<int>bottomview=t.bottomView(t.root);
    for(int i=0;i<bottomview.size();i++)
    {
        cout<<bottomview[i]<<" ";
    }
    cout<<endl;
    vector<int>leftview;
    t.leftView(t.root,0,leftview);
    for(int i=0;i<leftview.size();i++)
    {
        cout<<leftview[i]<<" ";
    }
}