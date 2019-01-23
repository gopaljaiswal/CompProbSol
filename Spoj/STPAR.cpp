
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void getRes(vector<int> v, int N)
{
     stack<int> lane; int need = 1;
bool state = true;
for (int i = 0; i < order.size(); i++) {
	while (!lane.empty() && lane.top() == need) {
		need++;
		lane.pop();
	}
	if (order[i] == need) {
		need++;
	} else if (!lane.empty() && lane.top() < order[i]) {
		state = false;
		break;
	} else {
		lane.push(order[i]);
	}
}

if (state) cout << "yes" << "\n";
else cout << "no" << "\n";
}

void solve()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        getRes(v, N);
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