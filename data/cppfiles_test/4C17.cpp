#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9 + 47;
const int nax = 2 * (int)1e5 + 10;
int n, k;
vector<pair<int, int>> g[nax];
int u[nax];
int a[nax];
int sz[nax];
int pref[nax];
int tot[nax][2], cnt[nax][2];
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
int mul(int a, int b) { return a * 1ll * b % MOD; }
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
void dfs(int v, int tot = 0, int p = -1) {
  tot = add(tot, a[v]);
  pref[v] = tot;
  sz[v] = 1;
  for (auto nxt : g[v]) {
    int to = nxt.first;
    if (to == p || u[to]) continue;
    dfs(to, tot, v);
    sz[v] += sz[to];
  }
}
void dfs_get(int v, vector<pair<int, int>>& vec, int cur, int alr = 0,
             int p = -1) {
  if (alr <= k) vec.push_back({alr, v});
  for (auto nxt : g[v]) {
    int to = nxt.first;
    if (to == p || u[to]) continue;
    dfs_get(to, vec, nxt.second, alr + (cur != nxt.second), v);
  }
}
int build(int v) {
  dfs(v);
  int p = v;
  int sz_all = sz[v];
  while (true) {
    int x = -1;
    for (auto nxt : g[v]) {
      int to = nxt.first;
      if (to == p || u[to]) continue;
      if (sz[to] * 2 > sz_all) {
        x = to;
        break;
      }
    }
    if (x == -1) break;
    p = v;
    v = x;
  }
  u[v] = 1;
  dfs(v);
  int res = 0;
  vector<vector<pair<int, int>>> vec(g[v].size());
  for (int i = 0; i < g[v].size(); i++) {
    if (!u[g[v][i].first]) dfs_get(g[v][i].first, vec[i], g[v][i].second);
  }
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    int cc = g[v][i].second;
    if (u[to]) continue;
    sort(vec[i].begin(), vec[i].end(), greater<pair<int, int>>());
    vector<int> id(2, 0);
    int count = 0, totl = 0;
    for (auto x : vec[i]) {
      for (int c = 0; c < 2; ++c) {
        while (cc < sz[v] && x.first + id[c] + (c != cc) <= k) {
          if (!cnt[id[c]][c]) break;
          count += cnt[id[c]][c];
          totl = add(totl, tot[id[c]][c]);
          ++id[c];
        }
      }
      res = add(res, pref[x.second]);
      res = add(res, add(mul(sub(pref[x.second], a[v]), count), totl));
    }
    for (auto x : vec[i]) {
      cnt[x.first][cc]++;
      tot[x.first][cc] = add(tot[x.first][cc], pref[x.second]);
    }
  }
  for (int i = 0; i < sz[v]; i++) {
    for (int j = 0; j < 2; j++) {
      tot[i][j] = 0, cnt[i][j] = 0;
    }
  }
  res = add(res, a[v]);
  for (auto nxt : g[v]) {
    int to = nxt.first;
    if (!u[to]) res = add(res, build(to));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int x, y, type;
    cin >> x >> y >> type;
    --x, --y;
    g[x].push_back({y, type});
    g[y].push_back({x, type});
  }
  cout << build(0);
}
