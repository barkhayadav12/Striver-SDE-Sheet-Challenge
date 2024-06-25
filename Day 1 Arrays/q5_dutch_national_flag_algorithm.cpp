#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void sortColors(vector<int> &nums)
{
    int start=0;
    int mid=0;
    int end=nums.size()-1;
    while(mid<=end)
    {
        if(nums[mid]==0)
        {
            swap(nums[start],nums[mid]);
            start++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else{
            swap(nums[end],nums[mid]);
            end--;
            mid++;
        }
    }
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
    sortColors(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}