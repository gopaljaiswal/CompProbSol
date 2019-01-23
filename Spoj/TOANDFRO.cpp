#include <iostream>
#include <vector>

using namespace std;

void getAns(int N, string s)
{
    int len = s.length();
    char A[len / N][N];

    int j = -1, k = 0;
    for (int i = 0; i < len; i++)
    {
        if (i % N == 0)
        {
            j++;
            if (j % 2 == 0)
            {
                k = i % N;
            }
            else
            {
                k = N - 1;
            }
        }

        A[j][k] = s[i];
        if (j % 2 == 0)
        {
            k++;
        }
        else if (j % 2 != 0)
        {
            k--;
        }
    }

    for (int j1 = 0; j1 < N; j1++)
    {
        for (int i1 = 0; i1 < (len / N); i1++)
        {
            cout << A[i1][j1];
        }
    }
}

void solve()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        string s;
        cin >> s;
        getAns(N, s);
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