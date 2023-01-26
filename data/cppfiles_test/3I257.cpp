#include <bits/stdc++.h>
using namespace std;
const int nax = (int)1e6 + 10;
const int INF = (int)1e9 + 47;
const int MOD = (int)1e9 + 7;
int dp[10][25][10];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  bool all_zero = true;
  for (int i = 0; i < n; i++) all_zero &= (s[i] == '0');
  if (all_zero) {
    cout << 1 << '\n';
    return 0;
  }
  if (s[0] == '0') {
    cout << 0 << '\n';
    return 0;
  }
  if (s == "X" || s == "_") {
    cout << 1 << '\n';
    return 0;
  }
  bool have_x = false;
  for (int i = 0; i < n; i++) {
    have_x |= (s[i] == 'X');
  }
  for (int x = 0; x < 10; x++) {
    if (s[0] != 'X' && s[0] != '_') {
      dp[0][s[0] - '0'][x] = 1;
    } else if (s[0] == 'X') {
      if (x == 0) continue;
      dp[0][x][x] = 1;
    } else if (s[0] == '_') {
      for (int i = 1; i < 10; i++) dp[0][i][x] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int rem = 0; rem < 25; rem++) {
      for (int x = 0; x < 10; x++) {
        if (s[i] != 'X' && s[i] != '_') {
          dp[i][(rem * 10 + (s[i] - '0')) % 25][x] += dp[i - 1][rem][x];
        } else if (s[i] == 'X') {
          dp[i][(rem * 10 + x) % 25][x] += dp[i - 1][rem][x];
        } else {
          for (int dig = 0; dig < 10; dig++) {
            dp[i][(rem * 10 + dig) % 25][x] += dp[i - 1][rem][x];
          }
        }
      }
    }
  }
  int ans = 0;
  if (have_x) {
    for (int x = 0; x < 10; x++) ans += dp[n - 1][0][x];
  } else
    ans = dp[n - 1][0][0];
  cout << ans << '\n';
}
