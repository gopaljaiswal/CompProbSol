#include <iomanip>
#include <iostream>

using namespace std;

void getAns(int L)
{
    cout << std::setprecision(2) << fixed;
    cout << ((L * L) / (2 * 3.14159)) << "\n";
}

void solve()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        getAns(N);
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