

#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr[N];
    int lastAnswer = 0;
    for (int i = 0; i < Q; i++)
    {
        int a = 0, x = 0, y = 0;
        cin >> a >> x >> y;
        if (a == 1)
        {
            int idx = (x ^ lastAnswer) % N;
            arr[idx].push_back(y);
        }
        else if (a == 2)
        {
            int xIdx = (x ^ lastAnswer) % N;
            int yIdx = (y % arr[xIdx].size());
            //cout << xIdx << " " << y % arr[xIdx].size() << endl;

            lastAnswer = arr[xIdx][yIdx];
            cout << lastAnswer << endl;
        }
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