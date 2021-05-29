#include <bits/stdc++.h>
using namespace std;
 
bool pr[31000];
void sv(int n)
{
        memset(pr, true, sizeof(pr));
    for (int j = 2; j * j <= n; j++)
    {
        if (pr[j] == true)
        {
            for (int i = j * j; i <= n; i += j)
                pr[i] = false;
        }
    }
}
 
long int getprime(int num)
{
 
    if (num <= 1)
        return 2;
          bool fnd = false;
    while (!fnd)
    {
        if (pr[num])
        {
            fnd = true;
            break;
        }
        num++;
    }
 
    return num;
}
 
int main()
{
    sv(31000);
    long int t, zz, i;
    cin >> t;
    while (t--)
    {
        cin >> zz;
        long int aa = getprime(1 + zz);
        long int bb = (long int)getprime(aa + zz);
        cout << aa * bb << endl;
    }
}