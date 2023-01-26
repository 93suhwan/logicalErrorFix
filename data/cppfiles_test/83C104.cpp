#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const double PI = acos(-1.0);
int lcp[N][N];
char s[N];
int dp[N];
void solve() {
  memset(dp, 0, sizeof dp);
  int n;
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      lcp[i][j] = 0;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      if (s[i] != s[j])
        lcp[i][j] = 0;
      else
        lcp[i][j] = lcp[i + 1][j + 1] + (s[i] == s[j]);
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = n - i + 1;
    for (int j = 1; j < i; j++) {
      int len = lcp[i][j];
      if (s[i + len] > s[j + len]) {
        dp[i] = max(dp[i], dp[j] + n - (i + len) + 1);
      }
    }
    res = max(res, dp[i]);
  }
  printf("%d\n", res);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
