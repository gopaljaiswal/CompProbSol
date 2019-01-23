#include <iostream>

using namespace std;

struct Interval
{
    int buy;
    int sell;
};

void getRes(int A[], int N)
{

    Interval I[N / 2 + 1];
    int count = 0;
    int i = 0;
    while (i < N - 1)
    {
        while ((i < N - 1) && (A[i + 1] <= A[i]))
        {
            i++;
        }

        if (i == N - 1)
        {
            break;
        }

        I[count].buy = i++;

        while ((i < N) && (A[i] >= A[i - 1]))
        {
            i++;
        }

        I[count].sell = i - 1;
        count++;
    }

    if (count == 0)
    {
        cout << "No Profit";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << "(" << I[i].buy << " " << I[i].sell
                 << ") ";
        }
    }
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
        getRes(A, N);
        cout << "\n";
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
