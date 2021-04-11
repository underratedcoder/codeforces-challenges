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
        unordered_map<lli, lli> mp;
        lli n, l, r, s, sel, minm, maxm, sum;
        cin >> n >> l >> r >> s;
        sel = r - l + 1;
        minm = sel * (sel + 1) / 2;
        maxm = (n * (n + 1) / 2) - ((n - sel) * (n - sel + 1) / 2);
        if (s < minm || s > maxm)
        {
            cout << -1 << endl;
            continue;
        }
        vector<lli> ans(sel);
        for (i = 0; i < sel; i++)
        {
            ans[i] = i + 1;
        }
        lli selSum = minm, j = 0;
        for (i = sel - 1; i >= 0; i--, j++)
        {
            if (s - selSum >= (n - j) - (i + 1))
            {
                selSum += (n - j) - (i + 1);
                ans[i] = n - j;
            }
            else
            {
                ans[i] += s - selSum;
                selSum = s;
                break;
            }
        }
        for (i = 0; i < sel; i++)
        {
            // cout << ans[i] << " ";
            mp[ans[i]]++;
        }
        vector<lli> other;
        for (i = 1; i <= n; i++)
        {
            if (!mp[i])
                other.push_back(i);
        }
        j = 0;
        lli k = 0;
        for (i = 1; i <= n; i++)
        {
            if (i >= l && i <= r)
            {
                cout << ans[j++] << " ";
            }
            else
            {
                cout << other[k++] << " ";
            }
        }
        cout << endl;
    }
}
