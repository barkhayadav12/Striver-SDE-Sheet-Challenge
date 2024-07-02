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
Intuition:
Say if you have two meetings, one which gets over early
and another which gets over late. Which one should we choose?
If our meeting lasts longer the room stays occupied and we lose our time.
On the other hand, if we choose a meeting that finishes early we can accommodate more meetings.
Hence we should choose meetings that end early and utilize the remaining time for more meetings.
*/

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    vector<int> end(n);
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    // pair - start,end

    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }

    // sort acc to end time
    sort(meetings.begin(), meetings.end(), cmp);
    int cnt = 0;
    int prev = -1;
    for (auto it : meetings)
    {
        int start_time = it.first;
        int end_time = it.second;
        if (start_time > prev)
        {
            cnt++;
            prev = end_time;
        }
        else
        {
            continue;
        }
    }
    cout << cnt << endl;
}