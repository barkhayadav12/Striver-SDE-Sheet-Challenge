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

int largestSubarrayWithXorK(vector<int> &arr, int n, int k)
{
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        if (mpp.find(x) != mpp.end())
        {
            cnt += mpp[x];
        }
        mpp[xr]++;
    }

    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << largestSubarrayWithXorK(arr, n, k) << endl;
}