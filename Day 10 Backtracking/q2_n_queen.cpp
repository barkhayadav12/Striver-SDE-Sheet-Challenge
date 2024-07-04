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

void solve(int n, int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal)
{
    // base case
    if (n == col)
    {
        ans.push_back(board);
        return;
    }
    // traversing the row
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(n, col + 1, ans, board, leftRow, lowerDiagonal, upperDiagonal);
            // backtrack
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> leftRow(n, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);
    vector<int> upperDiagonal(2 * n - 1, 0);
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<vector<string>> ans;
    solve(n, 0, ans, board, leftRow, lowerDiagonal, upperDiagonal);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}