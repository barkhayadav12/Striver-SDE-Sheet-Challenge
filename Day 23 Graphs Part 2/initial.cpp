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
Dijkstra's algorithm
*/

vector<int>shortestPath(vector<vector<int>>adj[],int n,int src)
{
    vector<int>dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i]=1e9;
    }
    dist[src]=0;
    //creating a min heap -- pair of distance and node
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node])
        {
            int adjNode=it[0];
            int adjWt=it[1];
            if(dis+adjWt<dist[adjNode])
            {
                dist[adjNode]=dis+adjWt;
                pq.push({dis+adjWt,adjNode});
            }
        }
    }
    return dist;
}
/*
Visualize ki hum input kaise le rhe hai....
0 -> {1,4} {2,4}
1 -> {0,4} {2,2}

jab hum vector<int>adj[n] kr rhe the toh iska mtlb tha ki we have created an array of size
n and each array index could be treated as an array jismein kitne bhi values aa skte hai kyunki 
vector hai toh dynamic hai(array of array type hai)

vector<vector<int>>adj[n]-- humne ek array banayi jiska size hai n,and uss array mein humne
ek array pass ki hai jismein, hum jis node se woh connected hai woh store karenge plus
u and v ke beech mein jo weight hai woh store karenge aur values bhi store kr skte hai par nhi karenge kyunki
needed nhi hai, and this type of pair hum kitne bhi store kr skte hai kyunki vector hai toh dynamic hai
*/
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        vector<int>temp;
        temp.push_back(v);
        temp.push_back(wt);
        adj[u].push_back(temp);
        vector<int>temp_two;
        temp_two.push_back(u);
        temp_two.push_back(wt);
        adj[v].push_back(temp_two);
    }
    vector<int>dist=shortestPath(adj,n,0);

}