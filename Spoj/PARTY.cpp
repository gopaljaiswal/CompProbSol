#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// create a map to store solutions of subproblems

// top-down approach
int topDownKanpsackSol(unordered_map<string, int> lookup, int W, int N, vector<int> wt, vector<int> val)
{
    if (W < 0)
    {
        return INT_MIN;
    }
    if (N == 0 or W == 0)
    {
        return 0;
    }
    string key = to_string(N) + "|" + to_string(W);

    if (!lookup.count(key))
    {
        int include = val[N - 1] + topDownKanpsackSol(lookup, W - wt[N - 1], N - 1, wt, val);
        int exclude = topDownKanpsackSol(lookup, W, N - 1, wt, val);

        lookup[key] = max(include, exclude);
    }
    return lookup[key];
}

// bootom-up
void knapshack(int W, int N, vector<int> fee, vector<int> fun)
{
    int dp[N + 1][W + 1];
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j < fee[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - fee[i - 1]] + fun[i - 1]);
            }
        }
    }

    int maxFun = dp[N][W];
    int minFee = 0;
    for (int j = 0; j <= W; j++)
    {
        if (dp[N][j] == maxFun)
        {
            minFee = j;
            break;
        }
    }
    // for (int i = 0; i <= N; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << minFee << " " << maxFun << "\n";
}

// recursion
int recKnapsack(int W, int N, vector<int> fee, vector<int> fun)
{
    if (W == 0 or N == 0)
    {
        return 0;
    }
    if (fee[N - 1] > W)
    {
        return recKnapsack(W, N - 1, fee, fun);
    }
    else
    {
        return max(recKnapsack(W, N - 1, fee, fun),
                   recKnapsack(W - fee[N - 1], N - 1, fee, fun) + fun[N - 1]);
    }
}

void solve()
{
    while (true)
    {
        unordered_map<string, int> lookup;
        int W, N;
        cin >> W >> N;
        if (W == 0 and N == 0)
        {
            return;
        }
        vector<int> fee, fun;
        for (int i = 0; i < N; i++)
        {
            int a, b;
            cin >> a >> b;
            fee.push_back(a);
            fun.push_back(b);
        }
        // knapshack(W, N, fee, fun);
        // cout << "\n\n";
        // cout << recKnapsack(W, N, fee, fun);
        cout << topDownKanpsackSol(lookup, W, N, fee, fun) << "\n";
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
