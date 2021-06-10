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
    lli t, i, j, k, n, minm, maxm, ans, cnt, sum;
    cin >> t;
    while (t--)
    {
        sum = 0, cnt = 0;
        cin >> n;
        vector<lli> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        if (sum % n != 0)
        {
            cout << -1 << endl;
            continue;
        }
        lli avg = sum / n;

        for (i = 0; i < n; i++)
        {
            if (v[i] > avg)
                cnt++;
        }
        cout << cnt << endl;
    }
}
