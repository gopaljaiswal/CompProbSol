#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int stringtoint(string &s)
{
    int ten = 1;
    int b = 0;
    int i;
    for (i = s.size() - 1; i >= 0; i--)
    {
        b = b + (s[i] - '0') * ten;
        ten = ten * 10;
    }
    return b;
}

bool ifnumber(string &s)
{
    bool check = true;
    for (int i = 0; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

void solve()
{
    int i, j, b, c, d, e, f, k, t, s, n1, n2, n3;
    string s1, s2, s3;
    cin >> t;
    char ch;
    for (k = 1; k <= t; k++)
    {
        cin >> s1 >> ch >> s2 >> ch >> s3;
        if (ifnumber(s1) == false)
        {
            n2 = stringtoint(s2);
            n3 = stringtoint(s3);
            n1 = n3 - n2;
            cout << n1 << " + " << n2 << " = " << n3 << endl;
        }
        else if (ifnumber(s2) == false)
        {
            n1 = stringtoint(s1);
            n3 = stringtoint(s3);
            n2 = n3 - n1;
            cout << n1 << " + " << n2 << " = " << n3 << endl;
        }
        else
        {
            n1 = stringtoint(s1);
            n2 = stringtoint(s2);
            n3 = n1 + n2;
            cout << n1 << " + " << n2 << " = " << n3 << endl;
        }
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "input.txt",
            "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "output.txt",
            "w", stdout);

    solve();
    return 0;
}