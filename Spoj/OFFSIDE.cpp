#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getAns(vector<int> at, vector<int> df)
{
    sort(at.begin(), at.end());
    sort(df.begin(), df.end());
    if (at[0] >= df[0] and at[0] >= df[1])
    {
        return "N";
    }
    return "Y";
}

void solve()
{
    while (true)
    {
        int A, D;
        cin >> A >> D;
        if (A == 0 and D == 0)
        {
            break;
        }

        vector<int> at, df;
        for (int i = 0; i < A; i++)
        {
            int a;
            cin >> a;
            at.push_back(a);
        }
        for (int i = 0; i < D; i++)
        {
            int b;
            cin >> b;
            df.push_back(b);
        }
        cout << getAns(at, df) << "\n";
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