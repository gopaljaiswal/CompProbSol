

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct Item
{
    int val, wt;
    void update(int val, int wt)
    {
        this->val = val;
        this->wt = wt;
    }
};

// Comparison function to sort Item according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.val / a.wt;
    double r2 = (double)b.val / b.wt;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].val << "  " << arr[i].wt << endl;
    // }
    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (curWeight + arr[i].wt <= W)
        {
            curWeight += arr[i].wt;
            finalvalue += arr[i].val;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].val * ((double)remain / arr[i].wt);
            break;
        }
    }
    return finalvalue;
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N, W;
        cin >> N;
        cin >> W;
        //Item *arr = (Item *)malloc(sizeof(Item) * N);
        Item arr[N];
        for (int i = 0; i < N; i++)
        {
            int val, w;
            cin >> val;
            cin >> w;
            arr[i].update(val, w);
        }
        cout << setprecision(2) << fixed << fractionalKnapsack(W, arr, N) << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}