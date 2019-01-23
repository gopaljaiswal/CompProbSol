
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void getAns(vector<int> A)
{
    long swapCnt = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (A[i] != (i + 1))
        {
            int temp = A[A[i] - 1];
            A[A[i] - 1] = A[i];
            A[i] = temp;

            swapCnt += 1;
            i = i - 1;
        }
    }

    cout << swapCnt << endl;
}

void solve()
{
    int N, K;
    cin >> N >> K;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        A.push_back(0);
    }

    long int sum = 0;
    for (int i = 0; i < K; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;

        for (int j = a - 1; j < b; j++)
        {
            A[j] = A[j] + k;
            if (A[j] > sum)
            {
                sum = A[j];
            }
        }
    }
    cout << sum << endl;
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