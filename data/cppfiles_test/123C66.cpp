#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20, inf = 1e6 + 20;
vector<int> adj[N];
bool hazf[N];
int lazy[N << 2], h[N], ziad[N], par[N];
pair<int, int> pos[N], seg[N << 2];
vector<int> vt;
int n, k;
void dfs(int u, int pp = -1) {
  pos[u].first = (int)vt.size();
  vt.push_back(u);
  for (int v : adj[u]) {
    if (v == pp) continue;
    h[v] = h[u] + 1;
    par[v] = u;
    dfs(v, u);
  }
  pos[u].second = (int)vt.size();
  return;
}
void build(int u = 1, int s = 0, int e = n) {
  seg[u] = {h[vt[s]], vt[s]};
  if (e - s < 2) return;
  int lc = u << 1, rc = lc | 1, mid = (s + e) >> 1;
  build(lc, s, mid);
  build(rc, mid, e);
  seg[u] = max(seg[lc], seg[rc]);
  return;
}
inline void put(int u, int x) {
  lazy[u] += x;
  seg[u].first += x;
  return;
}
inline void shift(int u, int s, int e) {
  if (e - s >= 2 && lazy[u] != 0) {
    int lc = u << 1, rc = lc | 1;
    put(lc, lazy[u]);
    put(rc, lazy[u]);
    lazy[u] = 0;
  }
  return;
}
void add(int l, int r, int x, int u = 1, int s = 0, int e = n) {
  if (e <= l || r <= s) return;
  if (l <= s && r >= e) {
    put(u, x);
    return;
  }
  shift(u, s, e);
  int lc = u << 1, rc = lc | 1, mid = (s + e) >> 1;
  add(l, r, x, lc, s, mid);
  add(l, r, x, rc, mid, e);
  seg[u] = max(seg[lc], seg[rc]);
  return;
}
pair<int, int> get(int l, int r, int u = 1, int s = 0, int e = n) {
  if (e <= l || r <= s) return {-inf, -inf};
  if (l <= s && r >= e) return seg[u];
  shift(u, s, e);
  int lc = u << 1, rc = lc | 1, mid = (s + e) >> 1;
  return max(get(l, r, lc, s, mid), get(l, r, rc, mid, e));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  h[0] = 1;
  dfs(0);
  build();
  int tt = 0;
  while (true) {
    pair<int, int> pp = get(0, n);
    if (pp.first <= 0) break;
    int u = pp.second;
    ziad[tt++] = pp.first;
    while (!hazf[u]) {
      hazf[u] = true;
      add(pos[u].first, pos[u].first + 1, -inf);
      add(pos[u].first, pos[u].second, -1);
      u = par[u];
    }
  }
  long long ans = -1e16;
  int xxx = 0;
  for (int i = 1; i <= k; i++) {
    xxx += ziad[i - 1];
    int y = n - xxx;
    if (i >= y) {
      ans = max(ans, 1ll * (n - i - y) * (i - y));
      continue;
    }
    int w = n - i - y;
    y -= i;
    int maj = y + w;
    y = min(y, (y + w) / 2);
    ans = max(ans, -1ll * y * (maj - y));
  }
  cout << ans;
  return 0;
}
