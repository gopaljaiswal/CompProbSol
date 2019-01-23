

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

void getRes(string a)
{
    vector<int> A;

    int numOfEven = 0;
    int minOddDig = INT_MAX;
    int minEvenDig = INT_MAX;
    string::iterator it;
    for (it = a.begin(); it != a.end(); it++)
    {
        int rem = (int)(*it) - (int)'0';

        if (rem % 2 == 0)
        {
            numOfEven = numOfEven + 1;
            if (rem < minEvenDig)
            {
                minEvenDig = rem;
            }
        }
        else
        {
            if (rem < minOddDig)
            {
                minOddDig = rem;
            }
        }
        A.push_back(rem);
    }

    //cout << numOfEven << " " << minEvenDig << " " << minOddDig;
    sort(A.begin(), A.end());

    if (numOfEven > 0)
    {
        vector<int> right, left;
        int counter = 0;

        for (int i = A.size() - 1; i >= 0; i--)
        {
            if (A[i] > minEvenDig)
            {
                right.push_back(A[i]);
            }
            else
            {
                if (counter > 0)
                {
                    left.push_back(A[i]);
                }
                counter += 1;
            }
        }
        left.push_back(minEvenDig);

        for (int i = 0; i < right.size(); i++)
        {
            cout << right[i];
        }
        for (int i = 0; i < left.size(); i++)
        {
            cout << left[i];
        }
    }
    else
    {
        for (int i = A.size() - 1; i >= 0; i--)
        {
            cout << A[i];
        }
    }
    cout << "\n";
}

void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        getRes(a);
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
