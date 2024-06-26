#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
using namespace std;

/*
Not the best optimal solution, but khud hi hai so chhoddo
*/

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    stack<pair<int, int>> stk;
    stk.push({intervals[0][0], intervals[0][1]});
    int n = intervals.size();
    for (int i = 1; i < n; i++)
    {
        int first = intervals[i][0];
        int second = intervals[i][1];
        auto it = stk.top();
        int stk_first = it.first;
        int stk_second = it.second;
        if (stk_second >= first)
        {
            stk.pop();
            stk.push({min(first, stk_first), max(second, stk_second)});
        }
        else
        {
            stk.push({intervals[i][0], intervals[i][1]});
        }
    }
    vector<vector<int>> ans;
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();
        int first = it.first;
        int second = it.second;
        ans.push_back({first, second});
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int m = 2;
    vector<vector<int>> intervals(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0];
        cin >> intervals[i][1];
    }

    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}