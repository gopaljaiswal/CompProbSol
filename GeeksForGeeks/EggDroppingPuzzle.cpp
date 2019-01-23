

#include <iostream>
#include <cmath>

using namespace std;

// #### Recursion
// int eggFlooor(int N, int K)
// {
//     if (K == 0 || K == 1)
//     {
//         return K;
//     }
//     if (N == 1)
//     {
//         return K;
//     }
//     int min = INT_MAX, x, res;
//     for (int x = 1; x <= K; x++)
//     {
//         res = max(eggFlooor(N - 1, x - 1), eggFlooor(N, K - x));
//         if (res < min)
//         {
//             min = res;
//         }
//     }
//     return min + 1;
// }

int eggFlooor(int N, int K)
{
    int dp[N + 1][K + 1];
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int j = 1; j <= K; j++)
    {
        dp[1][j] = j;
    }

    int res;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= K; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (dp[i][j] > res)
                {
                    dp[i][j] = res;
                }
            }
        }
    }
    return dp[N][K];
}
void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, K;
        cin >> N;
        cin >> K;
        cout << eggFlooor(N, K) << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}