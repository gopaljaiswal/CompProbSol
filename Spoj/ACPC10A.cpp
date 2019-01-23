#include <iostream>

using namespace std;

void getAns(int a, int b, int c)
{
    if (b - a == c - b)
    {
        cout << "AP " << c + (b - a) << "\n";
    }
    else if (b / a == c / b)
    {
        cout << "GP " << c * (b / a) << "\n";
    }
}

void solve()
{

    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
        {
            break;
        }
        getAns(a, b, c);
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}