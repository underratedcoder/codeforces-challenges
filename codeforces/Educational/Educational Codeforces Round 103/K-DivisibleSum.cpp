#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

lli my_ceil(lli a, lli b)
{
    return (a + b - 1) / b;
}

lli my_floor(lli a, lli b)
{
    return a / b;
}

// code start from here...

int main()
{
    lli t, i, j;
    cin >> t;

    while (t--)
    {
        lli n, k;
        cin >> n >> k;

        if (n > k)
        {
            cout << my_ceil(my_ceil(n, k) * k, n) << endl;
        }
        else
        {
            cout << my_ceil(k, n) << endl;
        }
    }
}