#include <bits/stdc++.h>
using namespace std;
const int MAXN = 13, MAXM = MAXN * MAXN / 2;
long long c[MAXN][MAXN], fact[MAXN], ans;
int n, m, k, cnt, tot, e[MAXN][MAXN], way[MAXN][MAXN], bucket[MAXN], vis[MAXN];
set<int> s;
pair<int, int> g[MAXN];
struct Solution {
  int id[MAXN];
  bool operator<(const Solution& s2) const {
    for (int i = (1); i <= (n); i++)
      if (id[i] != s2.id[i]) return id[i] < s2.id[i];
    return 0;
  }
} sol;
set<Solution> ret;
long long P(long long n, long long m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return c[n][m] * fact[m];
}
int check() {
  static int dp[(1 << 6)][MAXN][MAXN];
  memset(dp, 0, sizeof dp);
  for (int i = (0); i <= (n / 2 - 1); i++) {
    if (e[g[i].first][g[i].second]) {
      dp[1 << i][g[i].first][g[i].second] =
          dp[1 << i][g[i].second][g[i].first] = 1;
    }
  }
  for (int i = (1); i <= ((1 << (n / 2)) - 1); i++) {
    for (int u = (1); u <= (n); u++) {
      for (int v = (1); v <= (n); v++) {
        if (!dp[i][u][v]) continue;
        for (int j = (0); j <= (n / 2 - 1); j++) {
          if (i & (1 << j)) continue;
          int x = g[j].first, y = g[j].second;
          if ((e[u][x] && e[v][y]) || (e[u][y] && e[v][x])) {
            dp[i | (1 << j)][x][y] = dp[i | (1 << j)][y][x] = 1;
          }
        }
      }
    }
  }
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (dp[(1 << (n / 2)) - 1][i][j]) return 1;
  return 0;
}
void dfs2(int r) {
  if (r == n / 2) {
    for (int i = (1); i <= (cnt); i++) {
      for (int j = (1); j <= (way[i][0]); j++) {
        int u = g[way[i][j]].first, v = g[way[i][j]].second;
        sol.id[u] = sol.id[v] = i;
      }
    }
    ret.insert(sol);
    return;
  }
  for (int i = (1); i <= (cnt); i++) {
    way[i][++way[i][0]] = r;
    dfs2(r + 1);
    way[i][0]--;
  }
  cnt++;
  way[cnt][++way[cnt][0]] = r;
  dfs2(r + 1);
  way[cnt][0]--;
  cnt--;
}
void dfs() {
  int u = 0;
  for (int i = (1); i <= (n); i++)
    if (!vis[i]) {
      u = i;
      break;
    }
  if (!u) {
    if (!check()) return;
    cnt = 0;
    for (int i = (1); i <= (n); i++) way[i][0] = 0;
    dfs2(0);
    return;
  }
  vis[u] = 1;
  for (int v = (u + 1); v <= (n); v++) {
    if (vis[v]) continue;
    vis[v] = 1;
    g[tot++] = make_pair(u, v);
    dfs();
    tot--;
    vis[v] = 0;
  }
  vis[u] = 0;
}
void solve() {
  for (int i = (1); i <= (m); i++) {
    int u, v;
    cin >> u >> v;
    e[u][v] = e[v][u] = 1;
  }
  dfs();
  for (auto it : ret) {
    int cnt = 0;
    memset(bucket, 0, sizeof bucket);
    for (int i = (1); i <= (n); i++) {
      if (bucket[it.id[i]]) continue;
      cnt++;
      bucket[it.id[i]] = 1;
    }
    ans += P(k, cnt);
  }
}
int main() {
  c[0][0] = 1;
  for (int i = (1); i <= (12); i++) {
    c[i][0] = 1;
    for (int j = (1); j <= (i); j++) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  fact[0] = 1;
  for (int i = (1); i <= (12); i++) fact[i] = fact[i - 1] * i;
  cin >> n >> m >> k;
  solve();
  printf("%lld", ans);
  return 0;
}
