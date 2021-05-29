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
    lli t, i, j, n;
    cin >> n;
    vector<lli> v(n), vis(n + 1), missing;
    unordered_map<lli, lli> mp;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (i = 1; i <= n; i++)
    {
        if (!mp[i])
            missing.push_back(i);
    }
    j = 0;
    cout << missing.size() << endl;
    for (i = 0; i < n; i++)
    {
        if (mp[v[i]] > 1)
        {
            if (j < missing.size())
            {
                if (v[i] < missing[j] && !vis[v[i]])
                {
                    cout << v[i] << " ";
                    vis[v[i]] = 1;
                }
                else
                {
                    cout << missing[j] << " ";
                    j++;
                    mp[v[i]]--;
                }
            }
        }
        else if (mp[v[i]] == 1 && vis[v[i]] == 0)
        {
            cout << v[i] << " ";
            vis[v[i]] = 1;
        }
    }
    cout << endl;
}
