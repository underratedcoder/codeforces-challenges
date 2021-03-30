#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
lli mod = 1000000007;

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
        lli n, p, ans = 0;
        cin >> p >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (p == 1)
        {
            cout << 2 << endl;
            continue;
        }
        if (p == 2)
        {
            cout << 1 + n << endl;
            continue;
        }

        ans = 2;
        lli dp[n - 1][p - 1];
        for (i = 0; i < p - 1; i++)
        {
            dp[0][i] = 1;
            ans++;
        }
        for (i = 1; i < n - 1; i++)
        {
            if (i % 2 == 1)
            {
                for (j = p - 2; j >= 0; j--)
                {
                    if (j == p - 2)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = (dp[i - 1][j] % mod + dp[i][j + 1] % mod) % mod;
                    ans = (ans % mod + dp[i][j] % mod) % mod;
                }
            }
            else
            {
                for (j = 0; j < p - 1; j++)
                {
                    if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
                    ans = (ans % mod + dp[i][j] % mod) % mod;
                }
            }
        }
        cout << ans << endl;
    }
}
