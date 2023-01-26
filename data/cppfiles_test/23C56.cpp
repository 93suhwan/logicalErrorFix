#include <bits/stdc++.h>
using namespace std;
long long int a[4005];
long long int dp[4005][4005];
int m;
int dfs(int l, int r) {
  if (l > r) return 0;
  long long int mi = 1e18;
  long long int root = -1;
  for (int i = l; i <= r; i++) {
    if (a[i] < mi) {
      mi = a[i];
      root = i;
    }
  }
  int root_l = dfs(l, root - 1);
  int root_r = dfs(root + 1, r);
  int sz = r - l + 1;
  for (int i = 0; i <= sz; i++) {
    int sz_l = root - l;
    int sz_r = r - root;
    dp[root][i] = -1e18;
    for (int j = max(0, i - sz_r - 1); j <= min(sz_l, i); j++) {
      dp[root][i] = max(dp[root][i], dp[root_l][j] + dp[root_r][i - j] -
                                         2ll * j * (i - j) * a[root]);
      if (i - 1 - j >= 0)
        dp[root][i] = max(dp[root][i], dp[root_l][j] + dp[root_r][i - 1 - j] -
                                           2ll * (j + 1) * (i - j) * a[root] +
                                           a[root] + 1ll * m * a[root]);
    }
  }
  return root;
}
int main(void) {
  int n;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i <= n; i++) {
    dp[0][i] = -1e18;
  }
  dp[0][0] = 0;
  int root = dfs(1, n);
  printf("%lld\n", dp[root][m]);
  return 0;
}
