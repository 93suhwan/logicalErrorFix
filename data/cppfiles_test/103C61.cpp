#include <bits/stdc++.h>
using namespace std;
int n, m, k, to[105], edge[105][105];
bool dp[10][(1 << 6) + 11];
map<pair<long long, long long>, bool> M;
vector<vector<pair<int, int>>> vec;
vector<vector<vector<int>>> group;
long long ans, fac[105];
void dfs0(int lvl) {
  if (to[lvl]) return dfs0(lvl + 1);
  if (lvl == n + 1) {
    vector<pair<int, int>> cur;
    for (int i = (1); i <= (n); i++)
      if (i < to[i]) cur.push_back(make_pair(i, to[i]));
    vec.push_back(cur);
    return;
  }
  for (int i = (lvl + 1); i <= (n); i++) {
    if (to[i]) continue;
    to[lvl] = i;
    to[i] = lvl;
    dfs0(lvl + 1);
    to[lvl] = to[i] = 0;
  }
}
void dfs1(int lvl, int dep) {
  if (lvl == n / 2 + 1) {
    vector<vector<int>> cur;
    cur.resize(dep);
    for (int i = (1); i <= (n / 2); i++) cur[to[i] - 1].push_back(i - 1);
    group.push_back(cur);
    return;
  }
  for (int i = (1); i <= (dep + 1); i++) {
    to[lvl] = i;
    dfs1(lvl + 1, max(dep, i));
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  fac[0] = 1;
  for (int i = (1); i <= (k); i++) fac[i] = fac[i - 1] * i;
  for (int i = (1); i <= (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u][v] = edge[v][u] = 1;
  }
  dfs0(1);
  dfs1(1, 0);
  for (auto x : vec) {
    memset(dp, 0, sizeof dp);
    for (int i = (0); i <= (n / 2 - 1); i++) {
      if (edge[x[i].first][x[i].second]) dp[i][(1 << i)] = 1;
    }
    for (int s = (1); s <= ((1 << (n / 2)) - 1); s++) {
      for (int i = (0); i <= (n / 2 - 1); i++) {
        if (!dp[i][s]) continue;
        for (int j = (0); j <= (n / 2 - 1); j++) {
          if (s >> j & 1) continue;
          if ((edge[x[i].first][x[j].first] &&
               edge[x[i].second][x[j].second]) ||
              (edge[x[i].first][x[j].second] &&
               edge[x[i].second][x[j].first])) {
            dp[j][s | (1 << j)] = 1;
          }
        }
      }
    }
    bool flag = 0;
    for (int i = (0); i <= (n / 2 - 1); i++) flag |= dp[i][(1 << (n / 2)) - 1];
    if (!flag) continue;
    for (auto y : group) {
      int cnt = 0;
      long long u = 0, v = 0;
      for (auto z : y) {
        cnt++;
        if (cnt <= 3)
          u <<= 12;
        else
          v <<= 12;
        for (auto w : z) {
          if (cnt <= 3) {
            u |= (1 << (x[w].first - 1));
            u |= (1 << (x[w].second - 1));
          } else {
            v |= (1 << (x[w].first - 1));
            v |= (1 << (x[w].second - 1));
          }
        }
      }
      if (M[make_pair(u, v)]) continue;
      M[make_pair(u, v)] = 1;
      if (cnt <= k) ans += fac[k] / fac[k - cnt];
    }
  }
  printf("%lld\n", ans);
  return 0;
}
