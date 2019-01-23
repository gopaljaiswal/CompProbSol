#include <iostream>
typedef long long int ll;

using namespace std;

ll maxLL(ll a, ll b) { return a > b ? a : b; }

ll getAns(ll A[], ll dp[], int N)
{
    if (N == 1)
    {
        return A[0];
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i] = maxLL((i > 1) ? dp[i - 1] : 0, (i > 2 ? dp[i - 2] : 0) + A[i - 1]);
    }
    return dp[N];
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            cout << "Case " << t << ":  "
                 << "0"
                 << "\n";
            continue;
        }
        ll A[N], dp[N + 1];
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            A[i] = a;
            dp[i] = 0;
        }
        dp[N] = 0;
        cout << "Case " << t << ":  " << getAns(A, dp, N) << "\n";
    }
}

int main()
{
    solve();
    return 0;
}