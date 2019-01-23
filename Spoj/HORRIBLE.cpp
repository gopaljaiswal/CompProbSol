#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

// ll tree[4000040] = {0};
// ll lazy[400040] = {0};

vector<ll> tree(4000040, 0);
vector<ll> lazy(4000040, 0);

// lazy propogation
void lazyUpdateRangeMinTree(int rootIdx, int l, int r, int x, int y, ll delta)
{
    if (lazy[rootIdx] != 0)
    {
        tree[rootIdx] += (r - l + 1) * lazy[rootIdx];
        if (l != r)
        {
            lazy[2 * rootIdx] += lazy[rootIdx];
            lazy[2 * rootIdx + 1] += lazy[rootIdx];
        }
        lazy[rootIdx] = 0;
    }

    if (x > r or y < l or l > r)
    {
        return;
    }
    if (x <= l and r <= y)
    {
        tree[rootIdx] += (r - l + 1) * delta;
        if (l != r)
        {
            lazy[2 * rootIdx] += delta;
            lazy[2 * rootIdx + 1] += delta;
        }
        return;
    }
    int mid = (l + r) >> 1;
    lazyUpdateRangeMinTree(2 * rootIdx, l, mid, x, y, delta);
    lazyUpdateRangeMinTree(2 * rootIdx + 1, mid + 1, r, x, y, delta);

    tree[rootIdx] = tree[2 * rootIdx] + tree[2 * rootIdx + 1];
}

void buildTree(int rootIdx, int l, int r)
{
    if (l == r)
    {
        tree[rootIdx] = 0;
    }
    else
    {
        int mid = (l + r) / 2;
        buildTree(2 * rootIdx, l, mid);
        buildTree(2 * rootIdx + 1, mid + 1, r);
        tree[rootIdx] = tree[2 * rootIdx] + tree[2 * rootIdx + 1];
    }
}

ll lazyQueryRangeMinTree(int rootIdx, int l, int r, int x, int y)
{

    if (lazy[rootIdx] != 0)
    {
        tree[rootIdx] += (r - l + 1) * lazy[rootIdx];
        if (l != r)
        {
            lazy[2 * rootIdx] += lazy[rootIdx];
            lazy[2 * rootIdx + 1] += lazy[rootIdx];
        }
        lazy[rootIdx] = 0;
    }

    if (x > r or y < l or l > r)
    {
        return 0;
    }

    if (x <= l and r <= y)
    {
        return tree[rootIdx];
    }

    int mid = (l + r) / 2;
    return lazyQueryRangeMinTree(2 * rootIdx, l, mid, x, y) +
           lazyQueryRangeMinTree(2 * rootIdx + 1, mid + 1, r, x, y);
}
void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 4000040; i++)
        {
            tree[i] = 0;
            lazy[i] = 0;
        }
        // memset(tree, 0, sizeof(tree));
        // memset(lazy, 0, sizeof(lazy));
        int N, C;
        cin >> N >> C;
        buildTree(1, 0, N - 1);
        while (C--)
        {
            int isPrint;
            cin >> isPrint;
            if (isPrint == 0)
            {
                int p, q;
                ll v;
                cin >> p >> q >> v;
                // cout << p << " " << q << " " << v << "\n";
                lazyUpdateRangeMinTree(1, 0, N - 1, p - 1, q - 1, v);
            }
            else
            {
                int p, q;
                cin >> p >> q;
                cout << lazyQueryRangeMinTree(1, 0, N - 1, p - 1, q - 1) << "\n";
            }
            // cout << "\n";

            // for (int i = 0; i < 15; i++)
            // {
            //     cout << tree[i] << " ";
            // }
            // cout << "\n";
            // for (int i = 0; i < 15; i++)
            // {
            //     cout << lazy[i] << " ";
            // }
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