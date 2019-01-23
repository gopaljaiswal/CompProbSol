#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int i, n, b, c, d;
    vector<int> a, ans;
    string s;
    while (cin >> s)
    {
        if (!(s[0] >= '0' && s[0] <= '9'))
            break;
        if (s == "1")
        {
            cout << 1 << endl;
            continue;
        }
        if (s == "0")
        {
            cout << 0 << endl;
            continue;
        }
        ans.clear();
        a.clear();
        for (i = s.size() - 1; i >= 0; --i)
            a.push_back(s[i] - '0');
        int rem = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            b = a[i] * 2 + rem;
            rem = b / 10;
            b = b % 10;
            ans.push_back(b);
        }
        if (rem != 0)
            ans.push_back(rem);
        ans[0] -= 2;
        if (ans[0] < 0)
        {
            ans[0] += 10;
            i = 1;
            while (ans[i] == 0)
            {
                ans[i] = 9;
                ++i;
            }

            ans[i]--;
        }
        if (ans[ans.size() - 1] == 0)
            ans.pop_back();
        for (i = ans.size() - 1; i >= 0; --i)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}