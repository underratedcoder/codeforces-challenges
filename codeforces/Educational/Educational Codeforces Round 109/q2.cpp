#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
#define sfor(i, a, b) for (lli i = a; i < b; i++)
#define rfor(i, a, b) for (lli i = a; i >= b; i--)
#define pb push_back
lli mod = 1000000007;

bool isPowerOfTwo(lli n)
{
    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

bool isPalindrome(string s)
{
    lli l = 0;
    lli h = s.size() - 1;
    while (h > l)
    {
        if (s[l++] != s[h--])
        {

            return false;
        }
    }
    return true;
}

//to find nth fibonacci number.
//This code returns Fn and Fn+1 as a pair.
pair<lli, lli> fib(lli n)
{
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    lli c = p.first * (2 * p.second - p.first);
    lli d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

lli fact(lli n)
{
    lli res = 1;
    for (lli i = n; i >= 1; i--)
        (res *= i) %= mod;
    return (res % mod);
}

lli power(lli a, lli b, lli mod)
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
    lli t, n, i, j;
    cin >> t;

    while (t--)
    {
        lli n, minm = INT_MAX, maxm = INT_MIN, sorted = 1, c = 0;
        cin >> n;
        vector<lli> v;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
            minm = min(minm, x);
            maxm = max(maxm, x);
            if (x != i + 1)
                sorted = 0;
        }
        if (sorted == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (v[0] == 1 || v[n - 1] == n)
        {
            cout << 1 << endl;
            continue;
        }
        if (v[0] == n && v[n - 1] == 1)
        {
            cout << 3 << endl;
            continue;
        }
        cout << 2 << endl;
    }
}