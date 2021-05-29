#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
lli mod = 1000000007;

lli power(lli a, lli b)
{
    lli ans = 1;

    a = a % mod;

    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b /= 2;
        a = (a * a) % mod;
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
lli arr[2250][2250];
int main()
{
    lli t, i, j;
    cin >> t;
    while (t--)
    {
        lli n, m, ans = 0, newM, div, minm, col;
        cin >> n >> m;
        vector<lli> dig(10);
        while (n)
        {
            dig[n % 10]++;
            n /= 10;
        }
        for (i = 0; i <= 9; i++)
        {
            if (dig[i] > 0)
            {
                newM = m - (10 - i);
                if (newM < 0)
                {
                    ans = (ans % mod + dig[i] % mod) % mod;
                }
                else if (newM < 9)
                {
                    ans = (ans % mod + ((dig[i] % mod) * 2 % mod)) % mod;
                }
                else
                {
                    // cout << newM << endl;
                    div = newM / 9;
                    minm = div * 9;
                    col = newM - minm;
                    // if (div - 1 >= 0)
                    //     ans = (ans % mod + ((dig[i] % mod) * (power(2, div) % mod)) % mod) % mod;
                    // cout << div << " " << col << endl;
                    col = min(col, div);
                    if (col >= 0)
                    {
                        int prev = 1;
                        ans = (ans + dig[i] * 2) % mod;
                        // cout << ans << endl;

                        for (int j = 1; j <= col; j++)
                        {
                            // nCr = (nCr-1 * (n - r + 1))/r
                            int curr = (prev * (div - j + 1)) / j;
                            // cout << "curr " << curr << endl;
                            ans = (ans % mod + (dig[i] % mod * curr * 2 % mod) % mod) % mod;
                            prev = curr % mod;
                            // cout << ans << endl;
                        }
                        for (int j = col + 1; j <= div; j++)
                        {
                            // nCr = (nCr-1 * (n - r + 1))/r
                            int curr = (prev * (div - j + 1)) / j;
                            ans = (ans % mod + (dig[i] % mod * curr % mod) % mod) % mod;
                            prev = curr % mod;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
