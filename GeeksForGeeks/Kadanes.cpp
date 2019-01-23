#include <iostream>
#include <vector>
using namespace std;

int getRes(vector<int> v)
{
    bool flag = false;
    int min = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            flag = true;
            break;
        }
        if (v[i] > min)
        {
            min = v[i];
        }
    }
    if (flag == false)
    {
        return min;
    }

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        //cout << v[i] << endl;
        if (sum + v[i] > 0)
        {
            sum += v[i];
            ans = max(ans, sum);
            //cout << ans;
        }
        else
        {
            sum = 0;
        }
    }
    return ans;
}

void solve()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        cout << getRes(v) << endl;
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