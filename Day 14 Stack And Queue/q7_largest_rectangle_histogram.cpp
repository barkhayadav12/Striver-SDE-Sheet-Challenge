class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<pair<int, int>> nsl;
        int pseudoIndex = -1;
        vector<int> left;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            if (nsl.empty())
            {
                left.push_back(pseudoIndex);
            }
            else if (nsl.size() > 0 && nsl.top().first < heights[i])
            {
                left.push_back(nsl.top().second);
            }
            else if (nsl.size() > 0 && nsl.top().first >= heights[i])
            {
                while (nsl.size() > 0 && nsl.top().first >= heights[i])
                {
                    nsl.pop();
                }
                if (nsl.size() == 0)
                {
                    left.push_back(pseudoIndex);
                }
                else
                {
                    left.push_back(nsl.top().second);
                }
            }
            nsl.push({heights[i], i});
        }
        stack<pair<int, int>> nsr;
        pseudoIndex = n;
        vector<int> right;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nsr.empty())
            {
                right.push_back(pseudoIndex);
            }
            else if (nsr.size() > 0 && nsr.top().first < heights[i])
            {
                right.push_back(nsr.top().second);
            }
            else if (nsr.size() > 0 && nsr.top().first >= heights[i])
            {
                while (nsr.size() > 0 && nsr.top().first >= heights[i])
                {
                    nsr.pop();
                }
                if (nsr.size() == 0)
                {
                    right.push_back(pseudoIndex);
                }
                else
                {
                    right.push_back(nsr.top().second);
                }
            }
            nsr.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        int width[n];
        for (int i = 0; i < n; i++)
        {
            width[i] = (right[i] - left[i] - 1);
        }
        int area = 0;
        for (int i = 0; i < n; i++)
        {
            area = max(area, width[i] * heights[i]);
        }
        return area;
    }
};