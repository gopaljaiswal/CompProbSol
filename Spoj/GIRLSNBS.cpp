#include <cmath>
#include <iostream>

using namespace std;

int getRes(int G, int B)
{
    if (G == 0)
    {
        return B;
    }
    else if (B == 0)
    {
        return G;
    }
    else if (G == B)
    {
        return 1;
    }
    else if (G > B)
    {
        // cout << " test " << G << " " << B << " " << G * 1.0 / (B + 1) << "\n";
        return ceil(G * 1.0 / (B + 1));
    }
    return ceil(B * 1.0 / (G + 1));
}

void solve()
{
    while (true)
    {
        int G, B;
        cin >> G >> B;
        if (G == -1 && B == -1)
        {
            break;
        }
        cout << getRes(G, B) << "\n";
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