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
    lli n, ans = 0, pf, ps;
    cin >> n;
    map<lli, lli> mp;
    vector<lli> v(n);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    j = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        if (j == 0)
        {
            pf = i->first;
            ps = i->second;
        }
        else
        {

            ans += min(ps, i->second);
            ps -= min(ps, i->second);
            pf = i->first;
            ps += i->second;
        }
        // cout << pf << " " << ps << endl;
        j++;
    }
    cout << ans << endl;
    // }
}
