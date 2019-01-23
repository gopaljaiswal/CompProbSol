

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void getRes(vector<string> a, vector<string> b)
{
    unordered_map<string, int> aMap, bMap;
    for (int i = 0; i < a.size(); i++)
    {
        if (aMap.find(a[i]) == aMap.end())
        {
            aMap[a[i]] = 1;
        }
        else
        {
            aMap[a[i]] = aMap[a[i]] + 1;
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (bMap.find(b[i]) == bMap.end())
        {
            bMap[b[i]] = 1;
        }
        else
        {
            bMap[b[i]] = bMap[b[i]] + 1;
        }
    }

    for (int i = 0; i < b.size(); i++)
    {
        if (bMap.find(b[i]) == bMap.end())
        {
            cout << "No" << endl;
            return;
        }

        if (bMap[b[i]] != aMap[b[i]])
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

void solve()
{
    int alen, blen;
    cin >> alen >> blen;
    vector<string> a, b;
    string x;
    for (int i = 0; i < alen; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < blen; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    getRes(a, b);
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