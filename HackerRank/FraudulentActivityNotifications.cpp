
#include <iostream>
#include <vector>

using namespace std;
vector<int> A;
vector<int> dayArr;

double getMedian(int i, int j, int d, int ak) 
{
    double ans;
    int mid = (dayArr.size() - 1) / 2;
    if (d % 2 == 0)
    {
        ans = (dayArr[mid] + dayArr[mid + 1]) / (double)2.0;
    }
    ans = (double)dayArr[mid];


    return ans;
}

void solve()
{
    int n, d, counter = 0;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
        if (i < d)
        {
            dayArr.push_back(a);
        }
    }
    sort(dayArr.begin(), dayArr.end());

    int i = 0;
    int j = d - 1;
    for (int k = d; k < n; k++)
    {
        double median = getMedian(i, j, d, A[k]);
        //cout << i << " " << j << " " << median << "\n";
        if (A[k] >= 2 * median)
        {
            counter = counter + 1;
        }

        i = i + 1;
        j = j + 1;
    }
    cout << counter;
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