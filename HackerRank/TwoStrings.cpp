

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

void solve()
{
    int t;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        string a, b;
        cin >> a;
        cin >> b;
        map<char, int> m;

        int i = 0;
        while (i < a.length())
        {
            m[a.at(i)] = 1;
            i = i + 1;
        }

        bool flag = false;
        int j = 0;
        while (j < b.length())
        {
            if (m.find(b.at(j)) != m.end())
            {
                flag = true;
                //cout << b.at(j) << endl;
            }
            j = j + 1;
        }

        if (flag == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
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