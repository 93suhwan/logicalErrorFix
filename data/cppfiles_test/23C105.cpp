#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 4e3 + 7;
int siz[maxn], ls[maxn], rs[maxn], lw[maxn], rw[maxn], arr[maxn];
int sta[maxn], n, m;
ll dp[maxn][maxn];
void build() {
  int top = 0;
  for (int i = 1; i <= n; ++i) {
    while (top > 0 && arr[sta[top]] > arr[i]) ls[i] = sta[top--];
    if (sta[top]) {
      rs[sta[top]] = i;
      rw[sta[top]] = arr[i] - arr[sta[top]];
    }
    if (ls[i]) {
      lw[i] = arr[ls[i]] - arr[i];
    }
    sta[++top] = i;
  }
}
void dfs(int u) {
  siz[u] = 1;
  if (ls[u]) {
    dfs(ls[u]);
    for (int i = min(m, siz[u]); i >= 0; --i) {
      for (int j = min(m, siz[ls[u]]); j >= 0; --j) {
        if (i + j > m) continue;
        dp[u][i + j] = max(dp[u][i + j],
                           dp[u][i] + dp[ls[u]][j] + 1ll * (m - j) * j * lw[u]);
      }
    }
    siz[u] += siz[ls[u]];
  }
  if (rs[u]) {
    dfs(rs[u]);
    for (int i = min(m, siz[u]); i >= 0; --i) {
      for (int j = min(m, siz[rs[u]]); j >= 0; --j) {
        if (i + j > m) continue;
        dp[u][i + j] = max(dp[u][i + j],
                           dp[u][i] + dp[rs[u]][j] + 1ll * (m - j) * j * rw[u]);
      }
    }
    siz[u] += siz[rs[u]];
  }
}
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", arr + i);
  build();
  dfs(sta[1]);
  printf("%lld\n", dp[sta[1]][m]);
}
int main() {
  solve();
  return 0;
}
