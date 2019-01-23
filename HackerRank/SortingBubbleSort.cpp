

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}

void buubleSort(vector<int> A, int N)
{
    int counter = 0;
    bool isSorted = true;
    while (isSorted)
    {
        isSorted = false;
        int lastElement = N - 1;
        for (int i = 0; i < lastElement; i++)
        {
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
                isSorted = true;
                counter += 1;
            }
        }
        lastElement--;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << A[i] << " ";
    // }
    cout << "Array is sorted in " << counter << " swaps."
         << "\n";
    cout << "First Element: " << A[0] << "\n";
    cout << "Last Element: " << A[N - 1];
}

void solve()
{
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    buubleSort(A, N);
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