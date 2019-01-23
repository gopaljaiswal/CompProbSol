#include <iostream>

using namespace std;

int bst(int A[], int l1, int r1, int ele)
{
    int l = l1, r = r1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (A[mid] == ele)
        {
            return mid;
        }
        else if (A[mid] < ele)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return -1;
}

int getPivot(int A[], int N)
{
    int pivotIdx;
    for (int i = 1; i < N; i++)
    {
        if (A[i] < A[i - 1])
        {
            pivotIdx = i;
            break;
        }
    }
    return pivotIdx;
}

void solve()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int A[N];
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            A[j] = a;
        }
        int ele;
        cin >> ele;

        int pivotIdx = getPivot(A, N);
        if (ele >= A[0])
        {
            cout << bst(A, 0, pivotIdx, ele) << "\n";
        }
        else
        {
            cout << bst(A, pivotIdx, N, ele) << "\n";
        }
        //cout << pivotIdx;
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
