#include <bits/stdc++.h>
const int MAXN = 1e3;
int n, k, mxc, ans[MAXN + 5][MAXN + 5];
inline void solve(const int l, const int r, const int clr) {
  if (l == r) return;
  if (clr > mxc) mxc = clr;
  int s = (r - l + k) / k;
  for (int i = l; i <= r; i += s) {
    solve(i, std::min(i + s - 1, r), clr + 1);
    for (int u = l, repu = i - 1; u <= repu; ++u)
      for (int v = i, repv = std::min(i + s - 1, r); v <= repv; ++v) {
        ans[u][v] = clr;
      }
  }
}
int main() {
  scanf("%d %d", &n, &k);
  solve(1, n, 1);
  printf("%d\n", mxc);
  for (int i = 1, repi = n; i <= repi; ++i)
    for (int j = i + 1, repj = n; j <= repj; ++j) printf("%d ", ans[i][j]);
  putchar('\n');
  return 0;
}
