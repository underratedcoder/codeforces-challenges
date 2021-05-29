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
        lli n, ok = 1, T = 0, M = 0;
        string str;
        cin >> n;
        cin >> str;
        if (str[0] == 'M' || str[n - 1] == 'M')
        {
            cout << "NO" << endl;
            continue;
        }
        vector<lli> tc(n), mc(n);
        tc[0] = 1;
        T++;
        for (i = 1; i < n; i++)
        {
            if (str[i] == 'T')
            {
                tc[i] = 1 + tc[i - 1];
                mc[i] = mc[i - 1];
                T++;
            }
            else
            {
                tc[i] = tc[i - 1];
                mc[i] = 1 + mc[i - 1];
                M++;
            }
        }
        if (2 * M != T)
        {
            cout << "NO" << endl;
            continue;
        }
        for (i = 1; i < n - 1; i++)
        {
            if (str[i] == 'M')
            {
                if (mc[i] > tc[i])
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        for (i = n - 2; i > 0; i--)
        {
            if (str[i] == 'M')
            {
                if (M - mc[i] + 1 > T - tc[i])
                {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
