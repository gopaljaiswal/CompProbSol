

#include <iostream>

using namespace std;

int eulerTotient(int n)
{
    float result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n = n / i;
            }
            result *= 1.0 - (1.0 / (float)i);
        }
    }

    if (n > 1)
    {
        result *= 1.0 - (1.0 / (float)n);
    }
    return (int)result;
}

void solve()
{
    int N;
    cin >> N;
    while (N--)
    {
        int n;
        cin >> n;
        cout << eulerTotient(n) << "\n";
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