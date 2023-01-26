#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(2226701);
const int INF = 0x3f3f3f3f;
const int maxn = 55;
int n, k;
class Dsu {
 public:
  int fa[maxn];
  inline void init() {
    for (int i = 0; i < n; ++i) fa[i] = i;
    return;
  }
  inline int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
  inline bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    fa[x] = y;
    return 1;
  }
} dsu;
int deg2[maxn], deg[maxn], d[maxn];
int w[maxn][maxn], vis[maxn][maxn];
inline bool cmp(const pair<int, int> &i, const pair<int, int> &j) {
  return w[i.first][i.second] < w[j.first][j.second];
}
inline int check() {
  vector<pair<int, int> > vec;
  dsu.init();
  int ret = 0, cnt = n;
  vector<pair<int, int> > fuck;
  for (int i = 0; i < n; ++i) {
    deg2[i] = deg[i];
    for (int j = i + 1; j < n; ++j) {
      if (vis[i][j]) {
        if (!dsu.merge(i, j)) return INF;
        ret += w[i][j];
        fuck.push_back(make_pair(i, j));
        --cnt;
      } else
        vec.push_back(make_pair(i, j));
    }
  }
  sort(vec.begin(), vec.end(), cmp);
  for (int i = 0; i < vec.size(); ++i)
    if (deg2[vec[i].first] < d[vec[i].first] &&
        deg2[vec[i].second] < d[vec[i].second] &&
        dsu.merge(vec[i].first, vec[i].second))
      ret += w[vec[i].first][vec[i].second], ++deg2[vec[i].first],
          ++deg2[vec[i].second], --cnt, fuck.push_back(vec[i]);
  if (cnt > 1) return INF;
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) scanf("%d", d + i);
  for (int i = k; i < n; ++i) d[i] = INF;
  vector<pair<int, int> > all;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      scanf("%d", &w[i][j]);
      if (i < k) all.push_back(make_pair(i, j));
    }
  int ans = check(), cur = ans;
  for (long double T = 1000; T > 0.0001; T *= 0.9993) {
    int p = -1;
    for (p = rnd() % all.size(); (deg[all[p].first] == d[all[p].first] ||
                                  deg[all[p].second] == d[all[p].second]) &&
                                 !vis[all[p].first][all[p].second];
         p = rnd() % all.size())
      ;
    int u = all[p].first, v = all[p].second;
    deg[u] -= vis[u][v], deg[v] -= vis[u][v];
    vis[u][v] ^= 1;
    deg[u] += vis[u][v], deg[v] += vis[u][v];
    int delta = check() - cur;
    if (exp(-delta / T) >= (long double)(rnd() % 1000000000) / 1000000000) {
      cur += delta;
      ans = min(ans, cur);
    } else {
      deg[u] -= vis[u][v], deg[v] -= vis[u][v];
      vis[u][v] ^= 1;
      deg[u] += vis[u][v], deg[v] += vis[u][v];
    }
  }
  printf("%d\n", ans);
  return 0;
}
