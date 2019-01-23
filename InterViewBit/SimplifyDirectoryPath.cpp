
#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<char> c)
{
    while (!c.empty())
    {
        std::cout << c.top();
        c.pop();
    }
}

void backStak(stack<char> s)
{
    int count = 0;
    while (!s.empty())
    {
        if (count == 2)
        {
            break;
        }
        if (s.top() == '/')
        {
            count++;
        }
        s.pop();
    }
}

void simplifyPath(string A)
{
    char token = strtok(A, "/");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }

    stack<char> s;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '.' & A[i + 1] == '.')
        {
            backStak(s);
        }
        else if (A[i] != '.')
        {
            s.push(A[i]);
        }
    }
    print_stack(s);
}

void solve()
{
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        simplifyPath(s);
    }
}

int main()
{

    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);

    solve();
    return 0;
}