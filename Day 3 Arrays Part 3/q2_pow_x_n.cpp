#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

/*
Mathematics concept:

--Binary Exponentiation--

(base)^power

case 1: if power=even,

3^16 = (3^2)^8 =(9)^8
9^8 = (9^2)^4 =(81)^4
... so on

case 2: if power=odd, make it even

3^17 = 3 X (3^16)
*/

double calculatePow(double base, int power)
{
    double ans = 1.0;
    long long temp = power;
    // if power is negative,make it positive
    if (power < 0)
    {
        temp = (-1) * temp;
    }
    while (temp > 0)
    {
        if (temp % 2 == 0)
        {
            base = base * base;
            temp = temp / 2;
        }
        else
        {
            ans = ans * base;
            temp--;
        }
    }
    if (power < 0)
    {
        ans = (double)1.0 / (double)ans;
    }
    return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    cout << calculatePow(x, n) << endl;
}