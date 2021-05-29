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
    // cin >> t;
    // while (t--)
    // {
    lli n, l, ans = LONG_MAX, final_ans = 1000000000000000L;
    cin >> n;
    vector<lli> v(n), unq;
    unordered_map<lli, lli> mp;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (i = 0; i < n; i++)
    {
        if (!mp[v[i]])
            unq.push_back(v[i]);
        mp[v[i]]++;
    }
    l = unq.size();
    cout << "L : " << l << endl;
    if (l == 1)
    {
        cout << 0 << endl;
    }
    else if (l == 2)
    {
        cout << abs(unq[0] - unq[1]) * min(mp[unq[0]], mp[unq[1]]) << endl;
    }
    else
    {
        for (i = 0; i < l - 1; i++)
        {
            j = i;
            k = i + 1;
            ans = abs(unq[j] - unq[k]) * min(mp[unq[j]], mp[unq[k]]);
            while (j >= 1 && k <= l - 2)
            {
                if (abs(unq[j] - unq[k + 1]) * mp[unq[k + 1]] <= abs(unq[j - 1] - unq[k]) * mp[unq[j - 1]])
                {
                    ans += abs(unq[j] - unq[k + 1]) * mp[unq[k + 1]];
                    k++;
                }
                else
                {
                    ans += abs(unq[j - 1] - unq[k]) * mp[unq[j - 1]];
                    j--;
                }
            }
            if (k == l - 1 && j >= 1)
            {
                while (j >= 1)
                {
                    ans += abs(unq[j - 1] - unq[k]) * mp[unq[j - 1]];
                    j--;
                }
            }
            if (j == 0 && k <= l - 2)
            {
                while (k <= l - 2)
                {
                    ans += abs(unq[j] - unq[k + 1]) * mp[unq[k + 1]];
                    k++;
                }
            }
            cout << ans << endl;
            final_ans = min(ans, final_ans);
        }
        cout << final_ans << endl;
    }
    // }
}
