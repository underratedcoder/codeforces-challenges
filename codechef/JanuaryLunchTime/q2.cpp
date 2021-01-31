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
    cin >> t;

    while (t--)
    {
        lli n;
        vector<lli> v;

        cin >> n;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }

        lli o = 0, e = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }
        cout << min(o, e) << endl;

        // cout << "YES" << endl;
    }
}