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
    lli t, i, j, k, n, minm, maxm, ans, cnt;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<lli> v(n);
        unordered_set<int> st;
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
            st.insert(v[i]);
        }
        if (n > 300)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(v.begin(), v.end());
        while (v.size() <= 300)
        {
            vector<lli> newV;
            for (i = 0; i < v.size(); i++)
            {
                for (j = i + 1; j < v.size(); j++)
                {
                    int diff = v[j] - v[i];
                    if (st.find(diff) == st.end())
                    {
                        st.insert(diff);
                        newV.push_back(diff);
                    }
                }
            }
            if (newV.size() == 0)
                break;
            for (i = 0; i < newV.size(); i++)
            {
                v.push_back(newV[i]);
            }
            sort(v.begin(), v.end());
        }
        if (v.size() > 300)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << v.size() << endl;
            for (i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}
