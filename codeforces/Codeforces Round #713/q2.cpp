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
        lli n, r1, r2, r3, r4, c1, c2, c3, c4;
        bool first = false;
        bool sec = false;
        cin >> n;
        vector<vector<char>> v(n, vector<char>(n));
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {

                cin >> v[i][j];
                if (v[i][j] == '*')
                {
                    if (!first)
                    {
                        r1 = i;
                        c1 = j;
                        first = true;
                    }
                    else if (!sec)
                    {
                        r2 = i;
                        c2 = j;
                        sec = true;
                    }
                }
            }
        }
        // cout << r1 << " " << c1 << endl;
        // cout << r2 << " " << c2 << endl;

        if (r1 == r2)
        {
            // cout << "one" << endl;
            if (r1 - 1 >= 0)
            {
                r3 = r4 = r1 - 1;
                c3 = c1;
                c4 = c2;
            }
            else
            {
                r3 = r4 = r1 + 1;
                c3 = c1;
                c4 = c2;
            }
        }
        else if (c1 == c2)
        {
            // cout << "two" << endl;
            if (c1 - 1 >= 0)
            {
                r3 = r1;
                r4 = r2;
                c3 = c4 = c1 - 1;
            }
            else
            {
                r3 = r1;
                r4 = r2;
                c3 = c4 = c1 + 1;
            }
        }
        else
        {
            // cout << "three" << endl;
            r3 = r1;
            c3 = c2;
            r4 = r2;
            c4 = c1;
        }

        // cout << "mid" << endl;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (
                    (i == r1 || i == r2 || i == r3 || i == r4) &&
                    (j == c1 || j == c2 || j == c3 || j == c4))
                {
                    cout << '*';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << endl;
        }
    }
}
