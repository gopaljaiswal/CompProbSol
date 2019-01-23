#include <iostream>
#include <vector>

#define MAX 1e5
using namespace std;
vector<int> tree(4 * MAX + 5, 0);
vector<int> A;
vector<int> lazy(4 * MAX + 5, 0);

//lazy propogation implementation
// input
// 8 4
// -1 2 4 1 7 1 3 2
// 0 0 3 3
// 0 0 3 1
// 0 0 0 2
// 1 3 5

// output
// 1

void buildTree(int rootIdx, int l, int r)
{
    if (l == r)
    {
        tree[rootIdx] = A[l];
    }
    else
    {
        int mid = (l + r) / 2;
        buildTree(2 * rootIdx + 1, l, mid);
        buildTree(2 * rootIdx + 2, mid + 1, r);
        tree[rootIdx] = min(tree[2 * rootIdx + 1], tree[2 * rootIdx + 2]);
    }
}

void lazyUpdateRangeMinTree(int rootIdx, int l, int r, int x, int y,
                            int delta)
{
    if (lazy[rootIdx] != 0)
    {
        tree[rootIdx] += (r - l + 1) * lazy[rootIdx];
        if (l != r)
        {
            lazy[2 * rootIdx + 1] += lazy[rootIdx];
            lazy[2 * rootIdx + 2] += lazy[rootIdx];
        }
        lazy[rootIdx] = 0;
    }

    if (x > r or y < l)
    {
        return;
    }
    if (x <= l and r <= y)
    {
        tree[rootIdx] += (r - l + 1) * delta;
        if (l != r)
        {
            lazy[2 * rootIdx + 1] += delta;
            lazy[2 * rootIdx + 2] += delta;
        }
        return;
    }
    int mid = (l + r) >> 1;
    lazyUpdateRangeMinTree(2 * rootIdx + 1, l, mid, x, y, delta);
    lazyUpdateRangeMinTree(2 * rootIdx + 2, mid + 1, r, x, y, delta);

    tree[rootIdx] = min(tree[2 * rootIdx + 1], tree[2 * rootIdx + 2]);
}

int lazyQueryRangeMinTree(int rootIdx, int l, int r, int x, int y)
{
    if (l > r)
    {
        return 1e9;
    }
    if (lazy[rootIdx] != 0)
    {
        tree[rootIdx] += (r - l + 1) * lazy[rootIdx];
        if (l != r)
        {
            lazy[2 * rootIdx + 1] += lazy[rootIdx];
            lazy[2 * rootIdx + 2] += lazy[rootIdx];
        }
        lazy[rootIdx] = 0;
    }

    if (x > r or y < l)
    {
        return 1e9;
    }

    if (x <= l and r <= y)
    {
        return tree[rootIdx];
    }

    int mid = (l + r) / 2;
    return min(lazyQueryRangeMinTree(2 * rootIdx + 1, l, mid, x, y),
               lazyQueryRangeMinTree(2 * rootIdx + 2, mid + 1, r, x, y));
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    buildTree(0, 0, N - 1);
    for (int i = 0; i < Q; i++)
    {
        int isPrint;
        cin >> isPrint;
        if (isPrint == 0)
        {
            int p, q, delta;
            cin >> p >> q >> delta;
            lazyUpdateRangeMinTree(0, 0, N - 1, p, q, delta);
        }
        else
        {
            int p, q;
            cin >> p >> q;
            cout << lazyQueryRangeMinTree(0, 0, N - 1, p, q) << "\n";
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
