#include <iostream>
#include <string>

using namespace std;

void solve()
{
    int T;
    string s;
    cin >> T;
    while (T--)
    {
        getline(cin, s);
        int N;
        cin >> N;
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            long long int a;
            cin >> a;
            sum += a;
            sum = sum % N;
        }
        if (sum % N == 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
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