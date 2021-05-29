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

//THIS IS THE CODE TO FIND ALL PRIME NUMBERS IN THE RANGE "L" to "R";
vector<lli> segmentedSieve(lli L, lli R)
{
    // generate all primes up to sqrt(R)
    lli lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<lli> primes;
    for (lli i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (lli j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (lli i : primes)
        for (lli j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    vector<long long> realprime;
    for (lli i = 0; i <= R - L; i++)
    {
        if (isPrime[i])
        {
            realprime.emplace_back(i + L);
        }
    }
    return realprime;
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

class TriPair
{
public:
    int h;
    int w;
    int i;
};

bool compareInterval(TriPair p1, TriPair p2)
{
    if ((p1.h < p2.h) || ((p1.h == p2.h) && (p1.w < p2.w)))
        return true;
    return false;
}

main()
{
    lli t, i, j;
    cin >> t;

    while (t--)
    {
        lli n, h, w;
        cin >> n;
        vector<TriPair> v;

        for (i = 0; i < n; i++)
        {
            TriPair tripair;
            cin >> h >> w;
            tripair.h = max(w, h);
            tripair.w = min(w, h);
            tripair.i = i;
            v.push_back(tripair);
        }
        sort(v.begin(), v.end(), compareInterval);

        unordered_map<lli, lli> ans;
        lli min_h, min_w;
        for (i = 0; i < n; i++)
        {
            if (i == 0)
            {
                min_h = v[i].h;
                min_w = v[i].w;
                ans[v[i].i] = -2;
            }
            else
            {
                for (j = 0; j < i; j++)
                {
                    if (v[j].h < v[i].h && v[j].w < v[i].w)
                    {
                        ans[v[i].i] = v[j].i;
                        break;
                    }
                }
                if (j == i)
                {
                    ans[v[i].i] = -2;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
}
