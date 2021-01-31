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

bool isPrime(lli n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (lli i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

bool primes[31001];
void calPrimes(lli n)
{
    memset(primes, true, sizeof(primes));
    primes[0] = false;
    primes[1] = false;
    for (lli j = 2; j * j <= n; j++)
    {
        if (primes[j] == true)
        {
            for (lli i = j * j; i <= n; i += j)
                primes[i] = false;
        }
    }
}
// code start from here...

int main()
{
    lli t, n, m, k, i, j, sol, sum, maxm;
    string str;
    cin >> t;

    while (t--)
    {
        lli n;
        cin >> n;
        cin >> str;
        lli e1[n], one = 0, zero = 0;

        for (i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                if (str[i] == '0')
                {
                    zero++;
                    e1[i] = 0;
                }
                else
                {
                    one++;
                    e1[i] = 1;
                }
            }
            else
            {
                if (str[i] == '0')
                {
                    zero++;
                    e1[i] = e1[i + 1];
                }
                else
                {
                    one++;
                    e1[i] = 1 + e1[i + 1];
                }
            }
        }

        lli ans = min(one, zero);
        zero = 0;
        for (i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                zero++;
            }
            else
            {
                ans = min(ans, n - (zero + e1[i]));
            }
        }
        cout << ans << endl;
    }
}