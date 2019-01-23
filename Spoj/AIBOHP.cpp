
#include <iostream>

using namespace std;

string reverseString(string s, int len)
{
    string rev = "";
    for (int i = len - 1; i >= 0; i--)
    {
        rev += s[i];
    }
    return rev;
}

int lcm(string s)
{
    int len = s.length();
    string revs = reverseString(s, len);
    int dp[len + 1][len + 1];

    for (int i = 0; i < len + 1; i++)
    {
        for (int j = 0; j < len + 1; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == revs[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len][len];
}

void solve()
{
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        cout << s.length() - lcm(s) << "\n";
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