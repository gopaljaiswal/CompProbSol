#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void getRes(int N, vector<int> M, vector<int> W)
{
    sort(M.begin(), M.end());
    sort(W.begin(), W.end());

    long product = 0;
    for (int i = 0; i <= N - 1; i++)
        product = product + (M[i]) * (W[i]);

    cout << product << "\n";
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        vector<int> M, W;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            M.push_back(a);
        }
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            W.push_back(a);
        }
        getRes(N, M, W);
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}