#include <iostream>
#include <stack>
#include <vector>

using namespace std;
bool visited[5] = {false};
vector<int> graph[5];

// priny dfs using stack
void printDfs(int src) {
  stack<int> s;
  s.push(src);
  visited[src] = true;

  while (s.size() > 0) {
    int n = s.top();
    s.pop();
    cout << n << " ";

    for (int i = 0; i < graph[n].size(); i++) {
      int edge = graph[n][i];
      if (!visited[edge]) {
        s.push(edge);
        visited[edge] = true;
      }
    }
  }
}

void dfsUtil(int i) {
  visited[i] = true;
  cout << i << " ";
  for (int j = 0; j < graph[i].size(); j++) {
    int edge = graph[i][j];
    if (!visited[edge]) {
      dfsUtil(edge);
    }
  }
}

// recursive solution
void dfs(int src) {
  for (int i = 0; i < 5; i++) {
    if (!visited[i]) {
      dfsUtil(i);
    }
  }
}

// add edge
void addEdge(int u, int v) {
  graph[u].push_back(v);
  graph[v].push_back(u);
}

// print graph example
void printGraph() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {

  int N;
  cin >> N;
  while (N--) {
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
  }
  // printGraph();
  // printDfs(0);
  dfs(0);
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
