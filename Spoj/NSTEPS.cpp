

#include <iostream>

using namespace std;

int getRes(int a, int b)
{
    if (a == 0 && b == 0)
    {
        return 0;
    }
    if (a == 1 && b == 1)
    {
        return 1;
    }

    if (a == b || a == b + 2)
    {
        if (a % 2 == 0)
        {
            return a + b;
        }
        else
        {
            return a + b - 1;
        }
    }
    return -1;
}

void solve()
{
    int N;
    cin >> N;
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        int ans = getRes(a, b);
        if (ans == -1)
        {
            cout << "No Number";
        }
        else
        {
            cout << ans;
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