class MedianFinder
{
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    void addNum(int num)
    {
        if (maxh.size() == 0 || num < maxh.top())
        {
            maxh.push(num);
        }
        else
        {
            minh.push(num);
        }
        if (maxh.size() > minh.size() + 1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        if (minh.size() > maxh.size() + 1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian()
    {
        if (minh.size() == maxh.size())
        {
            return ((maxh.top() + minh.top())) / 2.0;
        }
        else
        {
            if (minh.size() > maxh.size())
            {
                return minh.top();
            }
            else
            {
                return maxh.top();
            }
        }
    }
};
