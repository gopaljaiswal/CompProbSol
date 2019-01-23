#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

map<int, long long> dp;

long long f(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    long long aux = f(n / 2) + f(n / 3) + f(n / 4);

    if (aux > n)
        dp[n] = aux;
    else
        dp[n] = n;

    return dp[n];
}

void solve()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("%lld\n", f(n));
    }
}

int main()
{
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}