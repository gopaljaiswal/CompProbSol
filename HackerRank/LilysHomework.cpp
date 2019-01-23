
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void getAns(int N, long *A, long *B, long *sortedArr, map<long, int> m, map<long, int> m1)
{
    long counter = 0;
    sort(sortedArr, sortedArr + N);
    for (int i = 0; i < N; i++)
    {
        int p = sortedArr[i];
        if (p != A[i])
        {
            int tempIdx = m[p];
            m[p] = i;
            m[A[i]] = tempIdx;

            int tempData = A[tempIdx];
            A[tempIdx] = A[i];
            A[i] = tempData;

            counter = counter + 1;
        }
    }

    sort(sortedArr, sortedArr + N, greater<int>());
    // for (int i = 0; i < N; i++)
    // {
    //     cout << sortedArr[i] << " ";
    // }
    // cout << "\n";

    long counter1 = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        int p = sortedArr[i];
        if (p != B[i])
        {
            int tempIdx = m1[p];
            m1[p] = i;
            m1[B[i]] = tempIdx;

            int tempData = B[i];
            B[i] = p;
            B[tempIdx] = tempData;

            counter1 = counter1 + 1;
        }
    }

    cout << counter << " " << counter1;
    // if (counter > counter1)
    // {
    //     cout << counter1;
    // }
    // else
    // {
    //     cout << counter;
    // }
}

void solve()
{
    int N;
    cin >> N;
    long A[N];
    long B[N];
    long sortedArr[N];
    map<long, int> m;
    map<long, int> m1;

    for (int i = 0; i < N; i++)
    {
        long a;
        cin >> a;
        A[i] = a;
        B[i] = a;
        sortedArr[i] = a;
        m[a] = i;
        m1[a] = i;
    }
    getAns(N, A, B, sortedArr, m, m1);
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