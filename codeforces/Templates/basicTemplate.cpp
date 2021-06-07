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
        for (i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
        cout << "YES" << endl;
    }
}
