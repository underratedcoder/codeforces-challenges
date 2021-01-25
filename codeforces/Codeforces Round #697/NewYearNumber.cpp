#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int flag = 0;
        while (n > 0)
        {
            if (n % 2020 == 0 || n % 2021 == 0)
                flag = 1;
            n -= 2020;
        }
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}