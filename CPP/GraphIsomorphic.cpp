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
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
#define FF first
#define SS second
#define pb(v) push_back(v)
#define mp(x, y) make_pair(x, y)
// #define min(a, b) (a>b?b:a)
// #define max(a, b) (a>b?a:b)

#define s(n) scanf("%d", &n)
#define rep(i, start, end) for (int i = start; i < end; i++)
using namespace std;

class GRAPH
{
  public:
    map<string, vector<pair<string, string>>> adj; // edges storing DS
    int N, E;                                      // num of nodes and edges of this graph

    GRAPH(int N, int E)
    {
        adj.clear();
        this->N = N;
        this->E = E;
    }

    void addEdges()
    {
        string u, v, val;
        for (int i = 0; i < this->E; i++)
        {
            cin >> u >> v >> val;
            this->adj[u].push_back({v, val});
        }
    }

    void reachableNodes(string at, set<string> &seen)
    {
        seen.insert(at);
        for (auto &to : adj[at])
        {
            if (seen.find(to.first) == seen.end())
                reachableNodes(to.first, seen);
        }
    }

    string findRoot()
    {
        for (auto &node : adj)
        {
            set<string> seen;
            this->reachableNodes(node.first, seen);

            if (seen.size() == this->N)
            {
                // this is my root as i can visit all nodes from it
                // Also only one root exists
                return node.first;
            }
        }
        // assert("No root found!!");
        return ""; //  in case we don't have root in such case input is not valid
    }
};

map<string, string> equals;
bool dfsMatch(GRAPH &graph1, GRAPH &graph2, string root1, string root2)
{
    if (graph1.adj[root1].size() != graph2.adj[root2].size())
        return false;

    equals[root1] = root2;

    for (auto &to1 : graph1.adj[root1])
    {
        bool found = false;
        if (equals.find(to1.first) != equals.end())
            continue; // avoid cycles
        for (auto &to2 : graph2.adj[root2])
        {
            if (to1.second == to2.second)
            { // constraint specified in question that
                // weight will be distinct
                found = true & dfsMatch(graph1, graph2, to1.first, to2.first);
                if (found == false)
                    return false;
            }
        }
    }
    return true;
}

string isIsomorphic(GRAPH &graph1, GRAPH &graph2)
{
    equals.clear(); // not needed
    string yes = "yes", no = "no";

    if (graph1.N != graph2.N or graph1.E != graph2.E)
        return no;
    if (graph1.N <= 1)
        return yes;

    string root1 = graph1.findRoot();
    string root2 = graph2.findRoot();

    // create a map where each key tells what node name in graph1 is equal to node
    // name in graph2
    // after iterate over this map and compare whether all edges are same or not
    if (dfsMatch(graph1, graph2, root1, root2) == false)
        return no;

    // for(auto &it: equals) cout << it.first << ' ' << it.second << '\n';
    for (auto &node : equals)
    {
        map<string, string> ref;
        for (auto &it : graph2.adj[node.second])
            ref[it.second] = it.first;
        for (auto &it : graph1.adj[node.first])
        {
            if (ref[it.second] != equals[it.first])
                return no;
        }
    }

    return yes;
}

void solve()
{
    int nodes_count, edges_count;

    cin >> nodes_count >> edges_count;
    GRAPH graph1(nodes_count, edges_count);
    graph1.addEdges();

    cin >> nodes_count >> edges_count;
    GRAPH graph2(nodes_count, edges_count);
    graph2.addEdges();

    cout << isIsomorphic(graph1, graph2) << '\n';
}

int main()
{
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "input.txt",
            "r", stdin);
    // freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
    //         "output.txt",
    //         "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
}