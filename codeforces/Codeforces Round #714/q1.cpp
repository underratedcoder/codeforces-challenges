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
        lli n, k, maxm;
        cin >> n >> k;
        maxm = (n - 1) / 2;
        if (k > maxm)
        {
            cout << -1 << endl;
            continue;
        }
        vector<lli> v(n);
        for (i = 1; i <= n; i++)
        {
            v[i - 1] = i;
        }
        for (i = n - 2; i >= 0; i = i - 2)
        {
            if (k > 0)
            {
                swap(v[i], v[i + 1]);
                k--;
            }
            else
                break;
        }
        for (i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
