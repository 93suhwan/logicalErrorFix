#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int inf = 1000 * 1000 * 1000;
const int mod = 1000 * 1000 * 1000 + 7;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
struct edge {
  int a, b, c, t;
};
vector<edge> E;
struct query {
  int v, x, id;
};
pair<int, int> answ[N];
vector<query> Q;
int n, q;
int a[N];
bool cmp_edge(const edge &e1, const edge &e2) { return e1.c > e2.c; }
bool cmp_query(const query &q1, const query &q2) { return q1.v > q2.v; }
int dp[N][22], d[N][22];
int root[N];
vector<int> vertices[N];
vector<pair<int, int> > g[N];
int depth[N];
int mx[N], papa[N], l[N];
vector<int> mas;
void dfs(int v, int p, int mx, int r) {
  depth[v] = r;
  if (a[v] == mx) {
    mas.push_back(v);
  }
  dp[v][0] = p;
  for (int i = 1; i < 20; i++) {
    dp[v][i] = dp[dp[v][i - 1]][i - 1];
    d[v][i] = max(d[v][i - 1], d[dp[v][i - 1]][i - 1]);
  }
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i].first;
    int len = g[v][i].second;
    if (to == p) continue;
    d[to][0] = len;
    dfs(to, v, mx, r + 1);
  }
}
void lca(int &v, int u, int &l) {
  if (depth[v] < depth[u]) {
    int delta = depth[u] - depth[v];
    for (int i = 0; i < 20; i++) {
      if ((delta >> i) & 1) {
        l = max(l, d[u][i]);
        u = dp[u][i];
      }
    }
  } else if (depth[v] > depth[u]) {
    int delta = depth[v] - depth[u];
    for (int i = 0; i < 20; i++) {
      if ((delta >> i) & 1) {
        l = max(l, d[v][i]);
        v = dp[v][i];
      }
    }
  }
  if (v == u) return;
  for (int i = 19; i >= 0; i--) {
    if (dp[v][i] != dp[u][i]) {
      l = max(l, d[v][i]);
      l = max(l, d[u][i]);
      v = dp[v][i];
      u = dp[u][i];
    }
  }
  assert(dp[v][0] == dp[u][0]);
  l = max(l, d[v][0]);
  l = max(l, d[u][0]);
  v = dp[v][0];
}
void tmerge(edge e) {
  int a = e.a;
  int b = e.b;
  int len = e.t;
  g[a].push_back(make_pair(b, len));
  g[b].push_back(make_pair(a, len));
  if ((int)vertices[root[a]].size() < (int)vertices[root[b]].size()) {
    swap(a, b);
  }
  int root_a = root[a];
  int root_b = root[b];
  for (int gag : vertices[root_b]) {
    root[gag] = root_a;
    vertices[root_a].push_back(gag);
  }
  vertices[root_b].clear();
  d[b][0] = len;
  int cur_mx = max(mx[root_a], mx[root_b]);
  dfs(b, a, cur_mx, depth[a] + 1);
  int cur_papa = 0;
  int cur_l = 0;
  if (cur_mx == mx[root_a]) {
    cur_papa = papa[root_a];
    cur_l = l[root_a];
  }
  for (int i = 0; i < (int)mas.size(); i++) {
    int v = mas[i];
    if (cur_papa == 0) {
      cur_papa = v;
    } else {
      lca(cur_papa, v, cur_l);
    }
  }
  mas.clear();
  mx[root_a] = cur_mx;
  papa[root_a] = cur_papa;
  l[root_a] = cur_l;
}
pair<int, int> get(int v) {
  pair<int, int> answ;
  int rt = root[v];
  answ.first = mx[rt];
  answ.second = l[rt];
  lca(v, papa[rt], answ.second);
  return answ;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++) {
    edge cur;
    scanf("%d%d%d%d", &cur.a, &cur.b, &cur.c, &cur.t);
    E.push_back(cur);
  }
  sort(E.begin(), E.end(), cmp_edge);
  for (int i = 1; i <= n; i++) {
    vertices[i].push_back(i);
    mx[i] = a[i];
    papa[i] = root[i] = i;
    l[i] = depth[i] = 0;
    for (int j = 0; j < 20; j++) {
      dp[i][j] = i;
      d[i][j] = 0;
    }
  }
  for (int i = 1; i <= q; i++) {
    query cur;
    scanf("%d%d", &cur.v, &cur.x);
    cur.id = i;
    Q.push_back(cur);
  }
  sort(Q.begin(), Q.end(), cmp_query);
  int it = 0;
  for (int i = 0; i < q; i++) {
    int id = Q[i].id;
    int v = Q[i].x;
    int cap = Q[i].v;
    while (it < (int)E.size() && E[it].c >= cap) {
      tmerge(E[it]);
      ++it;
    }
    answ[id] = get(v);
  }
  for (int i = 1; i <= q; i++) {
    printf("%d %d\n", answ[i].first, answ[i].second);
  }
  return 0;
}
