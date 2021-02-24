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
void fun(lli l, lli r, lli smax)
{
    lli mid = (l + r) / 2, lsmax, rsmax;
    if (l + 1 == r)
    {
        if (l == smax)
            cout << "! " << r << endl;
        if (smax == r)
            cout << "! " << l << endl;
        return;
    }
    if (l + 2 == r)
    {
        if (smax == l)
        {
            cout << "? " << l + 1 << " " << r << endl;
            cout.flush();
            cin >> lsmax;
            if (lsmax == l + 1)
                cout << "! " << r << endl;
            if (lsmax == r)
                cout << "! " << l + 1 << endl;
        }
        else if (smax == r)
        {
            cout << "? " << l << " " << r - 1 << endl;
            cout.flush();
            cin >> lsmax;
            if (lsmax == l)
                cout << "! " << r - 1 << endl;
            if (lsmax == r - 1)
                cout << "! " << l << endl;
        }
        else
        {
            cout << "? " << l << " " << r - 1 << endl;
            cout.flush();
            cin >> lsmax;
            if (lsmax == r - 1)
                cout << "! " << l << endl;
            if (lsmax == l)
                cout << "! " << r << endl;
        }
        return;
    }
    mid = (l + r) / 2;
    cout << "? " << l << " " << mid << endl;
    cout.flush();
    cin >> lsmax;
    cout << "? " << mid + 1 << " " << r << endl;
    cout.flush();
    cin >> rsmax;
    if (lsmax == smax)
    {
        fun(l, mid, smax);
    }
    else if (rsmax == smax)
    {
        fun(mid + 1, r, smax);
    }
    else if (smax > mid)
    {
        fun(l, mid, lsmax);
    }
    else
    {
        fun(mid + 1, r, rsmax);
    }
}
int main()
{
    lli n, smax;
    cin >> n;
    cout << "? 1 " << n << endl;
    cout.flush();
    cin >> smax;
    if (n == 1)
    {
        cout << "! 1" << endl;
    }
    else
    {
        fun(1, n, smax);
    }
}
