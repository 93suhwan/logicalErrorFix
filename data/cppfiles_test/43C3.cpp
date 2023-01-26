#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 1;
struct Edge {
  long long a;
  long long b;
  long long c;
  long long t;
  bool operator<(const Edge &other) const { return c < other.c; }
};
long long n, q;
long long arr[N];
long long ord[N];
long long ids[N];
long long mxi[N];
long long bst[N];
long long pre[N];
long long dep[N];
long long val[N][20];
long long tbl[N][20];
pair<long long, long long> que[N];
pair<long long, long long> ans[N];
vector<pair<long long, long long>> con[N];
long long get(long long u, long long v) {
  if (dep[u] > dep[v]) swap(u, v);
  long long dis = dep[v] - dep[u];
  long long res = 0;
  for (long long i = 19; i >= 0; i--) {
    if (dis >> i & 1) {
      res = max(res, val[v][i]);
      v = tbl[v][i];
    }
  }
  if (u == v) return res;
  for (long long i = 19; i >= 0; i--) {
    if (tbl[v][i] != tbl[u][i]) {
      res = max(res, val[v][i]);
      res = max(res, val[u][i]);
      v = tbl[v][i];
      u = tbl[u][i];
    }
  }
  res = max(res, val[v][0]);
  res = max(res, val[u][0]);
  return res;
}
long long fnd(long long i) {
  if (ids[i] != i) ids[i] = fnd(ids[i]);
  return ids[i];
}
void unn(long long a, long long b) {
  a = fnd(a);
  b = fnd(b);
  if (arr[bst[b]] > arr[bst[a]]) {
    swap(a, b);
  } else if (arr[bst[a]] == arr[bst[b]]) {
    mxi[a] = max(get(bst[a], bst[b]), max(mxi[a], mxi[b]));
  }
  ids[b] = a;
}
void dfs(long long i, long long p, long long x, long long d) {
  pre[i] = p;
  dep[i] = d;
  tbl[i][0] = p;
  val[i][0] = x;
  for (long long h = 1; h <= 19; h++) {
    tbl[i][h] = tbl[tbl[i][h - 1]][h - 1];
    val[i][h] = max(val[i][h - 1], val[tbl[i][h - 1]][h - 1]);
  }
  for (auto [v, t] : con[i]) {
    if (v != p) {
      dfs(v, i, t, d + 1);
    }
  }
}
bool cmp(long long a, long long b) { return que[a].first > que[b].first; }
signed main() {
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> arr[i];
  vector<Edge> edges;
  for (long long i = 2; i <= n; i++) {
    Edge e;
    cin >> e.a >> e.b >> e.c >> e.t;
    con[e.a].emplace_back(e.b, e.t);
    con[e.b].emplace_back(e.a, e.t);
    edges.push_back(e);
  }
  dfs(1, 0, 0, 0);
  sort(begin(edges), end(edges));
  for (long long i = 1; i <= q; i++) {
    cin >> que[i].first >> que[i].second;
  }
  iota(ord + 1, ord + 1 + q, 1);
  sort(ord + 1, ord + 1 + q, cmp);
  iota(ids + 1, ids + 1 + n, 1);
  iota(bst + 1, bst + 1 + n, 1);
  long long idx = n - 2;
  for (long long i = 1; i <= q; i++) {
    long long j = ord[i];
    while (idx >= 0 && edges[idx].c >= que[j].first) {
      unn(edges[idx].a, edges[idx].b), idx--;
    }
    long long p = que[j].second;
    long long r = max(get(p, bst[fnd(p)]), mxi[fnd(p)]);
    ans[j] = make_pair(arr[bst[fnd(p)]], r);
  }
  for (long long i = 1; i <= q; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
}
