#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;
int n, q, val[maxn], bel[maxn];
int dep[maxn], w[maxn], fa[maxn][20], ew[maxn];
pair<int, int> sub[maxn], mx[maxn][20];
vector<pair<int, int>> Q[maxn], G[maxn];
int find(int x) { return x == bel[x] ? x : bel[x] = find(bel[x]); }
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &val[i]);
  }
  vector<array<int, 4>> E;
  for (int i = 1, a, b, c, t; i < n; i++) {
    scanf("%d %d %d %d", &a, &b, &c, &t);
    E.push_back({c, a, b, t});
  }
  sort(E.begin(), E.end(), greater<array<int, 4>>());
  int tot = n;
  iota(bel + 1, bel + n + 1, 1);
  for (int i = 0; i < E.size(); i++) {
    int k = ++tot;
    w[k] = E[i][0], G[k].emplace_back(find(E[i][1]), E[i][3]);
    G[k].emplace_back(find(E[i][2]), E[i][3]);
    bel[find(E[i][1])] = bel[find(E[i][2])] = bel[k] = k;
  }
  function<void(int)> dfs = [&](int v) {
    dep[v] = dep[fa[v][0]] + 1, sub[v] = {val[v], 0};
    for (int i = 1; 1 << i < dep[v]; i++) {
      fa[v][i] = fa[fa[v][i - 1]][i - 1];
    }
    pair<int, int> sec(0, 0);
    for (auto &e : G[v]) {
      fa[e.first][0] = v, ew[e.first] = e.second, dfs(e.first);
      auto p = sub[e.first];
      p.second = max(e.second, p.second);
      if (p > sub[v])
        sec = sub[v], sub[v] = p;
      else
        sec = max(sec, p);
    }
    for (auto &e : G[v]) {
      auto p = sub[e.first];
      p.second = max(e.second, p.second);
      mx[e.first][0] = p == sub[v] ? sec : sub[v];
      mx[e.first][0].second = max(mx[e.first][0].second, e.second);
    }
  };
  dfs(tot);
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= tot; i++) {
      mx[i][j] = max(mx[i][j - 1], mx[fa[i][j - 1]][j - 1]);
      mx[i][j].second = max(mx[i][j].second, ew[fa[i][j - 1]]);
    }
  }
  while (q--) {
    int v, x;
    scanf("%d %d", &x, &v);
    int o = v;
    for (int i = 19; ~i; i--) {
      if (fa[o][i] && w[fa[o][i]] >= x) o = fa[o][i];
    }
    pair<int, int> ans(val[v], 0);
    int cur = 0;
    for (int i = 19; ~i; i--)
      if (dep[fa[v][i]] >= dep[o]) {
        ans = max(ans, make_pair(mx[v][i].first, max(cur, mx[v][i].second)));
        cur = max(cur, ew[v = fa[v][i]]);
      }
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}
