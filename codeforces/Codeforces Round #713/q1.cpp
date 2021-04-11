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
        lli n;
        cin >> n;
        vector<lli> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        lli fir = v[0], sec = v[1], th = v[2];
        if (v[0] == v[1] && v[0] != v[2])
        {
            cout << 3 << endl;
            continue;
        }
        if (v[0] != v[1] && v[0] == v[2])
        {
            cout << 2 << endl;
            continue;
        }
        if (v[1] == v[2] && v[0] != v[1])
        {
            cout << 1 << endl;
            continue;
        }
        for (i = 3; i < n; i++)
        {
            if (v[i] != v[0])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}
