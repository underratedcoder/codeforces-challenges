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
        lli n, x;
        cin >> n;
        vector<lli> e, o;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            if (x % 2 == 0)
                e.push_back(x);
            else
                o.push_back(x);
        }
        for (i = 0; i < o.size(); i++)
        {
            cout << o[i] << " ";
        }
        for (i = 0; i < e.size(); i++)
        {
            cout << e[i] << " ";
        }
        cout << endl;
    }
}
