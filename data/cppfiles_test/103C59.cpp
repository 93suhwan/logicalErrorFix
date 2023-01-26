#include <bits/stdc++.h>
using namespace std;
long long T, n, m, top, tt, ans, vis[2010][2010], dis[2010][2010];
pair<long long, long long> sta[4001000];
char mm[2010][2010];
inline void Min(long long &u, long long v) {
  if (v < u) u = v;
}
inline void Max(long long &u, long long v) {
  if (v > u) u = v;
}
void dfs(long long u, long long v) {
  if (!u || u > m || !v || v > n) {
    long long i, j;
    for (i = 1; top; i++, top--) {
      dis[sta[top].first][sta[top].second] = i;
    }
    return;
  }
  if (vis[u][v] == tt) {
    if (dis[u][v]) {
      long long i, j;
      for (i = dis[u][v] + 1; top; i++, top--) {
        dis[sta[top].first][sta[top].second] = i;
      }
      return;
    }
    long long i, j, len;
    for (i = top; sta[i] != make_pair(u, v); i--)
      ;
    len = top - i + 1;
    for (;; top--) {
      dis[sta[top].first][sta[top].second] = len;
      if (sta[top] == make_pair(u, v)) break;
    }
    top--;
    for (i = len + 1; top; top--, i++) {
      dis[sta[top].first][sta[top].second] = i;
    }
    return;
  }
  sta[++top] = make_pair(u, v);
  vis[u][v] = tt;
  if (mm[u][v] == 'L')
    dfs(u, v - 1);
  else if (mm[u][v] == 'R')
    dfs(u, v + 1);
  else if (mm[u][v] == 'U')
    dfs(u - 1, v);
  else
    dfs(u + 1, v);
}
int main() {
  long long i, j, t, p, q;
  cin >> T;
  while (T--) {
    tt++, ans = top = 0;
    scanf("%lld%lld", &m, &n);
    for (i = 1; i <= m; i++) scanf("%s", mm[i] + 1);
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        if (vis[i][j] == tt) continue;
        dfs(i, j);
      }
    }
    for (i = 1; i <= m; i++) {
      for (j = 1; j <= n; j++) {
        if (dis[i][j] > ans) {
          ans = dis[i][j];
          p = i, q = j;
        }
        dis[i][j] = 0;
      }
    }
    printf("%lld %lld %lld\n", p, q, ans);
  }
}
