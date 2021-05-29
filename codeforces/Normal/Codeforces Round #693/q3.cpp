#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
lli mod = 1000000007;
#define sfor(i, a, b) for (lli i = a; i < b; i++)
#define rfor(i, a, b) for (lli i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

// #######################
// code start from here...
// #######################

int main()
{
    lli t, i, j;
    cin >> t;

    while (t--)
    {
        lli n, sum = 0, c1 = 0, c2 = 0;

        cin >> n;
        vector<lli> v;

        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }

        lli maxm = v[n - 1];
        for (i = n - 2; i >= 0; i--)
        {
            if (i + v[i] < n)
            {
                v[i] += v[i + v[i]];
            }
            maxm = max(maxm, v[i]);
        }
        cout << maxm << endl;
    }
}