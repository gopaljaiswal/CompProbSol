#include <iostream>
#include <queue>
#include <vector>
#define MAX 10000

using namespace std;
vector<int> vc[MAX];

int getLastEle(int N, int s, bool isLastEle)
{

    bool visited[N];
    int cost[N];
    for (int i = 0; i < N; i++)
    {
        cost[i] = 0;
        visited[i] = false;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int lastElement;

    while (!q.empty())
    {
        int n = q.front();
        lastElement = n;
        q.pop();

        for (int i = 0; i < vc[n].size(); i++)
        {
            int edge = vc[n][i];
            if (!visited[edge])
            {
                q.push(edge);
                visited[edge] = true;
                cost[edge] = cost[n] + 1;
            }
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     cout << cost[i] << " ";
    // }
    // cout << "\n";

    if (isLastEle)
    {
        return lastElement;
    }
    return cost[lastElement];
}

void addEdge(int u, int v)
{
    vc[u].push_back(v);
    vc[v].push_back(u);
}

void solve()
{
    int N;
    cin >> N;
    int M = N - 1;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u - 1, v - 1);
    }
    int lastEle = getLastEle(N, 0, true);
    //cout << lastEle << "\n";
    cout << getLastEle(N, lastEle, false);
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