

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void getAns(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (((A[i] - 1) - i) > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }
    }

    long finalCount = 0;
    for (int i = 0; i < A.size(); i++)
    {
        bool isSwaped = false;
        for (int j = 0; j < A.size() - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;

                isSwaped = true;
                finalCount += 1;
            }
        }

        if (!isSwaped)
        {
            cout << finalCount << endl;
            break;
        }
    }
}

void solve()
{
    int N;
    cin >> N;
    vector<int> A;
    for (int j = 0; j < N; j++)
    {
        int val;
        cin >> val;
        A.push_back(val);
    }
    getAns(A);
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
}