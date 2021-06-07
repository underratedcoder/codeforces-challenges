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
void fun(string str)
{
    int i, j, k;
    string tmp = "abcdefghijklmnopqrstuvwxyz";
    while (true)
    {
        for (i = 0; i < 26; i++)
        {
            string s1(1, tmp[i]);
            if (str.find(s1) == std::string::npos)
            {
                cout << s1 << endl;
                return;
            }
        }

        for (i = 0; i < 26; i++)
        {
            string s1(1, tmp[i]);
            for (j = 0; j < 26; j++)
            {
                string s2 = s1 + tmp[j];
                if (str.find(s2) == std::string::npos)
                {
                    cout << s2 << endl;
                    return;
                }
            }
        }

        for (i = 0; i < 26; i++)
        {
            string s1(1, tmp[i]);
            for (j = 0; j < 26; j++)
            {
                string s2 = s1 + tmp[j];
                for (k = 0; k < 26; k++)
                {
                    string s3 = s2 + tmp[k];
                    if (str.find(s3) == std::string::npos)
                    {
                        cout << s3 << endl;
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    lli t, i, j, k, n, minm, maxm, ans, cnt;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string str;
        cin >> str;
        fun(str);
    }
}
