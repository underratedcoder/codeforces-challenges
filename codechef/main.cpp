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

// class TriPair
// {
// public:
//     int h;
//     int w;
//     int i;
// };

// bool compareInterval(TriPair p1, TriPair p2)
// {
//     if ((p1.h < p2.h) || ((p1.h == p2.h) && (p1.w < p2.w)))
//         return true;
//     return false;
// }

void fun(lli l, lli h, vector<lli> v, lli d, unordered_map<lli, lli> &mpp)
{
    if (h < l)
    {
        return;
    }
    if (l == h)
        mpp[l] = d;
    lli maxm = INT_MIN;
    lli maxm_i = -1;
    for (lli i = l; i <= h; i++)
    {
        if (v[i] > maxm)
        {
            maxm = v[i];
            maxm_i = i;
        }
    }
    mpp[maxm_i] = d;
    fun(l, maxm_i - 1, v, d + 1, mpp);
    fun(maxm_i + 1, h, v, d + 1, mpp);
}

main()
{
    lli t, i, j;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        vector<pair<lli, lli>> v;
        vector<lli> arr;
        map<lli, lli> mpp, mpp2;
        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            arr.push_back(x);
            mpp[x]++;
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }

        for (i = 0; i < n; i++)
        {
            if (mpp[arr[i]])
            {
                mpp2[mpp[arr[i]]]++;
                if (mpp2[mpp[arr[i]]] == 1)
                {
                    v.push_back(make_pair(mpp[arr[i]], 0));
                }
                mpp.erase(arr[i]);
            }
        }
        lli m = v.size();
        if (m == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (i = 0; i < v.size(); i++)
        {
            v[i].second = mpp2[v[i].first];
        }

        // for (i = 0; i < v.size(); i++)
        // {
        //     cout << v[i].first << " " << v[i].second << endl;
        // }

        sort(v.begin(), v.end());

        vector<lli> pref(m), suff(m), suff2(m);
        pref[0] = v[0].first * v[0].second;
        suff[m - 1] = v[m - 1].first * v[m - 1].second;
        suff2[m - 1] = v[m - 1].second;
        for (i = 1; i < m; i++)
        {
            pref[i] = v[i].first * v[i].second + pref[i - 1];
        }

        for (i = m - 2; i >= 0; i--)
        {
            suff[i] = v[i].first * v[i].second + suff[i + 1];
            suff2[i] = v[i].second + suff2[i + 1];
        }

        // for (i = 0; i < m; i++)
        // {
        //     cout << pref[i] << " " << suff[i] << " " << suff2[i] << endl;
        // }

        lli minm = n;
        minm = min(suff[1], pref[m - 2]);

        for (i = 0; i < m; i++)
        {
            if (i == 0)
            {
                minm = min(minm, suff[i + 1] - v[i].first * suff2[i + 1]);
            }
            else if (i == m - 1)
            {
                minm = min(minm, pref[i - 1]);
            }
            else
                minm = min(minm, pref[i - 1] + (suff[i + 1] - v[i].first * suff2[i + 1]));
        }

        cout << minm << endl;
    }
}
