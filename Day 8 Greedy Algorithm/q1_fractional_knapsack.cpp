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
Here, we are using greedy approach. Since we can break the items
also, as we want to maximize the profit, we can take those items first
whose p/w ( i.e cost of the item when the wt is 1 unit ) is greater.

Easy way to think of this problem:

Lower class mein jo mensuration padha tha wahi hai,

Eg: if 20kg of apple cost Rs 100,
    then, cost of 1kg apple=100/20

So, humein profit maximize krni hai, aur hum items ko fraction
mein le skte hai isiliye jis item ka 1kg mein jyada profit aa rha
unn items ko le rhe hai pehle.

If curr wt jo wt given hai uss se <= hai toh hum uss item ko
le skte hai, else uss item ka ek fraction lena hai (bachi hui wt * uski 1unit ka cost i.e p/w)
*/

bool cmp(pair<int, int> a, pair<int, int> b)
{
    double x = (double)a.first / (double)a.second;
    double y = (double)b.first / (double)b.second;
    return x > y;
}

int main()
{
    int n, W;
    cin >> n >> W;
    //pair - profit,weight
    vector<pair<int, int>> item;
    for (int i = 0; i < n; i++)
    {
        int val, wt;
        cin >> val >> wt;
        item.push_back({val, wt});
    }
    double profit = 0.0;
    for (auto it : item)
    {
        int wt = it.second;
        int val = it.first;
        if (wt <= W)
        {
            W -= wt;
            profit += val;
        }
        else
        {
            profit += (double)W * ((double)val / (double)wt);
            break;
        }
    }
    cout << profit << endl;
}