#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long int t, i, j, k, n, x, l, sum;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> a;
        l = a.length();
        cout << 1;
        sum = 1 + (a[0] - 48);
 
        for (i = 1; i < l; i++)
        {
            x = (a[i] - 48);
            if (x + 1 == sum)
            {
                cout << 0;
                sum = x;
            }
            else
            {
                cout << 1;
                sum = x + 1;
            }
        }
        cout << endl;
    }
}