
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using namespace std;

vector<int> graph[1000];
vector<int> relations[1000];
vector<int> level(1000);
vector<int> visited(1000, false);

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void bfs(int start)
{
    queue<int> que;
    que.push(start);
    visited[start] = true;
    level[start] = 0;

    while (!que.empty())
    {
        int n = que.front();
        que.pop();
        cout << n << " ";

        for (int i = 0; i < graph[n].size(); i++)
        {
            int edge = graph[n][i];
            if (!visited[edge])
            {
                que.push(edge);
                visited[edge] = true;
                level[edge] = level[n] + 1;
            }
        }
    }
}

void solve()
{

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        relations[i].push_back(u);
        relations[i].push_back(v);
    }
    bfs(1);

    // cout << "\n";
    // for (int i = 1; i <= 4; i++)
    // {
    //     cout << level[i] << " ";
    // }

    bool isBug = false;
    for (int i = 0; i < M; i++)
    {
        if ((level[relations[i][0]] - level[relations[i][1]]) % 2 == 0)
        {
            isBug = true;
            break;
        }
    }

    if (!isBug)
    {
        cout << "NO" << "\n";
    }
    else
    {
        cout << "YES" << "\n";
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
