#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5 + 5;
int cnt;
vector<int> ad[mxN];
int in[mxN];
int dep[mxN];
int sz[mxN];
int par[mxN];
int timer;
int tree[4 * mxN];
int lazy[4 * mxN];
int id[4 * mxN];
bool removed[mxN];
void dfs(int u, int p) {
  par[u] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  in[u] = ++timer;
  for (int v : ad[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
void propagate(int x, int lx, int rx) {
  if (lx == rx) return;
  lazy[x << 1] += lazy[x];
  lazy[x << 1 | 1] += lazy[x];
  tree[x << 1] += lazy[x];
  tree[x << 1 | 1] += lazy[x];
  lazy[x] = 0;
}
void update(int x, int lx, int rx, int l, int r, int del) {
  if (lazy[x]) propagate(x, lx, rx);
  if (l > rx || lx > r) return;
  if (lx == rx) id[x] = lx;
  if (l <= lx && r >= rx) {
    tree[x] += del;
    lazy[x] += del;
    return;
  }
  int mx = (lx + rx) >> 1;
  update(x << 1, lx, mx, l, r, del);
  update(x << 1 | 1, mx + 1, rx, l, r, del);
  tree[x] = max(tree[x << 1], tree[x << 1 | 1]);
  if (tree[x << 1] > tree[x << 1 | 1])
    id[x] = id[x << 1];
  else
    id[x] = id[x << 1 | 1];
}
pair<int, int> query(int x, int lx, int rx, int l, int r) {
  if (lazy[x]) propagate(x, lx, rx);
  if (l > rx || lx > r) return {0, 0};
  if (l <= lx && r >= rx) return {tree[x], id[x]};
  int mx = (lx + rx) >> 1;
  auto a = query(x << 1, lx, mx, l, r);
  auto b = query(x << 1 | 1, mx + 1, rx, l, r);
  if (a.first > b.first) return a;
  return b;
}
long long mini(long long w, long long r, long long n) {
  long long b = 2 * w + 2 * r - n;
  vector<long long> v = {0, n - w - r, -b / 2, -b / 2 + 1, -b / 2 - 1};
  long long ret = 1e18;
  for (long long x : v) {
    if (x >= 0 && x <= n - w - r) ret = min(ret, x * x + b * x);
  }
  return ret;
}
void testCase() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    ad[u].push_back(v);
    ad[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 2; i <= n; i++) {
    if (ad[i].size() == 1) {
      cnt++;
      update(1, 1, n, in[i], in[i], dep[i] - 1);
    }
  }
  removed[0] = true;
  long long ans = -1e18;
  long long wp = 0;
  for (long long r = 1; r <= k; r++) {
    auto q = query(1, 1, n, 1, n);
    if (cnt > 0) {
      wp += q.first;
      int cur = q.second;
      update(1, 1, n, in[cur], in[cur], -q.first);
      int top = cur;
      while (!removed[top]) top = par[top];
      int prev = cur;
      while (!removed[cur]) {
        for (int v : ad[cur]) {
          if (v == prev || v == par[cur]) continue;
          update(1, 1, n, in[v], in[v] + sz[v] - 1, -(dep[cur] - dep[top]));
        }
        prev = cur;
        removed[cur] = true;
        cur = par[cur];
      }
      cnt--;
    } else {
      wp--;
    }
    long long val = wp * r - wp * n + wp * wp + wp * r + mini(wp, r, n);
    ans = max(ans, val);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  testCase();
  return 0;
}
