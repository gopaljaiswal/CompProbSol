#include <iostream>

using namespace std;

void getAns(int A[], int N, long sum)
{
    if (sum % N != 0)
    {
        cout << "-1";
        return;
    }
    int count = 0;
    long avg = sum / N;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < avg)
        {
            count += (avg - A[i]);
        }
    }
    cout << count;
    //    cout << N << " " << sum;
}

void solve()
{

    while (true)
    {
        int N;
        cin >> N;
        if (N == -1)
        {
            break;
        }
        int A[N];
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            sum += a;
            A[i] = a;
        }
        getAns(A, N, sum);
        cout << "\n";
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}