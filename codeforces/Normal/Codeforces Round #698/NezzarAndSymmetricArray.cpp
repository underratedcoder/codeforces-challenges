#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli unsigned long long int

int main()
{
    lli t, n, k, i;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<lli> v;

        for (i = 0; i < 2 * n; i++)
        {
            lli x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), greater<lli>());

        lli ok = 1;
        for (i = 0; i < 2 * n; i = i + 2)
        {

            if ((v[i] != v[i + 1]) || (v[i] % 2 == 1))
            {
                ok = 0;
                break;
            }
            if (i > 0 && (v[i] == v[i - 1]))
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

        lli div, num, next, prev;
        for (i = 0; i < 2 * n; i = i + 2)
        {
            div = (2 * n - i);
            if (i == 0)
            {
                if (v[i] % div)
                {
                    ok = 0;
                    break;
                }
                num = v[i] / div;
                if (num == 0)
                {
                    ok = 0;
                    break;
                }
                prev = num;
            }
            else
            {
                if (((v[i] - 2 * num) <= 0) || (v[i] - 2 * num) % div)
                {
                    ok = 0;
                    break;
                }
                next = (v[i] - 2 * num) / div;

                if (next == 0 || next > prev)
                {
                    ok = 0;
                    break;
                }
                prev = next;
                num = num + next;
            }
        }
        if (ok == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}