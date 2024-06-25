#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<vector<int>> generate(int n)
{
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 || j == 0 || i == j)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            temp.push_back(arr[i][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans = generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}