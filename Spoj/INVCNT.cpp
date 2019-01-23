#include <cstdio>
#include <iostream>

using namespace std;

long merge(long A[], long tmp[], int l, int m, int r)
{

    long count = 0;
    int i = l, j = m, k = l;
    while (i < m && j <= r)
    {
        if (A[i] <= A[j])
        {
            tmp[k] = A[i];
            i++;
        }
        else
        {
            tmp[k] = A[j];
            j++;
            count = count + (m - i);
        }
        k++;
    }
    while (i < m)
    {
        tmp[k] = A[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        tmp[k] = A[j];
        j++;
        k++;
    }

    for (int p = l; p <= r; p++)
    {
        A[p] = tmp[p];
    }
    return count;
}

long sort(long A[], long tmp[], int l, int r)
{
    long finalCount = 0;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        finalCount = sort(A, tmp, l, mid);
        finalCount += sort(A, tmp, mid + 1, r);
        finalCount += merge(A, tmp, l, mid + 1, r);
    }
    return finalCount;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        long A[N];
        long tmp[N];
        for (int i = 0; i < N; i++)
        {
            long a;
            cin >> a;
            A[i] = a;
        }
        cout << sort(A, tmp, 0, N - 1) << "\n";
        // for (int i = 0; i < N; i++)
        // {
        //     cout << A[i] << " ";
        // }
    }
}

int main()
{
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "input.txt",
            "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "output.txt",
            "w", stdout);

    solve();
    return 0;
}
