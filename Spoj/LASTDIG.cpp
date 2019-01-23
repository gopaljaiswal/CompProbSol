#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

int getRes(long a, long b)
{
    if (b == 0)
    {
        b = 4;
    }
    
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans = (ans * a) % 10;
    }
    return ans % 10;
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long int a, b;
        cin >> a >> b;
        if (b == 0)
        {
            cout << "1";
        }
        else
        {
            cout << getRes(a % 10, b % 4);
        }
        cout << "\n";
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}