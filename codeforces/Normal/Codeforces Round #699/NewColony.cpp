#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, k, c, i, j;
    string str;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        vector<lli> v;

        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }
        c = 0;
        for (j = 1; j <= k; j++)
        {
            for (i = 0; i < n - 1; i++)
            {
                if (v[i] < v[i + 1])
                {
                    v[i]++;
                    c++;
                    break;
                }
            }
            if (i == n - 1)
                break;
        }
        if (c == k)
        {
            cout << i + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}