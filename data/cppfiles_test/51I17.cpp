#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 51;
int n, k;
int d[MAXN], fa[MAXN], deg[MAXN], cost[MAXN][MAXN];
vector<int> g[MAXN];
int root(int x) { return fa[x] = (fa[x] == x ? x : root(fa[x])); }
void del_edge(int u, int v) {
  deg[u]--;
  deg[v]--;
  vector<int> Tmp;
  for (auto it : g[u])
    if (it != v) Tmp.push_back(it);
  g[u] = Tmp;
  Tmp.clear();
  for (auto it : g[v])
    if (it != u) Tmp.push_back(it);
  g[v] = Tmp;
}
void add_edge(int u, int v) {
  deg[u]++;
  deg[v]++;
  g[u].push_back(v);
  g[v].push_back(u);
}
int P;
vector<int> tmp;
void dfs(int now, int pre, int z) {
  if (now == z) {
    P = pre;
    return;
  }
  if (deg[now] != d[now]) tmp.push_back(now);
  for (auto it : g[now])
    if (it != pre) dfs(it, now, z);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) d[i] = n;
  for (int i = 1; i <= k; ++i) scanf("%d", &d[i]);
  vector<pair<int, pair<int, int> > > e;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      int w;
      scanf("%d", &w);
      cost[i][j] = cost[j][i] = w;
      e.push_back(make_pair(w, make_pair(i, j)));
    }
  clock_t st = clock();
  sort(e.begin(), e.end());
  for (int i = 1; i <= n; ++i) fa[i] = i;
  int answer = INF;
  int cur = 0;
  for (auto it : e) {
    int w, u, v;
    w = it.first;
    u = it.second.first;
    v = it.second.second;
    if (root(u) == root(v) || deg[u] + 1 > d[u] || deg[v] + 1 > d[v]) continue;
    cur += w;
    add_edge(u, v);
    fa[root(u)] = root(v);
  }
  answer = cur;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  double T = 10000000, d = 0.999;
  while (clock() - st < 5800) {
    tmp.clear();
    int z = rng() % (n - 1) + 2;
    dfs(1, 0, z);
    if (tmp.empty()) continue;
    int y = tmp[rng() % tmp.size()];
    int delta = cost[z][y] - cost[z][P];
    if (delta < 0 || rng() % 1000000001 < llround(1e9 * exp(-delta / T))) {
      del_edge(z, P);
      add_edge(z, y);
      cur += delta;
      answer = min(answer, cur);
    } else
      continue;
    T *= d;
  }
  printf("%d\n", answer);
  return 0;
}
