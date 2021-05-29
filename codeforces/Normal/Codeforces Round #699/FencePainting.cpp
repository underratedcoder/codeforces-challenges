#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

// code start from here...

int main()
{
    lli t, n, m, i, j;
    string str;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        vector<lli> a, b, c;
        vector<vector<lli>> bb(n + 1);
        unordered_map<lli, lli> umb, umc;
        lli ind = -1;

        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            a.push_back(x);
        }
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            b.push_back(x);
        }

        for (i = 0; i < m; i++)
        {
            lli x;
            cin >> x;
            c.push_back(x);
            umc[x]++;
        }

        for (i = 0; i < n; i++)
        {
            // cout << "b[i] : " << b[i] << endl;
            if (a[i] != b[i])
            {
                bb[b[i]].push_back(i + 1);
                umb[b[i]]++;
            }
            if (ind == -1 && (b[i] == c[m - 1]))
            {
                ind = i + 1;
            }
        }
        // cout << "ind : " << ind << endl;

        if (ind == -1)
        {
            cout << "NO" << endl;
            continue;
        }
        lli ok = 1;
        for (i = 0; i < n; i++)
        {
            if (a[i] != b[i] && umc[b[i]] < umb[b[i]])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 0)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        if (!bb[c[m - 1]].empty())
            ind = bb[c[m - 1]][0];
        for (i = 0; i < m; i++)
        {
            if (umb[c[i]])
            {
                // cout << c[i] << " is IN the ummp" << endl;
                cout << bb[c[i]].back() << " ";
                bb[c[i]].pop_back();
                umb[c[i]]--;
            }
            else
            {
                // cout << c[i] << " is NOT IN the ummp" << endl;
                cout << ind << " ";
            }
        }
        cout << endl;
    }
}