

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int ansEle = INT_MAX;
        int A[100] = {0};
        int max = INT_MIN;
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            A[a] = A[a] + 1;
            if (A[a] > max)
            {
                max = A[a];
                ansEle = a;
            }
            if (A[a] == max && a < ansEle)
            {
                ansEle = a;
            }
        }
        cout << ansEle << "\n";
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