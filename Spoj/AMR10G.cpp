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

void getRes(vector<int> vc, int N, int K)
{
    sort(vc.begin(), vc.end());
    int minDiff = INT_MAX;
    for (int i = 0; i <= N - K; i++)
    {
        if (vc[i + K - 1] - vc[i] < minDiff)
        {
            minDiff = vc[i + K - 1] - vc[i];
        }
    }
    cout << minDiff;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        vector<int> vc;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            vc.push_back(a);
        }
        getRes(vc, N, K);
        cout << "\n";
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
