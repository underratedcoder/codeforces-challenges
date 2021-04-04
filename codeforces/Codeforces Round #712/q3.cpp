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
        lli n, one = 0, zero = 0;
        string str;
        cin >> n;
        cin >> str;
        if (n % 2 == 1 || !(str[0] == '1' && str[n - 1] == '1'))
        {
            cout << "NO" << endl;
            continue;
        }
        for (i = 1; i < n - 1; i++)
        {
            if (str[i] == '1')
                one++;
            else
                zero++;
        }
        if (!(one % 2 == 0 && zero % 2 == 0))
        {
            cout << "NO" << endl;
        }
        else
        {
            string first = "", sec = "";
            // char prev_zero = '', prev_one ='';
            lli first_left = 0, sec_left = 0;
            cout << "YES" << endl;
            for (i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    first += '(';
                    sec += '(';
                    first_left = 1;
                    sec_left = 1;
                }
                else if (i == n - 1)
                {
                    first += ')';
                    sec += ')';
                    first_left--;
                    sec_left--;
                }
                else if (str[i] == '0')
                {
                    if (first_left >= sec_left)
                    {
                        first += ')';
                        sec += '(';
                        first_left--;
                        sec_left++;
                    }
                    else
                    {
                        first += '(';
                        sec += ')';
                        first_left++;
                        sec_left--;
                    }
                }
                else if (str[i] == '1')
                {
                    if (str[i + 1] == '0' && first_left <= 1 && sec_left <= 1)
                    {
                        first += '(';
                        sec += '(';
                        first_left++;
                        sec_left++;
                    }
                    else if (first_left > 0 && sec_left > 0)
                    {
                        first += ')';
                        sec += ')';
                        first_left--;
                        sec_left--;
                    }
                    else
                    {
                        first += '(';
                        sec += '(';
                        first_left++;
                        sec_left++;
                    }
                }
            }
            cout << first << endl;
            cout << sec << endl;
        }
    }
}