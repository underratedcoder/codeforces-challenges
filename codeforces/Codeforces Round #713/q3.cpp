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

int main()
{
    lli t, i, j;
    cin >> t;
    while (t--)
    {
        lli n, a, b, zero = 0, one = 0, ok = 1;
        string str;
        cin >> a >> b;
        cin >> str;
        n = str.length();
        for (i = 0; i < n; i++)
        {
            if (str[i] == '0')
                zero++;
            else if (str[i] == '1')
                one++;
        }
        if (zero > a || one > b)
        {
            cout << -1 << endl;
            continue;
        }
        for (i = 0; i < n / 2; i++)
        {
            if (str[i] != str[n - i - 1])
            {
                if (str[i] != '?' && str[n - i - 1] != '?')
                {
                    ok = 0;
                    break;
                }
                if (str[i] != '?')
                {
                    str[n - i - 1] = str[i];
                    if (str[i] == '0')
                    {
                        zero++;
                    }
                    else
                    {
                        one++;
                    }
                }
                else if (str[n - i - 1] != '?')
                {
                    str[i] = str[n - i - 1];
                    if (str[n - i - 1] == '0')
                    {
                        zero++;
                    }
                    else
                    {
                        one++;
                    }
                }
            }
            if (zero > a || one > b)
            {
                ok = 0;
                break;
            }
        }

        for (i = 0; i < n / 2; i++)
        {
            if (str[i] == '?' && str[n - i - 1] == '?')
            {
                if (zero + 2 <= a)
                {
                    str[i] = str[n - i - 1] = '0';
                    zero += 2;
                }
                else
                {
                    str[i] = str[n - i - 1] = '1';
                    one += 2;
                }
            }
            if (zero > a || one > b)
            {
                ok = 0;
                break;
            }
        }
        if (n % 2 == 1 && str[n / 2] == '?')
        {
            if (zero < a)
            {
                str[n / 2] = '0';
                zero++;
            }
            else
            {
                str[n / 2] = '1';
                one++;
            }
        }
        if (ok == 0 || zero != a || one != b)
        {
            cout << -1 << endl;
            continue;
        }
        cout << str << endl;
    }
}
