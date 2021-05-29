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
        lli a, b, x, y, z;
        cin >> a >> b;
        if ((a <= 2 && b <= 2) ||)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << a << " " << a * b - a << " " << a * b << " " << endl;
    }
}