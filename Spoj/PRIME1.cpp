#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int no)
{
    if (no == 1)
    {
        return false;
    }
    if (no == 2 || no == 3)
    {
        return true;
    }
    for (int i = 2; i <= sqrt(no); i++)
    {
        if (no % i == 0)
        {
            return false;
        }
    }
    return true;
}

void getPrimeNo(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            cout << i << "\n";
        }
    }
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        getPrimeNo(a, b);
        cout << "\n";
    }
}

int main()
{
#ifndef ONLINE_JUDGEÎ
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
