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
    lli t, i, j, n, r1, r2, x = -1;
    cin >> n >> r1 >> r2;
    vector<lli> aka(n), ans(n);
    for (i = 0; i < n; i++)
    {
        if (i + 1 == r1)
        {
            aka[i] = -1;
        }
        else
        {
            cin >> aka[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i + 1 == r1)
        {
            ans[i] = r2;
        }
        else if (i + 1 == r2)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = aka[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (ans[i] != -1)
            cout << ans[i] << " ";
    }
    cout << endl;
}
