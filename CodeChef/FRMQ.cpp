//Chef and Array
//FRMQ

#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define ll long long int
const int MAX = 1e5;

vector<int> tree(4 * MAX + 5);

int query(vector<int> &A, int rootIdx, int L, int R, int X, int Y)
{
    if (Y < L or X > R or Y < X)
    {
        return 0;
    }
    if (X <= L and R <= Y)
    {
        return tree[rootIdx];
    }
    int mid = (L + R) >> 1;
    int left_ans =query(A, (2 * rootIdx + 1), L, mid, X, Y);
    int right_ans = query(A, (2 * rootIdx + 2), mid + 1, R, X, Y);
    //cout << rootIdx  << ' ' << L << ' ' << R << ' ' << left_ans << ' ' << right_ans << '\n';
    return max(left_ans, right_ans);
}

// update
void update(vector<int> &A, int rootIdx, int L, int R, int idx, int value)
{
    if (L == R)
    {
        tree[rootIdx] = value;
        A[L] = value;
        return;
    }
    int mid = (L + R) / 2;
    if (mid < idx)
    {
        update(A, (2 * rootIdx + 2), mid + 1, R, idx, value);
    }
    else
    {
        update(A, (2 * rootIdx + 1), L, mid, idx, value);
    }

    tree[rootIdx] = max(tree[2 * rootIdx + 1], tree[2 * rootIdx + 2]);
}

// build tree 
void buidTree(vector<int> &A, int rootIdx, int L, int R)
{
    if (L == R)
    {
        tree[rootIdx] = A[L];
        return;
    }
    int mid = (L + R) / 2;
    buidTree(A, 2 * rootIdx + 1, L, mid);
    buidTree(A, 2 * rootIdx + 2, mid + 1, R);

    tree[rootIdx] = max(tree[2 * rootIdx + 1], tree[2 * rootIdx + 2]);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        A.push_back(c);
    }

    int m, x, y;
    cin >> m >> x >> y;
    buidTree(A,0,0,n-1);
    ll sum= query(A,0,0,n-1,min(x, y),max(x, y));
    // cout << x  << ' ' << y << '\n';
    for(int i=1;i<m;i++){
        x = (x + 7)%(n-1);
        y = (y+11) %n;  
        // cout << x  << ' ' << y << '\n';
        sum+= query(A,0,0,n-1,min(x, y),max(x, y));
    }

    cout << sum << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    // freopen("out_wa.out", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
}
