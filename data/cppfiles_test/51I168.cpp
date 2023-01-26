#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
mt19937 rng(19260817);
const int MAXN = 51;
int n, k, d[MAXN], deg[MAXN], cost[MAXN][MAXN], fa[MAXN];
bool ok[MAXN][MAXN], used[MAXN][MAXN];
int root(int x) { return fa[x] = (fa[x] == x ? x : root(fa[x])); }
vector<int> dfs(int now, int pre) {
  vector<int> ret;
  ret.push_back(now);
  for (int it = 1; it <= n; ++it)
    if (used[it][now] && it != pre) {
      vector<int> z = dfs(it, now);
      for (auto it : z) ret.push_back(it);
    }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) scanf("%d", &d[i]);
  for (int i = k + 1; i <= n; ++i) d[i] = n;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
      int w;
      scanf("%d", &w);
      cost[i][j] = cost[j][i] = w;
    }
  for (int i = 1; i <= n; ++i) fa[i] = i;
  vector<pair<int, pair<int, int> > > e;
  for (int i = k + 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      e.push_back(make_pair(cost[i][j], make_pair(i, j)));
  sort(e.begin(), e.end());
  for (auto it : e) {
    int u, v;
    u = it.second.first;
    v = it.second.second;
    if (root(u) == root(v)) continue;
    fa[root(u)] = root(v);
    ok[u][v] = ok[v][u] = 1;
    used[u][v] = used[v][u] = 1;
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= k; ++i)
    for (int j = k + 1; j <= n; ++j) ok[i][j] = ok[j][i] = 1;
  for (int i = 1; i <= k; ++i)
    for (int j = i + 1; j <= k; ++j) ok[i][j] = ok[j][i] = 1;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i <= k; ++i) {
    used[i][k + 1] = used[k + 1][i] = 1;
    deg[i]++;
    deg[k + 1]++;
  }
  int cur, ans;
  cur = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      if (used[i][j]) cur += cost[i][j];
  ans = cur;
  double T, D;
  T = 2e5, D = 0.998;
  int ti = clock();
  while (T > 0.000001) {
    vector<pair<pair<int, int>, pair<int, int> > > cm;
    for (int u = 1; u <= n; ++u) {
      for (int v = u + 1; v <= n; ++v) {
        if (used[u][v]) {
          auto A = dfs(u, v);
          auto B = dfs(v, u);
          deg[u]--;
          deg[v]--;
          for (auto a : A) {
            if (deg[a] != d[a])
              for (auto b : B) {
                if (!used[a][b] && ok[a][b] && deg[b] != d[b]) {
                  cm.push_back(make_pair(make_pair(u, v), make_pair(a, b)));
                }
              }
          }
          deg[u]++;
          deg[v]++;
        }
      }
    }
    if (cm.empty()) break;
    auto it = cm[rng() % cm.size()];
    int u, v, a, b;
    u = it.first.first;
    v = it.first.second;
    a = it.second.first;
    b = it.second.second;
    int delta = cost[a][b] - cost[u][v];
    if (delta < 0 || (double)(rng() % 1000000001) / 1e9 < exp(-delta / T)) {
      used[u][v] = used[v][u] = 0;
      used[a][b] = used[b][a] = 1;
      deg[u]--;
      deg[v]--;
      deg[a]++;
      deg[b]++;
      cur += delta;
      ans = min(ans, cur);
    }
    T *= D;
    if (clock() - ti > 5980) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}
