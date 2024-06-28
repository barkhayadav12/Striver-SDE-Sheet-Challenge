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
using namespace std;

int main()
{
    string s;
    cin>>s;

    map<char,int>mpp;
    int i=0;
    int j=0;
    int n=s.length();
    int ans=0;
    while(j<n)
    {
        mpp[s[j]]++;
        if(mpp.size()==j-i+1)
        {
            ans=max(ans,j-i+1);
        }
        else if(mpp.size()<j-i+1)
        {
            while(mpp.size()<j-i+1)
            {
                mpp[s[i]]--;
                if(mpp[s[i]]==0)
                {
                    mpp.erase(mpp[s[i]]);
                }
                i++;
            }
        }
        j++;
    }
    cout<<ans<<endl;
}