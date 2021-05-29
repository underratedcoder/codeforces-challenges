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
    lli t, i, j, mod = 998244353;
    vector<lli> v(101);
    v[1] = 1;
    v[2] = 3;
    v[3] = 6;

    for (i = 4; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            lli a = v[i - 2];
            lli b = v[i - 2] + 1;
            if (a % 2 == 0)
                a /= 2;
            else
                b /= 2;

            v[i] = (v[i - 1] % mod + v[i - 1] % mod + 1) % mod;
        }
        else
        {
            v[i] = (v[i - 1] % mod + v[i - 2] % mod) % mod;
        }
    }

    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        cout << v[n] << endl;
    }
}
