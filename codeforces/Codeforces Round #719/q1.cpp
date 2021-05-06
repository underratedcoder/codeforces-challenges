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
        lli n, arr[26], ok = 1;
        memset(arr, 0, sizeof(arr));
        string str, tmp = "";
        cin >> n;
        cin >> str;
        for (i = 0; i < n;)
        {
            tmp += str[i];
            j = i + 1;
            while (j < n)
            {
                if (str[j] == str[i])
                {
                    j++;
                    continue;
                }
                break;
            }
            i = j;
        }
        for (i = 0; i < tmp.size(); i++)
        {
            if (arr[tmp[i] - 'A'] != 0)
            {
                ok = 0;
                break;
            }
            arr[tmp[i] - 'A'] = 1;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
