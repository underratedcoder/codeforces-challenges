#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

lli my_ceil(lli a, lli b)
{
    return (a + b - 1) / b;
}

lli my_floor(lli a, lli b)
{
    return a / b;
}

// code start from here...

int main()
{
    lli t, a, b, n, i, j, x, y;
    cin >> t;

    while (t--)
    {
        vector<lli> atk;
        vector<lli> hlt;
        cin >> a >> b >> n;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            atk.push_back(x);
        }
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            hlt.push_back(x);
        }

        lli sum = 0, maxm = -1;
        for (i = 0; i < n; i++)
        {
            sum += my_ceil(hlt[i], a) * atk[i];
            maxm = max(maxm, atk[i]);
        }
        if (b + maxm > sum)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}