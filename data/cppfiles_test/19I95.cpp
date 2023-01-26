#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
int read() {
  int x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 10000, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (ch<48 | ch> 57) {
    if (ch == '-') f = -1;
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 10000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  while (ch >= 48 && ch <= 57) {
    x = x * 10 + ch - 48;
    ch = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 10000, stdin), p1 == p2)
              ? EOF
              : *p1++);
  }
  return x * f;
}
const int maxn = 2105;
int n;
int dp[maxn * 5][maxn];
int a[maxn];
void init() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= maxn - 1; j++) dp[i][j] = 0x3f3f3f3f;
}
void solve() {
  n = read();
  init();
  for (int i = 1; i <= n; i++) a[i] = read();
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int k = 0; k <= 2000; k++) {
      if (dp[i - 1][k] == 0x3f3f3f3f) continue;
      if (k + a[i] <= 2000)
        dp[i][k + a[i]] = min(dp[i][k + a[i]], max(dp[i - 1][k], k + a[i]));
      if (k - a[i] >= 0)
        dp[i][k - a[i]] = min(dp[i][k - a[i]], dp[i - 1][k]);
      else
        dp[i][0] = min(dp[i][0], dp[i - 1][k] + a[i] - k);
    }
  int mn = 0x3f3f3f3f;
  for (int i = 0; i <= 2000; i++) mn = min(mn, dp[n][i]);
  cout << mn << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  int t = read();
  while (t--) {
    solve();
  }
  return 0;
}
