
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

long long getAns(string s) {

  int len = s.length();
  long long dp[len];

  for (int j = 0; j < len + 1; j++) {
    dp[j] = 0;
  }

  dp[0] = 1;
  for (int i = 1; i < len; i++) {

    long num = (s[i - 1] - '0') * 10;
    num += s[i] - '0';

    if (s[i] - '0') {
      dp[i] = dp[i - 1];
    }

    if (num > 9 && num < 27) {
      dp[i] += dp[(i - 2) > 0 ? (i - 2) : 0];
    }
  }
  return dp[len - 1];
}

void solve() {
  while (true) {
    string s;
    cin >> s;
    if (s == "0") {
      break;
    }
    cout << getAns(s) << "\n";
  }
}

int main() {

  freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
          "input.txt",
          "r", stdin);
  freopen("/Users/gopaljaiswal/project/frameworks/Anaconda_python/Comp_Prog/"
          "output.txt",
          "w", stdout);

  solve();
  return 0;
}