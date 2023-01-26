#include <bits/stdc++.h>
using namespace std;
int solve(string& s) {
  if (s[0] == '?') {
    s[0] = '0';
    int t1 = solve(s);
    s[0] = '1';
    int t2 = solve(s);
    return min(t1, t2);
  }
  int n = s.size();
  int dp[n + 1][2];
  dp[0][0] = 0, dp[0][1] = 0;
  for (int i = 1; i < n + 1; i++) {
    int player = 1 - i % 2;
    if (s[i - 1] == '0') {
      dp[i][player] = dp[i - 1][player];
    } else if (s[i - 1] == '1') {
      dp[i][player] = dp[i - 1][player] + 1;
    } else {
      if (dp[i - 1][player] > dp[i - 1][1 - player]) {
        dp[i][player] = dp[i - 1][player] + 1;
      } else {
        dp[i][player] = dp[i - 1][player];
      }
    }
    dp[i][1 - player] = dp[i - 1][1 - player];
    int diff = dp[i][player] - dp[i][1 - player];
    int delta = diff > 0 ? 0 : 1;
    if (2 * abs(diff) + i > (11 - delta)) {
      return i;
    }
  }
  return 10;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int z = solve(s);
    cout << z << endl;
  }
  return 0;
}
