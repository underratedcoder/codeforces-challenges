#include <bits/stdc++.h>
using namespace std;

#define li long int
#define lli long long int

int main()
{
    lli t, n, i, j;
    cin >> t;

    while (t--)
    {   
        cin >> n;
        if(ceil(log2(n)) == floor(log2(n))) {
            cout<<"NO"<<endl;
        }
        else
         cout<<"YES"<<endl;
    
    }
}