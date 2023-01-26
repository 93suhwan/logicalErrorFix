#include <bits/stdc++.h>
using namespace std;
const int Maxn = 4005;
long long dp[Maxn][Maxn];
int n, m;
int a[Maxn];
int sta[Maxn], top = 0;
int ls[Maxn], rs[Maxn], siz[Maxn];
int lw[Maxn], rw[Maxn];
inline int read() {
  int x = 0, f = 1;
  char p = getchar();
  while (p < '0' || p > '9') {
    if (p == '-') f = -1;
    p = getchar();
  }
  while (p >= '0' && p <= '9') {
    x = (x << 1) + (x << 3) + p - '0';
    p = getchar();
  }
  return x * f;
}
void dfs(int x) {
  siz[x] = 1;
  if (ls[x]) {
    dfs(ls[x]);
    for (int i = min(siz[x], m); i >= 0; i--) {
      for (int j = min(siz[ls[x]], m); j >= 0; j--) {
        dp[x][i + j] = max(dp[x][i + j],
                           dp[x][i] + dp[ls[x]][j] + 1ll * j * (m - j) * lw[x]);
      }
    }
    siz[x] += siz[ls[x]];
  }
  if (rs[x]) {
    dfs(rs[x]);
    for (int i = min(siz[x], m); i >= 0; i--) {
      for (int j = min(siz[rs[x]], m); j >= 0; j--) {
        dp[x][i + j] = max(dp[x][i + j],
                           dp[x][i] + dp[rs[x]][j] + 1ll * j * (m - j) * rw[x]);
      }
    }
    siz[x] += siz[rs[x]];
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    int k = top;
    while (k > 0 && a[sta[k]] > a[i]) k--;
    if (k) rs[sta[k]] = i, rw[sta[k]] = a[i] - a[sta[k]];
    if (k < top) ls[i] = sta[k + 1], lw[i] = a[sta[k + 1]] - a[i];
    sta[++k] = i;
    top = k;
  }
  dfs(sta[1]);
  printf("%lld\n", dp[sta[1]][m]);
}
