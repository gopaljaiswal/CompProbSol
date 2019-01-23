#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#define MAX 50010

using namespace std;

struct node
{
    int prefixSum, sum, suffixSum, maxSum;
};

node tree[4 * 50010];
int arr[50010];

node query(int rootIdx, int l, int r, int x, int y)
{
    node result;
    result.sum = result.prefixSum = INT_MIN;
    result.suffixSum = result.maxSum = INT_MIN;

    if (x > r or y < l)
    {
        return result;
    }
    if (x <= l and r <= y)
    {
        return tree[rootIdx];
    }
    int mid = (l + r) >> 1;
    if (x > mid)
        return query(2 * rootIdx + 2, mid + 1, r, x, y);
    if (y <= mid)
        return query(2 * rootIdx + 1, l, mid, x, y);

    node left = query(2 * rootIdx + 1, l, mid, x, y);
    node right = query(2 * rootIdx + 2, mid + 1, r, x, y);

    result.sum = left.sum + right.sum;
    result.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    result.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);

    result.maxSum =
        max(result.prefixSum,
            max(result.suffixSum,
                max(left.maxSum,
                    max(right.maxSum, left.suffixSum + right.prefixSum))));

    return result;
}

void build(int index, int start, int end)
{
    if (start == end)
    {
        tree[index].sum = arr[start];
        tree[index].prefixSum = arr[start];
        tree[index].suffixSum = arr[start];
        tree[index].maxSum = arr[start];
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * index + 1, start, mid);
        build(2 * index + 2, mid + 1, end);

        tree[index].sum = tree[2 * index + 1].sum + tree[2 * index + 2].sum;

        tree[index].prefixSum =
            max(tree[2 * index + 1].prefixSum,
                tree[2 * index + 1].sum + tree[2 * index + 2].prefixSum);

        tree[index].suffixSum =
            max(tree[2 * index + 2].suffixSum,
                tree[2 * index + 2].sum + tree[2 * index + 1].suffixSum);

        tree[index].maxSum = max(tree[index].prefixSum,
                                 max(tree[index].suffixSum,
                                     max(tree[2 * index + 1].maxSum,
                                         max(tree[2 * index + 2].maxSum,
                                             tree[2 * index + 1].suffixSum +
                                                 tree[2 * index + 2].prefixSum))));
    }
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
    build(0, 0, N - 1);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << query(0, 0, N - 1, x - 1, y - 1).maxSum << "\n";
    }
}

int main()
{
    solve();
    return 0;
}