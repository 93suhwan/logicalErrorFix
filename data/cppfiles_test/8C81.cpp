#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int n, q;
vector<long long int> a;
vector<long long int> graph[100001];
long long int parent[20][100001], sizes[100001], seg[4 * 100001], depth[100001],
    lazy[4 * 100001], mapping[100001], till[100001];
void update(long long int v, long long int from, long long int to,
            long long int l, long long int r, long long int del) {
  if (lazy[v]) {
    seg[v] += (to - from + 1) * lazy[v];
    if (from != to) lazy[2 * v] += lazy[v], lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
  }
  if (from > r || l > to) return;
  if (l <= from && to <= r) {
    seg[v] += (to - from + 1) * del;
    if (from != to) lazy[2 * v] += del, lazy[2 * v + 1] += del;
    return;
  }
  long long int mid = (from + to) / 2;
  update(2 * v, from, mid, l, r, del);
  update(2 * v + 1, mid + 1, to, l, r, del);
  seg[v] = seg[2 * v] + seg[2 * v + 1];
}
long long int query(long long int v, long long int from, long long int to,
                    long long int l, long long int r) {
  if (lazy[v]) {
    seg[v] += (to - from + 1) * lazy[v];
    if (from != to) lazy[2 * v] += lazy[v], lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
  }
  if (from > r || l > to) return 0;
  if (l <= from && to <= r) return seg[v];
  long long int mid = (from + to) / 2;
  return query(2 * v, from, mid, l, r) + query(2 * v + 1, mid + 1, to, l, r);
}
void dfs(long long int node, long long int par, long long int &i) {
  mapping[node] = i;
  parent[0][node] = par;
  depth[node] = depth[par] + 1;
  sizes[node] = a[node];
  for (long long int e : graph[node]) {
    if (e == par) continue;
    dfs(e, node, ++i);
    sizes[node] += sizes[e];
  }
  till[node] = i;
  update(1, 1, n, mapping[node], till[node], a[node]);
}
long long int lca(long long int a, long long int b) {
  if (depth[a] < depth[b]) swap(a, b);
  long long int del = depth[a] - depth[b];
  long long int i = 19;
  while (del) {
    if (del & (1ll << i)) {
      del -= (1ll << i);
      a = parent[i][a];
    }
    i -= 1;
  }
  if (a == b) return a;
  for (long long int i = 19; i >= 0; i--) {
    if (parent[i][a] == parent[i][b]) continue;
    a = parent[i][a];
    b = parent[i][b];
  }
  return parent[0][a];
}
void solve() {
  cin >> n >> q;
  a.resize(n + 1);
  for (long long int i = 1; i <= n; i += 1) cin >> a[i], a[i] = abs(a[i]);
  long long int ch, x, y;
  for (long long int i = 1; i <= n - 1; i += 1) {
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  depth[0] = -1;
  long long int val = 1;
  dfs(1, 0, val);
  for (long long int gen = 1; gen <= 19; gen += 1) {
    for (long long int node = 1; node <= n; node += 1)
      parent[gen][node] = parent[gen - 1][parent[gen - 1][node]];
  }
  while (q--) {
    cin >> ch >> x >> y;
    if (ch == 1) {
      y = abs(y);
      long long int del = y - a[x];
      update(1, 1, n, mapping[x], till[x], del);
      a[x] = y;
    } else {
      long long int lc = lca(x, y);
      long long int ans = 0;
      if (lc == y) swap(x, y);
      if (lc == x) {
        long long int px = parent[0][x];
        ans = query(1, 1, n, mapping[y], mapping[y]) -
              query(1, 1, n, mapping[px], mapping[px]);
      } else {
        ans = query(1, 1, n, mapping[y], mapping[y]) +
              query(1, 1, n, mapping[x], mapping[x]) -
              2 * query(1, 1, n, mapping[lc], mapping[lc]) + a[lc];
      }
      ans *= 2;
      ans -= a[x] + a[y];
      cout << ans << "\n";
    }
  }
}
int main() { solve(); }
