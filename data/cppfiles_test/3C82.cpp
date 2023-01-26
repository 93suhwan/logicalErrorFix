#include <bits/stdc++.h>
using namespace std;
string s;
int n, dp[10][30][20];
int func(int pos, int rem, int x) {
  if (pos == n) {
    if (rem != 0) return 0;
    return 1;
  }
  if (dp[pos][rem][x] != -1) return dp[pos][rem][x];
  int i, tot, tmp;
  if (pos) {
    if (s[pos] >= '0' && s[pos] <= '9') {
      int hi = rem;
      rem *= 10;
      rem += (s[pos] - '0');
      rem %= 25;
      return dp[pos][hi][x] = func(pos + 1, rem, x);
    }
    if (s[pos] == '_') {
      tot = 0;
      for (i = 0; i < 10; i++) {
        tmp = rem * 10 + i;
        tmp %= 25;
        tot += func(pos + 1, tmp, x);
      }
      return dp[pos][rem][x] = tot;
    }
    if (x > 10) {
      tot = 0;
      for (i = 0; i < 10; i++) {
        tmp = rem * 10 + i;
        tmp %= 25;
        tot += func(pos + 1, tmp, i);
      }
      return dp[pos][rem][x] = tot;
    }
    tmp = rem * 10 + x;
    tmp %= 25;
    return dp[pos][rem][x] = func(pos + 1, tmp, x);
  }
  if (s[pos] == '0') return dp[pos][rem][x] = 0;
  if (s[pos] > '0' && s[pos] <= '9') {
    int hi = rem;
    rem *= 10;
    rem += (s[pos] - '0');
    rem %= 25;
    return dp[pos][hi][x] = func(pos + 1, rem, x);
  }
  if (s[pos] == '_') {
    tot = 0;
    for (i = 1; i < 10; i++) {
      tmp = rem * 10 + i;
      tmp %= 25;
      tot += func(pos + 1, tmp, x);
    }
    return dp[pos][rem][x] = tot;
  }
  tot = 0;
  for (i = 1; i < 10; i++) {
    tmp = rem * 10 + i;
    tmp %= 25;
    tot += func(pos + 1, tmp, i);
  }
  return dp[pos][rem][x] = tot;
}
void solve() {
  memset(dp, -1, sizeof dp);
  cin >> s;
  n = s.size();
  if (s == "0" || s == "_" || s == "X") {
    cout << 1 << endl;
    return;
  }
  cout << func(0, 0, 15) << endl;
}
int main() {
  int t = 1;
  while (t--) solve();
}
