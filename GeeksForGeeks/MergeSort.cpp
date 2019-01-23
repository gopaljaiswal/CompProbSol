#include <iostream>

using namespace std;

int merge(int A[], int l, int m, int r)
{
    int counter = 0;
    int n1 = (m - l + 1);
    int n2 = (r - m);

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = A[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
            counter += (m - i);
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
    return counter;
}

int sort(int A[], int l, int r)
{
    int counter = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        counter = sort(A, l, m);
        counter += sort(A, m + 1, r);
        counter += merge(A, l, m, r);
    }
    return counter;
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
        int counter = sort(A, 0, N - 1);

        // for (int l = 0; l < N; l++)
        // {
        //     cout << A[l] << " ";
        // }
        cout << counter << "\n";
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
