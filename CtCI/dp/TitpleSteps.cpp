
#include <iostream>
#include <map>

using namespace std;
map<int, int> dp;

int getRecCount(int N)
{
    if (N < 0)
    {
        return 0;
    }
    else if (N == 0)
    {
        return 1;
    }
    else
    {
        return getRecCount(N - 1) + getRecCount(N - 2) + getRecCount(N - 3);
    }
}

int getDpCount(int N)
{
    if (N < 0)
    {
        return 0;
    }
    else if (N == 0)
    {
        return 1;
    }
    if (dp[N] != 0)
    {
        return dp[N];
    }
    return dp[N] = getDpCount(N - 1) + getDpCount(N - 2) + getDpCount(N - 3);
}

void solve()
{
    int N = 10;
    cout << getRecCount(N) << "\n";
    cout << getDpCount(N) << "\n";
}

int main()
{
    solve();
    return 0;
}