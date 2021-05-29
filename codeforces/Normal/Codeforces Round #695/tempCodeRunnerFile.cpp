#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
#define sfor(i, a, b) for (lli i = a; i < b; i++)
#define rfor(i, a, b) for (lli i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
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

// Check if a number is prime
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

// Calculate prime upto N
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

// Calculate GCD of a and b
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Calculate LCM of a and b
lli lcm(lli a, lli b)
{
    return (a / gcd(a, b)) * b;
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
        lli n, cnt = 0;
        cin >> n;
        vector<lli> v(n), hv(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (n <= 5)
        {
            cout << 0 << endl;
            continue;
        }

        for (i = 0; i < n; i++)
        {
            if (i == 0 || i == n - 1)
                hv[i] = -1;
            else
            {
                if (v[i] > v[i - 1] && v[i] > v[i + 1])
                {
                    hv[i] = 1;
                    cnt++;
                }
                else if (v[i] < v[i - 1] && v[i] < v[i + 1])
                {
                    hv[i] = 0;
                    cnt++;
                }
                else
                    hv[i] = -1;
            }
        }
        // for (i = 0; i < n; i++)
        // {
        //     cout << hv[i] << " ";
        // }
        // cout << endl;
        lli _hvh = 0, _hv = 0;
        for (i = 1; i < n - 1; i++)
        {
            if ((hv[i] == 0 && hv[i - 1] == 1 && hv[i + 1] == 1) || (hv[i] == 1 && hv[i - 1] == 0 && hv[i + 1] == 0))
            {
                _hvh = 1;
                break;
            }
            else if ((hv[i] == 0 && hv[i - 1] == 1) || (hv[i] == 1 && hv[i - 1] == 0))
            {
                if (hv[i] == 0)
                {
                    if ((v[i - 2] > v[i] && v[i - 2] > v[i - 3]) && (v[i + 1] < v[i - 1] && v[i + 1] < v[i + 2]))
                        continue;
                    _hv = 1;
                }
                else
                {
                    if ((v[i - 2] < v[i] && v[i - 2] < v[i - 3]) && (v[i + 1] > v[i - 1] && v[i + 1] > v[i + 2]))
                        continue;
                    _hv = 1;
                }
            }
        }

        // cout << "cnt : " << cnt << endl;
        if (_hvh == 1)
        {
            cout << cnt - 3 << endl;
        }
        else if (_hv == 1)
        {
            cout << cnt - 2 << endl;
        }
        else
        {
            cout << max(cnt - 1, (lli)0) << endl;
        }
    }
}
