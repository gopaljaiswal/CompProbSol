

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int getRes(int W, vector<int> wt, vector<int> val, int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] > w)
            {
                K[i][w] = K[i - 1][w];
            }
            else
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            // else if (wt[i - 1] <= w)
            //     K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            // else
            //     K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, W;
        cin >> N;
        cin >> W;
        vector<int> wt, val;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            val.push_back(x);
        }

        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            wt.push_back(x);
        }
        cout << getRes(W, wt, val, N) << endl;
    }
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
//     freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);
// #endif // ONLINE_JUDGE

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     clock_t beg = clock();
    solve();
    // clock_t end = clock();
    // fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}