#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
const int N = 2e5 + 10;
int f[N], d[N], parity[N], ans[N];
int fa[N];
struct edge {
  int a, b;
  int v;
};
int find(int x) {
  if (x == f[x]) return x;
  int t = f[x];
  f[x] = find(f[x]);
  d[x] ^= d[t];
  return f[x];
}
void merge(int a, int b, int c) {
  int fa = find(a);
  int fb = find(b);
  int dist = d[a] ^ d[b] ^ c;
  f[fa] = fb;
  d[fa] = dist;
}
void dfs(int u, int father) {
  fa[u] = father;
  for (int j : adj[u]) {
    if (j == father) continue;
    dfs(j, u);
  }
}
int lowbit(int x) { return x & -x; }
int count(int x) {
  int cnt = 0;
  while (x) {
    x -= lowbit(x);
    cnt++;
  }
  return cnt;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<edge> a;
  set<int> s;
  vector<int> st(n + 1, 0);
  st[1] = 1;
  adj.clear();
  adj.resize(n + 1);
  for (int i = 1; i <= n; i++) f[i] = i, d[i] = 0;
  for (int i = 0; i < n - 1; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    adj[x].push_back(y), adj[y].push_back(x);
    if (v != -1) {
      s.insert(v);
      a.push_back({x, y, v});
    }
  }
  dfs(1, 0);
  bool ok = true;
  for (auto tem : a) {
    int x = tem.a, y = tem.b, v = tem.v;
    if (fa[x] == y) swap(x, y);
    ans[y] = v;
    st[y] = 1;
    merge(x, y, count(v) & 1);
  }
  while (m--) {
    int x, y, v;
    cin >> x >> y >> v;
    if (find(x) == find(y)) {
      if (d[x] ^ d[y] != v) {
        ok = false;
      }
    } else {
      merge(x, y, v);
    }
  }
  for (int i = 1; i <= n; i++) find(i);
  for (int i = 1; i <= n; i++) {
    if (st[i]) continue;
    ans[i] = d[fa[i]] ^ d[i];
  }
  if (ok) {
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
      if (!fa[i])
        continue;
      else
        cout << i << ' ' << fa[i] << ' ' << ans[i] << '\n';
    }
  } else
    puts("NO");
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
