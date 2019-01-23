#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<int> graph[], int start, vector<int> level,
         vector<bool> visited)
{
    queue<int> que;
    que.push(start);
    visited[start] = true;

    while (!que.empty())
    {
        int n = que.front();
        cout << n << " ";
        que.pop();

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

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void addInteraction(vector<int> interaction[], int i, int u, int v)
{
    interaction[i].push_back(v);
    interaction[i].push_back(u);
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N, M;
        cin >> N >> M;
        vector<int> graph[N + 1];
        vector<int> interaction[M + 1];

        vector<int> level(N + 1);
        vector<bool> visited(N + 1);
        for (int i = 1; i <= N; i++)
        {
            level[i] = 0;
            visited[i] = false;
        }
        for (int i = 1; i <= M; i++)
        {
            int u, v;
            cin >> u >> v;
            addEdge(graph, u, v);
            addInteraction(interaction, i, u, v);
        }
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                bfs(graph, i, level, visited);
            }
        }
        cout << "\n";
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