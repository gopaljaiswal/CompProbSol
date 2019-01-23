#include <iostream>
#include <string>
using namespace std;

int getRes(string s)
{
    int noOfUnmatched = 0, minOps = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            noOfUnmatched += 1;
        }
        else if (noOfUnmatched > 0)
        {
            noOfUnmatched -= 1;
        }
        else
        {
            noOfUnmatched += 1;
            minOps += 1;
        }
    }
    minOps += (noOfUnmatched / 2);
    // cout << minOps << "\n";
    return minOps;
}

void solve()
{
    int i = 1;
    while (true)
    {
        string s;
        cin >> s;
        if (s[0] == '-')
        {
            break;
        }
        cout << i << ". " << getRes(s) << "\n";
        i++;
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
