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
        lli ang, start, maxm, ok = 0;
        cin >> ang;
        for (i = 3; i <= 360; i++)
        {
            lli num = i * ang;
            lli den = i * (i - 2);

            if ((i * ang) % 180 == 0)
            {
                if (ang <= (i - 2) * 180 / i)
                {
                    ok = 1;
                    cout << i << endl;
                    break;
                }
            }
        }
        if (ok == 0)
        {
            cout << -1 << endl;
        }
    }
}
