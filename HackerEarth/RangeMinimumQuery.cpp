#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;
vector<int> tree(MAX);

void update(int A[], int rootIdx, int l, int r, int idx, int val)
{
    if (l == r)
    {
        tree[rootIdx] = val;
        A[l] = val;
    }
    else
    {
        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(A, 2 * rootIdx + 1, l, mid, idx, val);
        }
        else
        {
            update(A, 2 * rootIdx + 2, mid + 1, r, idx, val);
        }
        tree[rootIdx] = min(tree[2 * rootIdx + 1], tree[2 * rootIdx + 2]);
    }
}

int query(int rootIdx, int l, int r, int x, int y)
{
    if (x > r or y < l)
    {
        // cout << rootIdx << ' ' << l << ' ' << r << ' ' << " " << x << " " << y
        //      << '\n';
        return INT_MAX;
    }
    if (x <= l and r <= y)
    {
        // cout << rootIdx << ' ' << l << ' ' << r << ' ' << " " << x << " " << y
        //      << '\n';
        return tree[rootIdx];
    }
    int mid = (l + r) / 2;
    int left_ans = query((2 * rootIdx + 1), l, mid, x, y);
    int right_ans = query((2 * rootIdx + 2), mid + 1, r, x, y);
    return min(left_ans, right_ans);
}

void buildTree(int A[], int rootIdx, int l, int r)
{
    if (l == r)
    {
        tree[rootIdx] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(A, (2 * rootIdx + 1), l, mid);
    buildTree(A, (2 * rootIdx + 2), mid + 1, r);
    tree[rootIdx] = min(tree[2 * rootIdx + 1], tree[2 * rootIdx + 2]);
}

void solve()
{
    int N, Q;
    cin >> N >> Q;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A[i] = a;
    }
    buildTree(A, 0, 0, N - 1);
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << tree[i] << " ";
    // }
    //    cout << "\n";
    for (int i = 0; i < Q; i++)
    {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'u')
        {
            update(A, 0, 0, N - 1, x - 1, y);
            // for (int i = 0; i < 9; i++)
            // {
            //     cout << tree[i] << " ";
            // }
            // cout << "\n";
        }
        else
        {
            cout << query(0, 0, N - 1, x - 1, y - 1) << "\n";
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