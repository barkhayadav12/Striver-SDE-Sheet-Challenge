/*
Assume n=4, k=17

arr[]={1,2,3,4}

arr
[ 1 (0-5th) 2 (6-11th)  3 (12-17th) 4(18-23th)]
1 2 3 4     2 1 3 4     3 1 2 4    4 1 2 3
1 2 4 3     2 1 4 3     3 1 4 2    4 1 3 2
1 3 2 4     2 3 1 4     3 2 1 4    4 2 1 3
1 3 4 2     2 3 4 1     3 2 4 1    4 2 3 1
1 4 2 3     2 4 1 3     3 4 1 2    4 3 1 2
1 4 3 2     2 4 3 1     3 4 2 1    4 3 2 1

so, yaha pe jo 16th ( kyunki 0 based indexing hai) permutation hai
woh 3 4 1 2 hai, wahi humara answer hai

Naive approach:

Hum saare permutations ko nikal skte hai phir loop krke 16th wale permutation ko
find kr skte hai.

Optimal approach: (thoda math)

humein pta hai ki har number ki 6 permutation banegi, so k yaha
pe 16 hai so woh block kaise milegi?

k/blocksize krne se milegi i.e 16/6=2, 2nd block mein milegi, and humari
answer k%blocksize wali sequence hogi i.e 16%6=4, 4th sequence i.e 3 4 1 2 humari
ans hai, par humein beforehand permutation find nhi kr rakhi hai isiliye
humein agar pta hai ki 4th sequence of the 2nd block humari answer hai tab
bhi we wouldn't be able to return that, but as of now we now know ki first number kaunsi hogi

first number: arr[k/blocksize] i.e arr[2]=3 hogi, abhi hum array
se 3 ko remove krdenge

abhi k=16%6=4 hai
     blocksize=6/3 = 2 hai

The new array: arr[]={1,2,4}

1          2       4
1 2 4     2 1 4    4 1 2
1 4 2     2 4 1    4 2 1

second number: arr[k/blocksize] i.e arr[2]=4 hogi, abhi hum array
se 4 ko remove krdenge

abhi k=k%blocksize= 4%2 =0 hai
     blocksize=blocksize/arr.size() = 2/2= 1hai

The new array: arr[]={1,2}

1        2
1 2     2 1

third number: arr[k/blocksize] i.e arr[0]=1 hogi, abhi hum array
se 1 ko remove krdenge

abhi k=k%blocksize= 0%1 = 1 hai
     blocksize=blocksize/arr.size() = 1/1= 1 hai

he new array: arr[]={2}

[2]

after deleting 2, array size becomes 0 so we break out of the
while loop

The final answer is 3 4 1 2
*/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> arr;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            arr.push_back(i);
        }
        arr.push_back(n);
        k--;
        string ans = "";
        while (true)
        {
            ans += to_string(arr[k / fact]);
            arr.erase(arr.begin() + k / fact);
            if (arr.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / arr.size();
        }
        return ans;
    }
};