#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>
using namespace std;

// print all the subsequences of the string

void fn(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    fn(ip, op1);
    fn(ip, op2);
}

// ip=ABC
// op=A-B-C, A-BC , AB-C , ABC

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back('-');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
}

// Permutation with case change

void caseChange(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(toupper(ip[0]));
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    caseChange(ip, op1);
    caseChange(ip, op2);
}

// letter change permutation

void letterChange(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << endl;
        return;
    }
    if (isalpha(ip[0]))
    {
        string op1 = op;
        string op2 = op;
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
        ip.erase(ip.begin() + 0);
        letterChange(ip, op1);
        letterChange(ip, op2);
    }
    else
    {
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin() + 0);
        letterChange(ip, op1);
    }
}

// palindrome partitioning

bool isPalindrome(string s, int ind, int i)
{
    while (ind <= i)
    {
        if (s[ind] != s[i])
        {
            return false;
        }
        ind++;
        i--;
    }
}
void palindromePartitioning(string ip, int ind, vector<string> &v)
{
    if (ind == ip.length())
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for (int i = ind; i < ip.length(); i++)
    {
        if (isPalindrome(ip, ind, i))
        {
            v.push_back(ip.substr(ind, i - ind + 1));
            palindromePartitioning(ip, i + 1, v);
            v.pop_back();
        }
    }
}

// generate parenthesis

void generateParenthesis(int open, int close, string op)
{
    if (open == 0 && close == 0)
    {
        cout << op << endl;
        return;
    }
    if (open != 0)
    {
        string op1 = op;
        op1.push_back('(');
        generateParenthesis(open - 1, close, op1);
    }
    if (close > open)
    {
        string op1 = op;
        op1.push_back(')');
        generateParenthesis(open, close - 1, op1);
    }
}

int main()
{
    // string ip;
    // cin >> ip;
    // string op = "";
    // op.push_back(ip[0]);
    // ip.erase(ip.begin() + 0);
    // solve(ip, op);
    // string op="";
    // letterChange(ip,op);
    // vector<string>v;
    // palindromePartitioning(ip,0,v);
    int n;
    cin >> n;
    int open = n;
    int close = n;
    string op = "";
    generateParenthesis(open, close, op);
}