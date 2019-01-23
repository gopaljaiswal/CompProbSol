
#include <iostream>
#include <vector>

using namespace std;
vector<int> A;

int partition(int left, int right, int pivot)
{
    while (left < right)
    {
        while (A[left] < pivot)
        {
            left = left + 1;
        }

        while (A[right] > pivot)
        {
            right = right - 1;
        }

        if (left <= right)
        {
            //swap(A[left], A[right]);
            int tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;

            left = left + 1;
            right = right - 1;
        }
    }
    return left;
}

void quickSort(int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = A[(left + right) / 2];
    int index = partition(left, right, pivot);
    quickSort(left, index - 1);
    quickSort(index, right);
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    quickSort(0, N - 1);
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
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