

#include <iostream>
#include <vector>
using namespace std;

vector<int> A;
int B[1000006];

void countingSort()
{
    int size = *(&B + 1) - B;
    for (int i = 1; i < size; i++)
    {
        B[i] = B[i - 1] + B[i];
    }

    int counter[size];
    counter[0] = 0;
    for (int i = 1; i < size; i++)
    {
        counter[i] = B[i - 1];
    }

    int newA[A.size()];
    for (int i = 0; i < A.size(); i++)
    
    {
        newA[counter[A[i]]] = A[i];
        counter[A[i]] = counter[A[i]] + 1;
    }

    for (int i = 0; i < A.size(); i++)
    {
        //cout << i << " " <<
        cout << newA[i] << "\n";
    }
}

void solve()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
        //cout << a << " ";
        B[a] = B[a] + 1;
    }
    countingSort();
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