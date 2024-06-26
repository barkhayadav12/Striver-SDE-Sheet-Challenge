#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

/*
Rotating the matrix clockwise
1.reversing the 2D array first
2.Swap the symmetry e.g matrix[0][1] & matrix[1][0]

    1 2 3       7 8 9       7 4 1
    4 5 6  -->  4 5 6  -->  8 5 2
    7 8 9       1 2 3       9 6 3
*/

void rotateClockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

/*
Rotating the matrix anti-clockwise
1.reversing the every row
2.Swap the symmetry e.g matrix[0][1] & matrix[1][0]

    1 2 3       3 2 1       3 6 9
    4 5 6  -->  6 5 4  -->  2 5 8
    7 8 9       9 8 7       1 4 7
*/

void rotateAntiClockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    rotateAntiClockwise(matrix);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

/*
One more variation hai (LeetCode question- 1886),
jismein bola hai ki 2d array ko 90 deg rotate kr skte
any number of times

0 deg- no change
90,180,270- 3 times rotate kr skte hai
360 deg- no change

During these 3 rotation, 2 given array same ho gayi toh
return true, else false
*/