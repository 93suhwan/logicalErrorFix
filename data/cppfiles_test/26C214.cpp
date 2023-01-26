#include <bits/stdc++.h>
using namespace std;
int solve(string& s, int i, int dp[][2]) {
  int n = s.size();
  if (i == n) {
    return 10;
  }
  int player = 1 - i % 2;
  if (s[i - 1] == '0') {
    dp[i][player] = dp[i - 1][player];
  } else if (s[i - 1] == '1') {
    dp[i][player] = dp[i - 1][player] + 1;
  }
  dp[i][1 - player] = dp[i - 1][1 - player];
  int diff = dp[i][player] - dp[i][1 - player];
  int delta = diff > 0 ? 0 : 1;
  if (2 * abs(diff) + i > (11 - delta)) {
    return i;
  }
  return solve(s, i + 1, dp);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1][2];
    dp[0][0] = 0, dp[0][1] = 0;
    string s1 = s, s2 = s;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && s[i] == '?') {
        s1[i] = '1';
        s2[i] = '0';
      }
      if (i % 2 != 0 && s[i] == '?') {
        s1[i] = '0';
        s2[i] = '1';
      }
    }
    int z1 = solve(s1, 1, dp);
    int z2 = solve(s2, 1, dp);
    int z = min(z1, z2);
    cout << z << endl;
  }
  return 0;
}
