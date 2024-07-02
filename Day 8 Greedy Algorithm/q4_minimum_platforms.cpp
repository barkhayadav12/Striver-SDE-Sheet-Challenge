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

Firstly we sort the arrival and departure time independently, uske baad we compare the arrival and departure
time.

Main:

If a train is departing from the station, it has to be the one which has arrived prior so
it doesn't matter which train is leaving, we are concerned only with the platform, after the departure that
platform becomes empty and another train can arrive there.
is
*/

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dep(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dep[i];
    }
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 0;
    int j = 0;
    int maxi = 0;
    int cnt = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j]) //jo trains hai abhi woh depart nhi hui isiliye koi empty platform nhi hai jaha naayi train aa sake, isiliye platform badhao
        {
            cnt++;
            i++;
        }
        else //train depart ho gayi hai, mtlb koi platform empty ho gayi hai abhi, toh koi naayi train aa skti hai waha
        {
            cnt--;
            j++;
        }
        maxi = max(maxi, cnt);
    }
    cout << maxi << endl;
}