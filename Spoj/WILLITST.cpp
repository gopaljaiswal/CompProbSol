#include <cstdio>
#include <iostream>

using namespace std;

bool getRes(long long int N)
{
    if (N == 0 || N == 1)
    {
        return true;
    }
    if (N % 2 != 0)
    {
        return false;
    }
    return getRes(N / 2);
}

void solve()
{
    long long int N;
    while (scanf("%lld", &N) != EOF)
    {
        string ans = getRes(N) == true ? "TAK" : "NIE";
        cout << ans << "\n";
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