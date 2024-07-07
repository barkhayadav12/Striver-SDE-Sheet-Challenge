class MyQueue
{
public:
    stack<int> ip;
    stack<int> op;
    MyQueue()
    {
    }

    void push(int x)
    {
        ip.push(x);
    }

    int pop()
    {
        if (op.empty())
        {
            while (!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
        }
        int x = op.top();
        op.pop();
        return x;
    }

    int peek()
    {
        if (op.empty())
        {
            while (!ip.empty())
            {
                op.push(ip.top());
                ip.pop();
            }
            return op.top();
        }
        int x = op.top();
        return x;
    }

    bool empty()
    {
        if (!ip.empty() || !op.empty())
        {
            return false;
        }
        return true;
    }
};
