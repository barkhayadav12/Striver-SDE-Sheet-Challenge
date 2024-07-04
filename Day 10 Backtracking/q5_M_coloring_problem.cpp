//checking if its adjacent node have the same color
bool isPossible(int node, bool graph[101][101], vector<int> &color, int col, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != node && graph[i][node] == 1 && color[i] == col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, int n, int m, bool graph[101][101], vector<int> &color)
{
    if (node == n)
    {
        return true;
    }
    for (int col = 1; col <= m; col++)
    {
        if (isPossible(node, graph, color, col, n))
        {
            color[node] = col;
            if (solve(node + 1, n, m, graph, color) == true)
            {
                return true;
            }
            else
            {
                color[node] = 0;
            }
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> color(n, 0);
    if (solve(0, n, m, graph, color))
        return true;
    return false;
}