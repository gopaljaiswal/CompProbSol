
#include <iostream>
#include <vector>

using namespace std;

void getRes(int a3, int a4)
{
    int a2 = a4 - a3;
    int a1 = a3 - a2;
    cout << a1 << " " << a2;
}

void solve()
{
    int a3, a4;
    cin >> a3 >> a4;
    getRes(a3, a4);
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