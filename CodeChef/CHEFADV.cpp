
#include <iostream>

using namespace std;

void getRes(int N, int M, int X, int Y)
{

    if (((N - 1) % X == 0 and (M - 1) % Y == 0) or (N - 2 >= 0 and M - 2 >= 0 and (N - 2) % X == 0 and (M - 2) % Y == 0))
        cout << "Chefirnemo"
             << "\n";
    else
        cout << "Pofik"
             << "\n";

    // N = N - 1;
    // M = M - 1;

    // if ((N == 1 && M == 1) && (N == 0 && M == 0))
    // {
    //     cout << "Chefirnemo"
    //          << "\n";
    //     return;
    // }

    // // while (N - N1 >= X)
    // // {
    // //     N1 = N1 + X;
    // // }

    // // while (M - M1 >= Y)
    // // {
    // //     M1 = M1 + Y;
    // // }

    int diffN = N % X;
    int diffM = M % Y;

    //cout << N1 << "  " << M1 << "\n";
    //cout << diffN << "  " << diffM;

    if ((diffN == 0 && diffM == 0) || (diffN == 1 && diffM == 1))
    {
        cout << "Chefirnemo"
             << "\n";
    }
    else
    {
        cout << "Pofik"
             << "\n";
    }
}

void solve()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M, X, Y;
        cin >> N >> M >> X >> Y;
        getRes(N, M, X, Y);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
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