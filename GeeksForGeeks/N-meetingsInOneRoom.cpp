#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int start;
    int finish;
    int idx;
};

bool activityCompare(Activity a1, Activity a2)
{
    return (a1.finish < a2.finish);
}

void optimalActivity(Activity A[], int N)
{

    sort(A, A + N, activityCompare);

    int i = 0;
    cout << (A[i].idx) << " ";
    for (int j = 1; j < N; j++)
    {
        if (A[j].start >= A[i].finish)
        {
            cout << (A[j].idx) << " ";
            i = j;
        }
    }
    cout << "\n";
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        Activity A[N];
        for (int i = 0; i < N; i++)
        {
            int s;
            cin >> s;
            A[i].start = s;
            A[i].idx = i + 1;
        }
        for (int i = 0; i < N; i++)
        {
            int f;
            cin >> f;
            A[i].finish = f;
        }
        optimalActivity(A, N);
    }

    return 0;
}