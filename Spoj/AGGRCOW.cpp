#include <iostream>

using namespace std;

int getLargestMinDist(int A[], int N, int mid, int K)
{
    int count = 1;
    int i = 0;
    int j = 1;
    while (j < N)
    {
        int diff = A[j] - A[i];
        if (diff >= mid)
        {
            count++;
            i = j;
        }
        // cout << i << "  " << diff << "\n";
        if (count == K)
        {
            return true;
        }
        j++;
    }
    return false;
}

int bst(int A[], int N, int K)
{
    int low = 0, high = 1000000000;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        bool flag = getLargestMinDist(A, N, mid, K);
        if (flag == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        // cout << low << " " << mid << " " << high << "  " << flag << "\n";
    }
    return high;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            A[i] = a;
        }
        sort(A, A + N);
        cout << bst(A, N, K) << "\n";
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