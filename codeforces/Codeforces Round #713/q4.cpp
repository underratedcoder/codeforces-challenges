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
        lli n, sum = 0;
        cin >> n;
        vector<lli> v(n + 2);
        for (i = 0; i < n + 2; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (i = 0; i < n; i++)
        {
            sum += v[i];
        }
        if (sum == v[n] || sum == v[n + 1])
        {
            for (i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        else
        {
            lli ok = -1;
            sum += v[n];
            for (i = 0; i < n; i++)
            {
                if (sum - v[i] == v[n + 1])
                {
                    ok = i;
                    break;
                }
            }
            if (ok == -1)
            {
                cout << -1 << endl;
            }
            else
            {
                for (i = 0; i < n + 1; i++)
                {
                    if (i != ok)
                        cout << v[i] << " ";
                }
                cout << endl;
            }
        }
    }
}
