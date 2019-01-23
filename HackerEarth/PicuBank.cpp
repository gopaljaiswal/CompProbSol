

#include <iostream>
#include <vector>
using namespace std;

int getRes(int D, int A, int M, int B, int X)
{
    int sum = X - D;
    int div = 0, mod = 0, i = 0;

    if (sum > ((A * M) + B))
    {
        div = (sum / ((A * M) + B));
        mod = (sum % ((A * M) + B));
        i = (div * (M + 1));
    }
    else
    {
        div = (sum / (A * M));
        mod = (sum % (A * M));
        i = (div * M);
    }

    if (mod > 0)
    {
        if (A > mod)
        {
            i = i + 1;
        }
        else
        {
            int newDiv = (mod / A);
            int newMod = (mod % A);
            i = i + newDiv;
            cout << mod << " " << newDiv << " " << newMod << " " << i << endl;
            if (newMod > 0)
            {
                i = i + 1;
            }
        }
    }
    return i;
}

void solve()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int D, A, M, B, X;
        cin >> D >> A >> M >> B >> X;
        cout << getRes(D, A, M, B, X) << endl;
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
}