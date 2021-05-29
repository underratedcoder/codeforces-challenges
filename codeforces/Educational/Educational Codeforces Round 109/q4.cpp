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
    lli i, j, n, ans = 0;
    cin >> n;
    vector<lli> arr(n), v(n), one(n), zero(n);
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        v[i] = arr[i];
    }
    if (n <= 3)
    {
        cout << 0 << endl;
    }
    else
    {
        if (arr[n - 1] == 0)
        {
            zero[n - 1] = 1;
            one[n - 1] = 0;
        }
        else
        {
            zero[n - 1] = 0;
            one[n - 1] = 1;
        }
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i] == 1)
            {
                one[i] = 1 + one[i + 1];
                zero[i] = zero[i + 1];
            }
            else
            {
                one[i] = one[i + 1];
                zero[i] = 1 + zero[i + 1];
            }
        }
        for (i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                j = 1;
                while (true)
                {
                    if (i - j >= 0 && v[i - j] == 0)
                    {
                        ans += j;
                        v[i - j] = 1;
                        break;
                    }
                    if (i + j < n && v[i + j] == 0)
                    {
                        if (zero[i + j] >= one[i])
                        {
                            ans += j;
                            v[i + j] = 1;
                            break;
                        }
                    }
                    j++;
                }
            }
        }
        cout << ans << endl;
    }
}