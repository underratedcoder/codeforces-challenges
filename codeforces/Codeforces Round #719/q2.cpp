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
        lli n, c = 0, tp, tc, sd, rem = 1, ans = 0;
        cin >> n;
        tp = n;
        while (tp > 0)
        {
            tp /= 10;
            c++;
        }
        if (c == 1)
        {
            cout << n << endl;
            continue;
        }
        tp = n, tc = c;
        ans += (c - 1) * 9;
        while (tc > 1)
        {
            rem *= 10;
            tc--;
        }
        tp = rem;
        sd = 1;
        while (n >= tp + rem)
        {
            ans++;
            tp += rem;
            sd++;
        }
        if (n != tp)
        {
            lli left = n - tp;
            // cout << "left: " << left << endl;
            tc = c - 1;
            lli newNo = 0;
            while (tc > 0)
            {
                newNo = newNo * 10 + sd;
                tc--;
            }
            // cout << "new: " << newNo << endl;
            if (left >= newNo)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
