#include <bits/stdc++.h>
using namespace std;
int n, m, root = 0;
int val[4000], siz[4000];
int lc[4000], rc[4000];
long long int dp[4000][4004];
int build(int l, int r) {
  if (l > r) return -1;
  int rt = l;
  for (int i = l + 1; i <= r; i++)
    if (val[rt] > val[i]) rt = i;
  lc[rt] = build(l, rt - 1);
  rc[rt] = build(rt + 1, r);
  return rt;
}
long long int temp[4004];
int dfs(int i) {
  if (i == -1) return 0;
  siz[i] = 1 + dfs(lc[i]);
  siz[i] += dfs(rc[i]);
  dp[i][0] = 0;
  dp[i][1] = (long long int)val[i] * (m - 1);
  if (lc[i] != -1) {
    for (int j = 0; j <= n; j++) temp[j] = 0;
    int ma = siz[lc[i]], mb = 1;
    for (int a = 0; a <= ma; a++)
      for (int b = 0; b <= mb; b++)
        temp[a + b] = max(temp[a + b], dp[lc[i]][a] + dp[i][b] -
                                           (long long int)2 * a * b * val[i]);
    for (int j = 0; j <= siz[i]; j++) dp[i][j] = temp[j];
  }
  if (rc[i] != -1) {
    for (int j = 0; j <= n; j++) temp[j] = 0;
    int mb = siz[rc[i]], ma = siz[i] - mb;
    for (int a = 0; a <= ma; a++)
      for (int b = 0; b <= mb; b++)
        temp[a + b] = max(temp[a + b], dp[i][a] + dp[rc[i]][b] -
                                           (long long int)2 * a * b * val[i]);
    for (int j = 0; j <= siz[i]; j++) dp[i][j] = temp[j];
  }
  return siz[i];
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val[i]);
    if (val[root] > val[i]) root = i;
  }
  lc[root] = build(0, root - 1);
  rc[root] = build(root + 1, n - 1);
  dfs(root);
  printf("%lld\n", dp[root][m]);
  return 0;
}
