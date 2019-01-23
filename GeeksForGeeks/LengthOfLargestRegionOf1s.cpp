#include <iostream>
#include <algorithm>

using namespace std;

int A[50][50];
bool visited[50][50];

bool isSafe(int r, int c, int R, int C)
{
    return (r >= 0) && (r < R) && (c >= 0) && (c < C) && (A[r][c] == 1 && !visited[r][c]);
}

void dfsUtil(int r, int c, int R, int C, int &count)
{
    static int x[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[r][c] = true;
    for (int i = 0; i < 8; i++)
    {
        if (isSafe(r + x[i], c + y[i], R, C))
        {
            count++;
            dfsUtil(r + x[i], c + y[i], R, C, count);
        }
    }
}

void getRes(int R, int C)
{
    int result = INT_MIN;
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (A[i][j] == 1 && !visited[i][j])
            {
                int count = 1;
                dfsUtil(i, j, R, C, count);

                result = max(result, count);
            }
        }
    }
    cout << result << "\n";
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int R, C;
        cin >> R >> C;
        int i = -1, j = 0;

        for (int k = 0; k < (R * C); k++)
        {
            int a;
            cin >> a;

            if (k % C == 0)
            {
                i++;
            }

            A[i][j % C] = a;
            j++;
        }
        // for (int i = 0; i < R; i++)
        // {
        //     for (int j = 0; j < C; j++)
        //     {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
        getRes(R, C);
        //cout << "\n";
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
