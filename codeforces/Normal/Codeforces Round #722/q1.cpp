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
        lli n, c = 0, minm = INT_MAX;
        cin >> n;
        vector<lli> v(n);
        map<lli, vector<lli>> mp;
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            minm = min(minm, v[i]);
        }
        for (i = 0; i < n; i++)
        {
            if (v[i] == minm)
                c++;
        }
        cout << n - c << endl;
    }
}
