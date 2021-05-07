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
        lli n, ans = 0, pos, mid, mid_ind, c = 0, evn = 0;
        string str;
        cin >> n;
        cin >> str;
        for (i = 0; i < n; i++)
        {
            if (str[i] == '*')
            {
                c++;
            }
        }
        if (c <= 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (c % 2 == 0)
            evn = 1;
        // cout << c << endl;
        mid = (c + 1) / 2;
        c = 0;
        for (i = 0; i < n; i++)
        {
            if (str[i] == '*')
            {
                c++;
                if (c == mid)
                    mid_ind = i;
            }
        }
        // cout << c << endl;
        c = 0;
        for (i = 0; i < mid_ind; i++)
        {
            if (str[i] == '*')
            {
                c++;
                pos = mid_ind - (mid - c);
                ans += pos - i;
            }
        }
        // cout << c << endl;
        c = 0;
        if (evn)
            c--;
        for (i = n - 1; i > mid_ind; i--)
        {
            if (str[i] == '*')
            {
                c++;
                pos = mid_ind + (mid - c);
                ans += i - pos;
            }
        }
        cout << ans << endl;
    }
}
