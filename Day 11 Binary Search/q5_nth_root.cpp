int NthRoot(int n, int m)
{
    // Write your code here.
    int lo = 1;
    int hi = m;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        if (pow(mid, n) > m)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return -1;
}