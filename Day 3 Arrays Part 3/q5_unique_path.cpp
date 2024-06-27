#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>
#include<math.h>
using namespace std;

int path(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0 || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int up=path(i-1,j,dp);
        int left=path(i,j-1,dp);
        return dp[i][j]=up+left;
    }

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<path(n-1,m-1,dp)<<endl;
}