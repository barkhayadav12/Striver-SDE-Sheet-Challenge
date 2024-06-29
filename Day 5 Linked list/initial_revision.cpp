//basic linked list operations
/*
1.Insert
2.Display
3.Find min/max, count, sum
4.
*/

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
#include<climits>
using namespace std;

struct node{
    int val;
    node*next;
};

//insertion
void insertNode(node*p,int n)
{
    cout<<"Enter the other values: ";
    for(int i=1;i<n;i++)
    {
        node*temp=new node();
        int x;
        cin>>x;
        temp->val=x;
        temp->next=NULL;
        p->next=temp;
        p=temp;
    }

}

//displaying

void display(node*p)
{
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        p=p->next;
    }
}

//finding min

int minNode(node*p)
{
    int mini=INT_MAX;
    while(p!=NULL)
    {
        mini=min(mini,p->val);
        p=p->next;
    }
    return mini;
}

//finding max

int maxNode(node*p)
{
    int maxi=INT_MIN;
    while(p!=NULL)
    {
        maxi=max(maxi,p->val);
        p=p->next;
    }
    return maxi;
}

//finding sum

int findSum(node*p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->val;
        p=p->next;
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int headVal;
    cout<<"Enter the value of the head: ";
    cin>>headVal;
    node*head=new node();
    head->val=headVal;
    head->next=NULL;
    insertNode(head,n);
    display(head);
    cout<<"The total sum of the nodes is "<<findSum(head)<<endl;
    cout<<"The maximum node is "<<maxNode(head)<<endl;
    cout<<"The minimum node is "<<minNode(head)<<endl;
}