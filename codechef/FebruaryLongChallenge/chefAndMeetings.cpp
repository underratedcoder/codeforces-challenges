#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int
lli MOD = 1000000007;
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

int main()
{
    lli t, n, k, i, j;
    cin >> t;

    while (t--)
    {
        string L, R, P;
        cin >> P;
        string P0, P1, P2;
        P0 = P.substr(0, 2);
        P1 = P.substr(0, 5);
        P1 = P.substr(6, 2);
        cin >> n;

        if (P0 == "12")
        {
            P1[0] = '0';
            P1[1] = '0';
        }

        string ans = "";
        for (i = 0; i < n; i++)
        {
            cin >> L >> R;
            string L0, L1, L2;
            string R0, R1, R2;
            L0 = L.substr(0, 2);
            L1 = L.substr(0, 5);
            L2 = L.substr(6, 2);
            if (L0 == "12")
            {
                L1[0] = '0';
                L1[1] = '0';
            }
            R0 = R.substr(0, 2);
            R1 = R.substr(0, 5);
            R2 = R.substr(6, 2);
            if (R0 == "12")
            {
                R1[0] = '0';
                R1[1] = '0';
            }
            if (
                (P2 == "AM" && L2 == "AM" && R2 == "AM") ||
                (P2 == "PM" && L2 == "PM" && R2 == "PM"))
            {
                if (P2 >= L2 && P2 <= R2)
                {
                    ans += "1";
                }
                else
                {
                    ans += "0";
                }
            }
            else if (L2 == "AM")
            {
                if (P2 <= R2)
                {
                    ans += "1";
                }
                else
                {
                    ans += "0";
                }
            }
            else if (L2 == "AM" && P2 == "AM")
            {
                if (L2 <= P2)
                {
                    ans += "1";
                }
                else
                {
                    ans += "0";
                }
            }
            else
            {
                ans += "0";
            }
        }

        cout << ans << endl;
    }
}