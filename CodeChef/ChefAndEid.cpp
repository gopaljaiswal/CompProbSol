

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getRes(vector<int> A)
{
    sort(A.begin(), A.end());
    int min = INT_MAX;
    for (int i = 1; i < A.size(); i++)
    {
        int m = A[i] - A[i - 1];
        if (m < min)
        {
            min = m;
        }
    }
    cout << min << endl;
}

void solve()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int N;
        cin >> N;
        vector<int> A;
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        getRes(A);
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