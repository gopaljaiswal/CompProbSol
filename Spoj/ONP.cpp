
#include <iostream>
#include <stack>
#define MAX 400

using namespace std;

void getAns(string A)
{
    string B;
    stack<char> s;
    int count = 0;
    int i = 0;

    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
        {
            count++;
        }
        else if (A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/' || A[i] == '^')
        {
            s.push(A[i]);
        }
        else if (A[i] == ')')
        {
            count--;
            B = B + "" + s.top();
            s.pop();
        }
        else
        {
            B = B + "" + A[i];
        }
    }

    cout << B;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        string A;
        cin >> A;
        getAns(A);
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
