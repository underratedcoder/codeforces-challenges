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
    lli t, i, j, k;
    lli n, each, sum = 0, ans = 0;
    cin >> n;
    vector<lli> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    each = sum / n;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] < each)
        {
            ans += (each - a[i]);
            a[i + 1] -= (each - a[i]);
        }
        else if (a[i] > each)
        {
            ans += (a[i] - each);
            a[i + 1] += (a[i] - each);
        }
    }
    cout << ans << endl;
    // }
}
