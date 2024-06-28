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

int largestSubarray(vector<int> &arr, int n)
{
    int sum = 0;
    int len = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            len = i + 1;
        }
        if (mpp.find(sum) != mpp.end())
        {
            len = max(len, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    return len;
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
    cout << largestSubarray(arr, n) << endl;
}