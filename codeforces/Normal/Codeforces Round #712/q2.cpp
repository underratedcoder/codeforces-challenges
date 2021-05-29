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
        lli n;
        string inp, exp;
        cin >> n;
        cin >> inp;
        cin >> exp;
        if (inp == exp)
        {
            cout << "YES" << endl;
            continue;
        }
        vector<lli> one(n), zero(n), same;
        if (inp[0] == '0')
        {
            zero[0] = 1;
        }
        else
        {
            one[0] = 1;
        }
        same.push_back(-1);
        for (i = 1; i < n; i++)
        {
            if (inp[i] == '0')
            {
                zero[i] = 1 + zero[i - 1];
                one[i] = one[i - 1];
            }
            else
            {
                zero[i] = zero[i - 1];
                one[i] = 1 + one[i - 1];
            }
            if (zero[i] == one[i])
                same.push_back(i);
        }
        if (same.size() == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        lli ok = 1, l = same.size();
        for (j = same[l - 1] + 1; j < n; j++)
        {
            if (inp[j] != exp[j])
            {
                ok = 0;
                break;
            }
        }
        if (ok == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        for (i = l - 1; i >= 1; i--)
        {
            lli c = 0;
            for (j = same[i - 1] + 1; j <= same[i]; j++)
            {
                if (inp[j] == exp[j])
                {
                    c++;
                }
            }
            if (c != 0 && c != (same[i] - same[i - 1]))
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
