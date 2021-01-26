#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << (m + m) - (n + n) + 1 << endl;
    }
}