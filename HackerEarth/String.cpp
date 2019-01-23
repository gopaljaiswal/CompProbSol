

#include <iostream>
#include <vector>
#define ASCII_SIZE 256

using namespace std;

int getRes(char *A, int *count, int N)
{
    int max = -1;
    for (int i = 0; i < N; i++)
    {
        if (max < count[A[i]])
        {
            max = count[A[i]];
        }
    }
    cout << max << endl;
    return N - (max);
}

void solve()
{
    int N;
    cin >> N;
    int count[ASCII_SIZE] = {0};
    char A[N];
    for (int i = 0; i < N; i++)
    {
        char ch;
        cin >> ch;
        A[i] = ch;
        count[ch] = count[ch] + 1;
    }
    // for (int i = 0; i < N; i++)
    // {
    //     cout << A[i] << " " << count[A[i]] << endl;
    // }
    cout << getRes(A, count, N);
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
}