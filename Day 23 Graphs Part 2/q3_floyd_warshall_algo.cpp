/*
Floyd Warshall Algorithm :

This algo is used to find shortest path for every node, in short for every node, we need
to find shortest distance to every node

Algo :
We need to go via every node and find the min path, check kr rhe ki iss node ke via jaane se
min path mil rhi hai ya nhi

Can detect negative cycles also ?
How to check?
for(int i=0;i<matrix.size();i++)
{
    if(matrix[i][i]<0)  // because negative cycle exists karegi toh < 0 ho jayegi iski value [0][0],[1][1] ki value 0 hai kyunki woh starting node hai par agar negative cycle exist kri toh inki value < 0 ho jayegi
    {
        return true;
    }
}
*/

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code here
        // question mein unreachable node ki value -1 given thi toh simplicity ke liye humne unreachable
        // node ki value 1e9 krdi
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int k = 0; k < matrix.size(); k++) // via
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        // phir se unreachable node ko -1 mein change krdi jo humne pehle change krdi thi
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};