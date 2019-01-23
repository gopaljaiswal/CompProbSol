#include "limits.h"
#include "unordered_map"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 10000
using namespace std;

// distance
int A[190][190];
int M, N;

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    A[i][j] = 0;

    while (!q.empty())
    {

        pair<int, int> n = q.front();
        int x = n.first;
        int y = n.second;
        q.pop();

        int dist = A[x][y] + 1;

        // left
        if (y > 0 && dist < A[x][y - 1])
        {
            q.push(make_pair(x, y - 1));
            A[x][y - 1] = dist;
        }

        // right
        if (y < M - 1 && dist < A[x][y + 1])
        {
            q.push(make_pair(x, y + 1));
            A[x][y + 1] = dist;
        }

        // below
        if (x > 0 && dist < A[x - 1][y])
        {
            q.push(make_pair(x - 1, y));
            A[x - 1][y] = dist;
        }

        // up
        if (x < N - 1 && dist < A[x + 1][y])
        {
            q.push(make_pair(x + 1, y));
            A[x + 1][y] = dist;
        }
    }
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        vector<pair<int, int>> vc;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '1')
                {
                    A[i][j] = -INF;
                    vc.push_back(make_pair(i, j));
                }
                else
                {
                    A[i][j] = INF;
                }
            }
        }

        for (int i = 0; i < vc.size(); i++)
        {
            pair<int, int> p = vc[i];
            bfs(p.first, p.second);
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
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
