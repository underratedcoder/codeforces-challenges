#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int

// Returns ceiling for a/b
lli my_ceil(lli a, lli b)
{
    return (a + b - 1) / b;
}

// Returns floor for a/b
lli my_floor(lli a, lli b)
{
    return a / b;
}

// #######################
// code start from here...
// #######################

int main()
{
    lli t, i, j;
    // cin >> t;
    // while (t--)
    // {
    lli n, k;
    cin >> n >> k;
    if (n + n - 1 < k)
    {
        cout << 0 << endl;
    }
    else
    {
        lli start = min(k - 1, n), ans;
        if (k % 2 == 1)
        {
            ans = start - k / 2;
        }
        else
        {
            ans = start - k / 2;
        }
        cout << ans << endl;
    }
    // }
}
