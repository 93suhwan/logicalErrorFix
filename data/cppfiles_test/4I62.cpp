#include <bits/stdc++.h>
using namespace std;
int n, k, a[200005];
vector<pair<int, int> > G[200005];
bool centroid[200005];
int sz[200005], deep[200005], d[200005];
int ans;
void add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
void dec(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
vector<pair<int, int> > vec[2];
pair<int, int> getroot(int v, int p, int t) {
  pair<int, int> res = pair<int, int>(INT_MAX, -1);
  int m = 0;
  sz[v] = 1;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int to = G[v][i].first;
    if (to == p || centroid[to]) continue;
    res = min(res, getroot(to, v, t));
    m = max(m, sz[to]);
    sz[v] += sz[to];
  }
  m = max(m, t - sz[v]);
  res = min(res, pair<int, int>(m, v));
  return res;
}
void dfs(int v, int p, int cost, int last, int turns, int type) {
  vec[type].push_back(pair<int, int>(turns, cost));
  for (int i = 0; i < (int)G[v].size(); i++) {
    int to = G[v][i].first, c = G[v][i].second;
    if (to == p || centroid[to]) continue;
    int ncost = cost;
    add(ncost, a[to]);
    dfs(to, v, ncost, c, turns + (last ^ c), type);
  }
}
int calc(int addcost) {
  int s0 = 0, s1 = 0;
  for (auto p : vec[0]) add(s0, p.second);
  for (auto p : vec[1]) add(s1, p.second);
  sort(vec[0].begin(), vec[0].end());
  sort(vec[1].begin(), vec[1].end());
  int res = 0;
  int l = 0, r = (int)vec[0].size() - 1, sum = s0;
  while (l < r) {
    if (vec[0][l].first + vec[0][r].first <= k) {
      add(res, 1LL * (r - l) * vec[0][l].second % 1000000007);
      add(res, 1LL * (r - l) * addcost % 1000000007);
      dec(sum, vec[0][l].second);
      add(res, sum);
      l++;
    } else {
      dec(sum, vec[0][r].second);
      r--;
    }
  }
  l = 0, r = (int)vec[1].size() - 1, sum = s1;
  while (l < r) {
    if (vec[1][l].first + vec[1][r].first <= k) {
      add(res, 1LL * (r - l) * vec[1][l].second % 1000000007);
      add(res, 1LL * (r - l) * addcost % 1000000007);
      dec(sum, vec[1][l].second);
      add(res, sum);
      l++;
    } else {
      dec(sum, vec[1][r].second);
      r--;
    }
  }
  l = 0, r = (int)vec[1].size() - 1, sum = s1;
  while (l < (int)vec[0].size() && r >= 0) {
    if (vec[0][l].first + vec[1][r].first <= k - 1) {
      add(res, sum);
      add(res, vec[0][l].second);
      add(res, 1LL * (r + 1) * addcost % 1000000007);
      l++;
    } else {
      dec(sum, vec[1][r].second);
      r--;
    }
  }
  return res;
}
void solve(int v) {
  centroid[v] = true;
  for (int i = 0; i < (int)G[v].size(); i++) {
    int to = G[v][i].first;
    if (centroid[to]) continue;
    vec[0].clear();
    vec[1].clear();
    dfs(to, v, a[to], G[v][i].second, 0, G[v][i].second);
    dec(ans, calc(a[v]));
  }
  vec[0].clear();
  vec[1].clear();
  for (int i = 0; i < (int)G[v].size(); i++) {
    int to = G[v][i].first;
    if (centroid[to]) continue;
    dfs(to, v, a[to], G[v][i].second, 0, G[v][i].second);
  }
  for (auto p : vec[0])
    if (p.first <= k) {
      add(ans, p.second);
      add(ans, a[v]);
    }
  for (auto p : vec[1])
    if (p.first <= k) {
      add(ans, p.second);
      add(ans, a[v]);
    }
  add(ans, calc(a[v]));
  for (int i = 0; i < (int)G[v].size(); i++) {
    int to = G[v][i].first;
    if (centroid[to]) continue;
    int rt = getroot(to, v, sz[to]).second;
    solve(rt);
  }
}
void ac() {
  ans = 0;
  int rt = getroot(1, 0, n).second;
  solve(rt);
  for (int i = 1; i <= n; i++) add(ans, a[i]);
  printf("%d\n", ans);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(pair<int, int>(v, w));
    G[v].push_back(pair<int, int>(u, w));
  }
  ac();
  return 0;
}
