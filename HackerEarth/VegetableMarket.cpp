

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int A[100000];

long getCal(int N, int mid)
{
    long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > mid)
        {
            sum += mid;
        }
        else
        {
            sum += A[i];
        }
    }
    return sum;
}

bool checkSum(int a[], int n, long p)
{
    long initial_sum = 0;
    for (int i = 0; i < n; i++)
    {
        initial_sum += a[i];
        if (initial_sum > p)
        {
            return true;
        }
    }
    return false;
}

void getRes(int N, int p)
{
    //cout << getCal(N, 3);

    if (checkSum(A, N, p) == false)
    {
        cout << "-1"
             << "\n";
        return;
    }

    //int diff = INT_MAX;
    int left = 0, right = 100000;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        long newK = getCal(N, mid);

        if (p == newK)
        {
            cout << mid << "\n";
            return;
        }

        // if (newK - p < diff)
        // {
        //     diff = newK - p;
        // }
        if (newK > p)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }

        //cout << newK << " " << diff << " " << left << "  " << mid << "  " << right << "\n";
    }
    cout << left << "\n";
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    sort(A, A + N);

    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        long k;
        cin >> k;
        getRes(N, k);
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