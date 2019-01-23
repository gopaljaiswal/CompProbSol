#include <iostream>
#include <math.h>

using namespace std;

int lenghtOfNo(int no)
{
    int len = to_string(no).length();
    return len;
}

int reverse(int a, int j, int len, int tmp)
{
    if (len == j)
    {
        return tmp * 10 + a;
    }

    int rem = a % 10;
    a = a / 10;
    tmp = tmp * 10 + rem;

    return reverse(a, j + 1, len, tmp);
}

void getAns(int a, int b)
{
    int tmp = 0;
    int lenA = lenghtOfNo(a);
    int revA = reverse(a, 0, lenA - 1, tmp);

    int tmp1 = 0;
    int lenB = lenghtOfNo(b);
    int revB = reverse(b, 0, lenB - 1, tmp1);

    int sum = revA + revB;

    // cout << revA << "\n";
    // cout << revB << "\n";
    // cout << sum << "\n";

    int tmp2 = 0;
    int lenSum = lenghtOfNo(sum);
    int revSum = reverse(sum, 0, lenSum - 1, tmp2);

    cout << revSum << "\n";
}

void solve()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        getAns(a, b);
    }
}

int main()
{
#ifndef ONLINE_JUDGEÎ
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/input.txt", "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
    return 0;
}
