
#include <iostream>
#include <map>
#include <string>

using namespace std;
map<int, string> mp;

// ome way to solve of N=1000
// void prepareMap()
// {
//     int count = 1;
//     mp[count] = 1 / 1;
//     for (int i = 2; i <= N; i++)
//     {
//         for (int j = 1; j < i; j++)
//         {
//             int nom = j;
//             int denom = i - j;
//             mp[count++] = to_string(nom) + "/" + to_string(denom);
//         }
//     }
// }

void getRes(int a)
{
    int sum = 0;
    int i = 1;
    for (int i = 1; true; i++)
    {
        sum += i;
        if (sum >= a)
        {
            int diff = sum - a;
            int nomi = diff + 1;
            int domi = i - diff;

            if (i % 2 != 0)
            {
                cout << "TERM " + to_string(a) + " IS " + to_string(nomi) + "/" +
                            to_string(domi);
            }
            else
            {
                cout << "TERM " + to_string(a) + " IS " + to_string(domi) + "/" +
                            to_string(nomi);
            }
            break;
        }
    }
}

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        getRes(N);
        cout << "\n";
    }
}

int main()
{
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "input.txt",
            "r", stdin);
    freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
            "output.txt",
            "w", stdout);

    solve();
    return 0;
}