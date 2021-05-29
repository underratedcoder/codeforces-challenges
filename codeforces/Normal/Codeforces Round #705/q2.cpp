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
    unordered_map<lli, lli> valid;
    valid[0]++;
    valid[1]++;
    valid[2]++;
    valid[5]++;
    valid[8]++;

    lli t, i, j;
    cin >> t;
    while (t--)
    {
        lli HH, MM, hh1, hh2, mm1, mm2;
        string time;

        cin >> HH >> MM;
        cin >> time;

        hh1 = time[0] - '0';
        hh2 = time[1] - '0';
        mm1 = time[3] - '0';
        mm2 = time[4] - '0';

        lli hr = hh1 * 10 + hh2;
        lli min = mm1 * 10 + mm2;
        lli rightHr, rightMin;
        bool flag = true;
        while (flag)
        {
            if (valid[min % 10] && valid[min / 10] && valid[hr % 10] && valid[hr / 10])
            {
                lli minLeft = (min % 10), minRight = (min / 10), hrLeft = (hr % 10), hrRight = (hr / 10);
                if (minLeft == 2)
                    minLeft = 5;
                else if (minLeft == 5)
                    minLeft = 2;
                if (minRight == 2)
                    minRight = 5;
                else if (minRight == 5)
                    minRight = 2;
                if (hrLeft == 2)
                    hrLeft = 5;
                else if (hrLeft == 5)
                    hrLeft = 2;
                if (hrRight == 2)
                    hrRight = 5;
                else if (hrRight == 5)
                    hrRight = 2;
                if (minLeft * 10 + minRight < HH && hrLeft * 10 + hrRight < MM)
                {
                    rightHr = hr;
                    rightMin = min;
                    break;
                }
            }

            min++;
            if (min == MM)
            {
                min = 0;
                hr++;
                if (hr == HH)
                    hr = 0;
            }
        }
        if (rightHr >= 10)
            cout << rightHr;
        else
            cout << "0" << rightHr;
        cout << ":";
        if (rightMin >= 10)
            cout << rightMin;
        else
            cout << "0" << rightMin;
        cout << endl;
    }
}
