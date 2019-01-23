#include <iostream>
#include <string>

using namespace std;

int getEditDistance(string A, string B)
{
    int len1 = A.length();
    int len2 = B.length();
    int dp[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (A[i-1] == B[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[len1][len2];
}

void solve()
{
    int N;
    cin >> N;
    while (N--)
    {
        string A, B;
        cin >> A >> B;
        cout << getEditDistance(A, B) << "\n";
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