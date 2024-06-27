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

/*
brute force gives tle, use merge sort
before merging, do the comparison
*/

void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] > nums[right])
        {
            temp.push_back(nums[right]);
            right++;
        }
        else
        {
            temp.push_back(nums[left]);
            left++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
int countPairs(vector<int> &nums, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && nums[i] > 2 * (long long)nums[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
    }
    return cnt;
}
int mergeSort(vector<int> &nums, int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }
    int mid = (low + high) / 2;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid + 1, high);
    cnt += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << mergeSort(nums, 0, n - 1) << endl;
}