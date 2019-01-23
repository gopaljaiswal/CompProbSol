

#include <iostream>

using namespace std;

void getAns(int N)
{
    long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += i * i;
    }
    cout << ans << "\n";
}

void solve()
{

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        getAns(N);
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}