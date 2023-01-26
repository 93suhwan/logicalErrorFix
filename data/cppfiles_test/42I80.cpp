#include <bits/stdc++.h>
int ft[200000 * 2];
void update(int i, int n, int x) {
  while (i < n) {
    ft[i] = (ft[i] + x) % 1000000007;
    i |= i + 1;
  }
}
int query(int i) {
  int x = 0;
  while (i >= 0) {
    x = (x + ft[i]) % 1000000007;
    i &= i + 1, i--;
  }
  return x;
}
int main() {
  static int ll[200000 * 2], rr[200000], dp[200000 * 2];
  static char marked[200000];
  int n, k, i, l, r, ans;
  scanf("%d", &n);
  memset(ll, -1, n * 2 * sizeof *ll);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &l, &r), l--, r--;
    rr[i] = r, ll[r] = l;
  }
  for (r = 0; r < n * 2; r++)
    if (ll[r] != -1) {
      dp[r] = (1 + query(n * 2 - 1 - ll[r])) % 1000000007;
      update(n * 2 - 1 - ll[r], n * 2, dp[r]);
    }
  scanf("%d", &k);
  while (k--) {
    scanf("%d", &i), i--;
    marked[rr[i]] = 1;
  }
  ans = 0;
  for (r = 0; r < n * 2; r++) ans = (ans + dp[r]) % 1000000007;
  for (r = n * 2 - 1, l = 0; r >= 0; r--)
    if (ll[r] >= l) {
      if (!marked[r])
        ans = (ans - dp[r]) % 1000000007;
      else
        l = ll[r];
    }
  printf("%d\n", ans);
  return 0;
}
