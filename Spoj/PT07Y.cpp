#include <iostream>
#include <queue>
#include <vector>

using namespace std;
bool visited[10003] = {false};
vector<int> graph[10002];

// tree validation
void isTree(int N) {

  queue<int> q;
  q.push(1);
  visited[1] = true;
  int count = 0;

  while (!q.empty()) {
    int n = q.front();
    q.pop();

    for (int i = 0; i < graph[n].size(); i++) {
      int edge = graph[n][i];
      if (!visited[edge]) {
        q.push(edge);
        visited[edge] = true;
      } else {
        cout << "NO";
        return;
      }
    }
    count++;
  }
  if (count != N) {
    cout << "NO";
  } else {
    cout << "YES";
  }
}

// add edge
void addEdge(int u, int v) { graph[u].push_back(v); }

void solve() {

  int N, M;
  cin >> N >> M;
  while (M--) {
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
  }
  isTree(N);
  // cout <<  ? "YES" : "NO");
}

int main() {
  freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
          "input.txt",
          "r", stdin);
  freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
          "output.txt",
          "w", stdout);

  solve();
  return 0;
}
