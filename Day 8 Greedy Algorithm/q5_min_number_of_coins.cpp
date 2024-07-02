class Solution
{
public:
    vector<int> minPartition(int N)
    {
        int arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int i = 0;
        vector<int> ans;
        while (N != 0)
        {
            if (arr[i] > N)
            {
                i++;
            }
            else
            {
                N -= arr[i];
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};