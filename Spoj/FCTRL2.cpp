#include <iostream>

#define MAX 200

using namespace std;

int multiply(int A[], int no, int res_size)
{
    int carry = 0;
    for (int i = 0; i < res_size; i++)
    {
        int prod = A[i] * no + carry;
        A[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry > 0)
    {
        A[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

void fact(int N)
{
    int A[MAX];
    A[0] = 1;
    int res_size = 1;
    int carry = 0;
    for (int i = 2; i <= N; i++)
    {
        res_size = multiply(A, i, res_size);
    }

    for (int i = res_size - 1; i >= 0; i--)
    {
        cout << A[i] << "";
    }
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        fact(N);
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