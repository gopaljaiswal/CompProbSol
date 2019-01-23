#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include "limits.h"
#include "unordered_map"
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector< vi > vii;
typedef pair<int, int> pii;
#define FF first
#define SS second
#define pb(v) push_back(v)
#define mp(x,y) make_pair(x, y)
// #define min(a, b) (a>b?b:a)
// #define max(a, b) (a>b?a:b)
 
#define s(n) scanf("%d",&n)
#define rep(i,start,end) for(int i = start;i<end;i++)
using namespace std;

void solve() {
    int tt;
    s(tt); // tt = in.nextInt();
    cin >> tt; // tt = in.nextInt();

    string A;
    cin >> A; // A = in.next();

    cout << A << '\n';

    rep(i,0,10) {
        cout << i << ' ';
    }
    cout << '\n';

}
 
int main(){
	#ifndef ONLINE_JUDGE
        freopen("tourist.txt", "r", stdin);
        freopen("tourist-res.out", "w", stdout);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    clock_t beg = clock();
    solve();
    clock_t end = clock();
    fprintf(stderr, "%.3f sec\n", double(end - beg) / CLOCKS_PER_SEC);
} 
