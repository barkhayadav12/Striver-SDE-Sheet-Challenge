class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        vector<int> v;
        int i = 0;
        int j = 0;
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                v.push_back(arr1[i]);
                i++;
            }
            else
            {
                v.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n)
        {
            v.push_back(arr1[i]);
            i++;
        }
        while (j < m)
        {
            v.push_back(arr2[j]);
            j++;
        }
        return v[k - 1];
    }
};
