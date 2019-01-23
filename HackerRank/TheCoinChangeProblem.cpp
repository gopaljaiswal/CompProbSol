
#include <iostream>
#include <vector>

using namespace std;
vector<long> vc;

long getRes(int N, int S)
{

    long dp[N + 1][S + 1];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= S; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= S; j++)
        {

            if (j < vc[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - vc[i - 1]];
            }
        }
    }
    return dp[N][S];
}

void solve()
{
    int N, S;
    cin >> S >> N;

    for (int i = 0; i < N; i++)
    {
        long a;
        cin >> a;
        vc.push_back(a);
    }
    cout << getRes(N, S) << "\n";
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