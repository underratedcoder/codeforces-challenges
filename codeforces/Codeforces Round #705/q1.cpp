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
    cin >> t;
    while (t--)
    {
        lli n, k;
        cin >> n >> k;
        cout << n - my_ceil(k, 2) << endl;
        for (i = k + 1; i <= n; i++)
        {
            cout << i << " ";
        }
        for (i = k - 1; i >= my_ceil(k, 2); i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
