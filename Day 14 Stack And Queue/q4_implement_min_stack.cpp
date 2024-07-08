class MinStack
{
public:
    MinStack()
    {
    }
    stack<pair<int, int>> stk;

    void push(int val)
    {
        int minVal;
        if (stk.empty())
        {
            minVal = val;
        }
        else
        {
            minVal = min(stk.top().second, val);
        }
        stk.push({val, minVal});
    }

    void pop()
    {
        stk.pop();
    }

    int top()
    {
        return stk.top().first;
    }

    int getMin()
    {
        return stk.top().second;
    }
};