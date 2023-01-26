#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[4010], size[4010];
int stk[4010], top;
int ls[4010], rs[4010], w[4010][2];
long long dp[4010][4010];
template <typename Tp>
void read(Tp &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
void dfs(int x) {
  size[x] = 1;
  if (ls[x]) {
    dfs(ls[x]);
    for (int j = 0; j <= size[ls[x]]; ++j)
      dp[x][j] = dp[ls[x]][j] + 1ll * j * (m - j) * w[x][0];
    size[x] += size[ls[x]];
  }
  if (rs[x]) {
    dfs(rs[x]);
    for (int i = size[ls[x]] + size[rs[x]]; i >= 0; --i) {
      for (int j = min(i, size[rs[x]]); j <= max(0, i - size[ls[x]]); ++j) {
        dp[x][i] = max(dp[x][i], dp[x][i - j] + dp[rs[x]][j] +
                                     1ll * j * (m - j) * w[x][1]);
      }
    }
    size[x] += size[rs[x]];
  }
  for (int i = 0; i < size[x]; ++i) dp[x][i + 1] = max(dp[x][i], dp[x][i + 1]);
}
int main() {
  read(n), read(m);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    bool flag = false;
    while (top > 0 && a[stk[top]] > a[i]) top--, flag = true;
    if (top) rs[stk[top]] = i, w[stk[top]][1] = a[i] - a[stk[top]];
    if (flag) ls[i] = stk[top + 1], w[i][0] = a[stk[top + 1]] - a[i];
    stk[++top] = i;
  }
  dfs(stk[1]);
  printf("%lld\n", dp[stk[1]][m]);
  return 0;
}
