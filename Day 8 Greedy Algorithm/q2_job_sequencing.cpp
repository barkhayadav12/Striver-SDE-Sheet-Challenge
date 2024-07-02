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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    cin >> n;
    // profit,deadline
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++)
    {
        int dead, profit;
        cin >> dead >> profit;
        jobs.push_back({dead, profit});
    }

    // sort acc to profit

    sort(jobs.begin(), jobs.end(), cmp);

    // create a deadline array having size same as the max deadline
    int size = 0;
    for (auto it : jobs)
    {
        size = max(size, it.first);
    }
    bool arr[size + 1];
    for (int i = 0; i <= size; i++)
    {
        arr[i] = false;
    }
    int tot_profit = 0;
    for (auto it : jobs)
    {
        int dead = it.first;
        int val = it.second;
        for (int j = dead; j > 0; j--)
        {
            if (arr[j] == true)
            {
                continue;
            }
            else
            {
                arr[j] = true;
                tot_profit += val;
                break;
            }
        }
    }
    cout << tot_profit << endl;
}