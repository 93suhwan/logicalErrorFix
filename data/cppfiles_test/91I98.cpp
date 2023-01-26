#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int mod = 998244353;
int ad(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int mu(int x, int y) { return 1ll * x * y % mod; }
int n;
int dp[2][MAXN], a[MAXN];
void sol() {
  scanf("%d", &n);
  for (int i = 1; i < MAXN; i++) {
    dp[0][i] = dp[1][i] = 0;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int cur = 0;
  dp[cur][a[n]] = 1;
  int ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    int r;
    for (int j = 1; j <= a[i + 1]; j = r + 1) {
      int v = a[i + 1] / j;
      r = a[i + 1] / (a[i + 1] / j);
      int c = dp[cur][v];
      if (!c) continue;
      int k = (a[i] + v - 1) / v;
      ans = ad(ans, mu(i, mu(c, k - 1)));
      dp[cur ^ 1][a[i] / k] += c;
    }
    dp[cur ^ 1][a[i]]++;
    cur ^= 1;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) sol();
  return 0;
}
