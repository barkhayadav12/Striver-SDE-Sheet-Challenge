class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            stk.push(i);
        }
        while (stk.size() > 1)
        {
            int first = stk.top();
            stk.pop();
            int second = stk.top();
            stk.pop();
            // kya first second ko jaanti hai? if yes, first celebrity nhi ho skta kyunki celebrity kisiko nhi jaanta
            if (M[first][second] == 1)
            {
                stk.push(second);
            }
            else
            { // if no, second celebrity nhi ko skta kyunki celebrity ko sab jaante hai
                stk.push(first);
            }
        }
        // after the elimination process, sirf 1 number reh jayegi, after that now we are sure ki
        // baaki ke jo numbers the woh toh celebrity nhi hai, abhi toh ek bacha hai woh celebrity ho skta hai
        // but we can't say for sure, so now we need to check its corresponding rows and cols
        int celeb = stk.top();
        stk.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == celeb)
            {
                continue;
            }
            // checking row and col, row saare 1 honi chahiye, column mein honi chahiye, kyunki celebrity
            // knows no one but everyone knows the celebrity
            if (M[i][celeb] != 1 || M[celeb][i] != 0)
            {
                return -1;
            }
        }
        return celeb;
    }
};