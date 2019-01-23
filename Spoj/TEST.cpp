#include <iostream>

using namespace std;

void solve()
{
    while (true)
    {
        int a;
        cin >> a;
        if (a == 42)
        {
            break;
        }
        cout << a << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGEÎ
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
