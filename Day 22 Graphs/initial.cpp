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

/*
    Input
    Here, n: no. of nodes
          m: no. of edges
          And an adjacency matrix or list would be given as input
    Adjacency list---
    Let us consider 0 based indexing 

    Let us suppose there is edge between:

    2 1
    1 3
    2 4
    3 4
    2 5
    4 5
    
*/
/*

Traversal:
go to a node, print it, marked it as visited, and visit its neighbour if not already visited

*/
//bfs traversal

vector<int>bfs(vector<int>adj[],int n)
{
    vector<int>ans;
    queue<int>q;
    q.push(1); //considering 1 based indexing
    vector<int>vis(n+1,0);
    vis[1]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it:adj[temp])
        {
            //if not visited, push in queue and mark as visited
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return ans;
}

//dfs traversal

void dfs(vector<int>adj[],vector<int>&ans,vector<int>&vis,int node)
{
    vis[node]=1;
    ans.push_back(node);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(adj,ans,vis,it);
        }
    }
}

//cycle detection in undirected graph
/*
Agar koi node already visited hai and usko visit krne wala curr node
nhi hai toh there is a loop, usko pehle kisi aur ne visit krli hai
*/
//cycle detection in undirected graph using bfs traversal
bool isLoop(vector<int>adj[],int n,int src)
{
    //curr node , parent node
    queue<pair<int,int>>q;
    vector<int>vis(n+1,0);
    vis[src]=1;
    q.push({src,-1});
    while(!q.empty())
    {
        auto it=q.front();
        int curr_node=it.first;
        int parent_node=it.second;
        for(auto it:adj[curr_node])
        {
            //if not visited, visit karo
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,curr_node});
            }
            else{
                if(parent_node!=it)   //if already visited, check karo kya jo node visited hai woh parent 
                {                     //node hai kya, agar hai toh 'no' loop, agar woh visited node parent
                    return true;      //nhi hai toh there is a loop, usko kisi aur ne pehle hi visit krli hai
                }                      
            }
        }
    }
    return false;
}

//cycle detection in undirected graph using dfs traversal

bool isThereALoop(vector<int>adj[],vector<int>&vis,int node,int parent)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
           if(isThereALoop(adj,vis,it,node)==true)
           {
              return true;
           }
        }
        else if(it!=parent)
        {
            return true;
        }
    }
    return false;
}
/*
Topological Sort:
linear ordering of nodes/vertices such that if there exists 
an edge between 2 nodes u,v then ‘u’ appears before ‘v’
This can be possible only for DAG ( Directed acyclic graph) because in an undirected graph 
we can’t decide which node will come first because there will be no direction,
and if there is a cycle topological order will not be possible
*/

/*
Topo Sort using DFS Traversal
Intuition:
Normal dfs traversal karo and while going back stack mein push krdo, 
if there is an edge between u and v, toh pehle v over hoga and then uske baad u. Toh stack mein humne
v pehle push krdi and uske baad u ko push kr rhe, this makes sure ki agar u and v
ke beech koi edge hai toh u ko pehle print krde, aur kr bhi rhe hai kyunki stack ke upar mein pehle u aa rha 
phir v.
*/

//dfs topological sort
void topoSort(vector<int>adj[],vector<int>&vis,stack<int>&stk,int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            vis[it]=1;
            topoSort(adj,vis,stk,it);
        }
    }
    stk.push(node);
}

/*
Bfs topological sort traversal : Kahn's algorithm
The question states that if there is an edge between u and v then u should appear before v, 
Which means we have to start this question from a node that doesn't have any previous edges. 
But how to find that node that has no edge before if? Here, we use the concept of in-degree 
(Number of edges pointing toward a node). We find an in-degree which has indegree=0 and we start 
from this. We use the Indegree concept to find topological sorting
*/
/*
Steps:
1. Insert all nodes with indegree 0
2. Pop the front node and visit its neighbour and reduce its indegree, when the indegree
becomes 0 push it in queue
*/

vector<int>topoSortBfs(vector<int>adj[],int starting_node,int n)
{
    //finding indegree
    int indegree[n]={0}; //considering 0 based indexing
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            indegree[i]++;
        }
    }
    queue<int>q;
    //agar indegree 0 hua toh queue mein push krdo
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        for(auto it:adj[temp])
        {
            indegree[it]--;      //indegree ko reduce karo
            if(indegree[it]==0)  //agar indegree hua toh queue mein push krdo
            {
                q.push(it);
            }
        }
    }
    return ans;
}

/*
Bipartite graph
A bipartite graph is a graph which can be coloured using 2 colours such that no adjacent nodes have the same colour. 
Any linear graph with no cycle is always a bipartite graph. With a cycle, any graph with an even cycle length can also 
be a bipartite graph. So, any graph with an odd cycle length can never be a bipartite graph.

The intuition is the brute force of filling colours using any traversal technique, just make sure no two adjacent nodes 
have the same colour. If at any moment of traversal, we find the adjacent nodes to have the same colour, it means that there 
is an odd cycle, or it cannot be a bipartite graph. 

Queue mein dalo -> pop kro ->apni neighbours ko opposite color do -> if curr node ki color aur uski neighbour ki color same
hui toh return false
*/

/*
BFS Traversal : Bipartite graph
*/

bool isBipartite(vector<int>adj[],int n,int starting_node)
{
    vector<int>color(n,-1); //considering 0 based indexing
    color[starting_node]=1;
    q.push(starting_node);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto it:adj[temp])
        {
            if(color[it]==-1)  //that means yeh unvisited hai, agar visited hoti toh uski value 0 ya 1 mein change ho gayi hoti
            {
                color[it]=!color[temp];
                q.push(it);
            }
            else{
                if(color[it]==color[temp])  //curr node ki color aur uski neighbour ki color same ho gayi
                {
                    return false;
                }
            }
        }
    }
    return true;
}
/*
DFS traversal : Bipartite Graph
*/
void isBipartiteDfs(vector<int>adj[],int col,int node,vector<int>&color)
{
    color[node]=col;
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        {
            if(isBipartiteDfs(adj,!col,it,color)==false)
            {
                return false;
            }
        }
        else if(color[it]==col)
        {
            return false;
        }
    }
    return false;
}
int main()
{
    //n - number of nodes, m- number of edges
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];  //if 1 based indexing
    //taking input
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //if undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vector<int>ans=bfs(adj,n);
    // for(auto it:ans)
    // {
    //     cout<<it<<" ";
    // }
    vector<int>vis(n+1,0);
    vector<int>ans;
    dfs(adj,ans,vis,1);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}