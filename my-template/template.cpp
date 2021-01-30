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
    lli t, n, k, i, j;
    cin >> t;

    while (t--)
    {
        lli n;
        vector<lli> v;

        cin >> n >> k;

        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }

        cout << "YES" << endl;
    }
}