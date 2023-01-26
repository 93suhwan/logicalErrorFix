#include <bits/stdc++.h>
using namespace std;
using namespace std;
const long long N = 1e5 + 5;
const long long D = 19;
const long long S = (1 << D);
long long n, q, v[N];
vector<long long> adj[N];
long long sz[N], p[N], dep[N];
long long st[S], id[N], tp[N];
void update(long long idx, long long val) {
  st[idx += n] = val;
  for (idx /= 2; idx; idx /= 2) st[idx] = st[2 * idx] + st[2 * idx + 1];
}
long long query(long long lo, long long hi) {
  long long ra = 0, rb = 0;
  for (lo += n, hi += n + 1; lo < hi; lo /= 2, hi /= 2) {
    if (lo & 1) ra += st[lo++];
    if (hi & 1) rb += st[--hi];
  }
  return ra + rb;
}
long long dfs_sz(long long cur, long long par) {
  sz[cur] = 1;
  p[cur] = par;
  for (long long chi : adj[cur]) {
    if (chi == par) continue;
    dep[chi] = dep[cur] + 1;
    p[chi] = cur;
    sz[cur] += dfs_sz(chi, cur);
  }
  return sz[cur];
}
long long ct = 1;
void dfs_hld(long long cur, long long par, long long top) {
  id[cur] = ct++;
  tp[cur] = top;
  update(id[cur], v[cur]);
  long long h_chi = -1, h_sz = -1;
  for (long long chi : adj[cur]) {
    if (chi == par) continue;
    if (sz[chi] > h_sz) {
      h_sz = sz[chi];
      h_chi = chi;
    }
  }
  if (h_chi == -1) return;
  dfs_hld(h_chi, cur, top);
  for (long long chi : adj[cur]) {
    if (chi == par || chi == h_chi) continue;
    dfs_hld(chi, cur, chi);
  }
}
long long path(long long x, long long y) {
  long long ret = 0;
  while (tp[x] != tp[y]) {
    if (dep[tp[x]] < dep[tp[y]]) swap(x, y);
    ret += query(id[tp[x]], id[x]);
    x = p[tp[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  ret += query(id[x], id[y]);
  return ret;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] = abs(v[i]);
  }
  for (long long i = 2; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs_sz(1, 1);
  dfs_hld(1, 1, 1);
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long s, x;
      cin >> s >> x;
      v[s] = abs(x);
      update(id[s], v[s]);
    } else {
      long long a, b;
      cin >> a >> b;
      long long res = 2 * path(a, b) - v[a] - v[b];
      cout << res << "\n";
    }
  }
}
