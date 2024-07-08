class StockSpanner
{
public:
    stack<pair<int, int>> stk;
    StockSpanner()
    {
    }

    int next(int price)
    {
        int ans = 1;
        while (!stk.empty() && stk.top().first <= price)
        {
            ans += stk.top().second;
            stk.pop();
        }
        stk.push({price, ans});
        return ans;
    }
};