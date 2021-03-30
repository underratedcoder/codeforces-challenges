#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int

lli power(lli a, lli b)
{
    lli ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a);
        b /= 2;
        a = (a * a);
    }
    return ans;
}

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
    lli t, i, j, prev;
    unordered_map<lli, lli> mp, rmp;
    mp[0] = 1;
    rmp[1] = 0;
    for (i = 1; i < 20; i++)
    {
        mp[i] = 2 * mp[i - 1];
        rmp[2 * mp[i - 1]] = i;
    }
    cin >> t;
    while (t--)
    {
        lli n, w, till = 0, h = 0;
        cin >> n >> w;
        vector<lli> cnt(20);
        vector<lli> v(n), dec;
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            cnt[rmp[v[i]]]++;
        }
        for (i = 19; i >= 0; i--)
        {
            if (cnt[i] != 0)
                dec.push_back(i);
        }

        // for (i = 0; i <= 19; i++)
        // {
        //     cout << i << " " << cnt[i] << endl;
        // }

        // for (i = 0; i <= dec.size(); i++)
        // {
        //     cout << mp[dec[i]] << " " << cnt[dec[i]] << endl;
        // }

        // j = 1;
        // cout << "out" << endl;
        while (true)
        {
            // cout << " j " << j << endl;
            lli tw = w;
            for (i = 0; i < dec.size() && tw > 0; i++)
            {
                if (cnt[dec[i]] > 0)
                {
                    lli no = tw / mp[dec[i]];
                    tw -= min(no, cnt[dec[i]]) * mp[dec[i]];
                    till += min(no, cnt[dec[i]]);
                    cnt[dec[i]] -= min(no, cnt[dec[i]]);
                }
            }
            // cout << h << " " << till << endl;
            h++;
            if (till == n)
                break;
        }
        cout << h << endl;
    }
}
