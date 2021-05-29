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

// #######################
// code start from here...
// #######################

int main()
{
    lli t, i, j;
    cin >> t;

    while (t--)
    {
        lli n, sum = 0, c1 = 0, c2 = 0;

        cin >> n;
        vector<lli> v1, v2;

        for (i = 0; i < n; i++)
        {
            lli x;
            cin >> x;
            if (x % 2 == 0)
                v2.push_back(x);
            else
                v1.push_back(x);
        }
        sort(v1.begin(), v1.end(), greater<lli>());
        sort(v2.begin(), v2.end(), greater<lli>());
        lli alice = 0, bob = 0, i1 = 0, i2 = 0, s1 = v1.size(), s2 = v2.size(), chance = 0;
        while (i1 < s1 && i2 < s2)
        {
            if (chance == 0)
            {
                if (v2[i2] > v1[i1])
                {
                    alice += v2[i2];
                    i2++;
                }
                else
                {
                    i1++;
                }
            }
            else
            {
                if (v2[i2] < v1[i1])
                {
                    bob += v1[i1];
                    i1++;
                }
                else
                {
                    i2++;
                }
            }
            chance = (chance + 1) % 2;
        }

        if (i2 < s2)
        {
            if (chance == 1)
            {
                i2++;
            }
            while (i2 < s2)
            {
                alice += v2[i2];
                i2++;
                i2++;
            }
        }
        if (i1 < s1)
        {
            if (chance == 0)
            {
                i1++;
            }
            while (i1 < s1)
            {
                bob += v1[i1];
                i1++;
                i1++;
            }
        }

        if (alice > bob)
        {
            cout << "Alice" << endl;
        }
        else if (alice < bob)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Tie" << endl;
        }
    }
}