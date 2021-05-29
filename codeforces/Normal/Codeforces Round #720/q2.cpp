#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int
#define ulli unsigned long long int

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
bool isPalindrome(lli n)
{
    // Find the appropriate divisor
    // to extract the leading digit
    lli divisor = 1;
    while (n / divisor >= 10)
        divisor *= 10;

    while (n != 0)
    {
        lli leading = n / divisor;
        lli trailing = n % 10;

        // If first and last digit
        // not same return false
        if (leading != trailing)
            return false;

        // Removing the leading and trailing
        // digit from number
        n = (n % divisor) / 10;

        // Reducing divisor by a factor
        // of 2 as 2 digits are dropped
        divisor = divisor / 100;
    }
    return true;
}
int main()
{
    lli t, i, j;
    for (i = 1; i <= 1000000000; i++)
    {
        lli sq = i * i;
        if (isPalindrome(i) && isPalindrome(sq))
            cout << i << " : " << sq << endl;
    }
}