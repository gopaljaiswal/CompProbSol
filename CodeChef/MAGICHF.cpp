
#include <iostream>
#include <vector>

using namespace std;

void getReS(int X, vector<int> A, vector<int> B)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == X)
        {

            int temp = B[i];
            B[i] = X;
            A[i] = temp;

            X = temp;
        }
        else if (B[i] == X)
        {

            int temp = A[i];
            A[i] = X;
            B[i] = temp;

            X = temp;
        }
    }
    cout << X << "\n";
}

void solve()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, X, S;
        vector<int> A;
        vector<int> B;

        cin >> N >> X >> S;
        for (int j = 0; j < S; j++)
        {
            int a, b;
            cin >> a >> b;
            A.push_back(a);
            B.push_back(b);
        }
        getReS(X, A, B);
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