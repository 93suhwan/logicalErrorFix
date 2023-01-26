#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
const long long M = 1e6 + 11;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 998244353;
const double EPS = 1e-9;
const long long block = 1e14;
const long long shift = 2e3;
const double pi = acos(-1.0);
long long n, q;
long long a[N], b[N], c[N];
vector<pair<long long, long long> > g[N];
struct DSU {
  long long p[N], sz[N];
  void init(long long n) {
    for (int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
  }
  long long fnd(long long a) { return p[a] = (p[a] == a ? a : fnd(p[a])); }
  void unt(long long a, long long b) {
    a = fnd(a), b = fnd(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
  }
} ds;
struct seg {
  long long t[4 * N] = {0};
  long long u[4 * N] = {0};
  void push(long long v, long long l, long long r) {
    if (u[v]) {
      t[v] = u[v];
      if (l != r) u[v * 2] = u[v * 2 + 1] = u[v];
    }
  }
  void upd(long long l, long long r, long long v = 1, long long tl = 1,
           long long tr = n + 10) {
    push(v, tl, tr);
    if (l > tr || tl > r || l > r) return;
    if (l <= tl && tr <= r) {
      u[v] = 1;
      push(v, tl, tr);
      return;
    }
    long long m = (tl + tr) >> 1ll;
    upd(l, r, v * 2, tl, m);
    upd(l, r, v * 2 + 1, m + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
  long long get(long long l, long long r, long long v = 1, long long tl = 1,
                long long tr = n + 10) {
    push(v, tl, tr);
    if (l > tr || tl > r || l > r) return 0;
    if (l <= tl && tr <= r) return t[v];
    long long m = (tl + tr) >> 1ll;
    return max(get(l, r, v * 2, tl, m), get(l, r, v * 2 + 1, m + 1, tr));
  }
} rt;
long long bp[N][21], xr[N], sz[N], tin[N], tout[N];
long long hp[N];
void dfs(long long v, long long p) {
  for (int i = 1; i < 20; i++) bp[v][i] = bp[bp[v][i - 1]][i - 1];
  sz[v] = 1;
  for (auto u : g[v])
    if (u.first != p)
      bp[u.first][0] = v, xr[u.first] = u.second ^ xr[v], dfs(u.first, v),
      sz[v] += sz[u.first];
}
void hldfs(long long v, long long p, long long pr) {
  hp[v] = pr;
  tin[v] = tout[0]++;
  for (auto u : g[v])
    if (u.first != p && sz[u.first] * 2 > sz[v]) hldfs(u.first, v, pr);
  for (auto u : g[v])
    if (u.first != p && sz[u.first] * 2 <= sz[v]) hldfs(u.first, v, u.first);
  tout[v] = tout[0];
}
bool upper(long long a, long long b) {
  return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}
long long LCA(long long a, long long b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int j = 19; j >= 0; j--)
    if (!upper(bp[a][j], b)) a = bp[a][j];
  return bp[a][0];
}
long long pLCA(long long a, long long b) {
  if (upper(a, b)) return -1;
  for (int j = 19; j >= 0; j--)
    if (!upper(bp[a][j], b)) a = bp[a][j];
  return a;
}
long long pxr(long long x, long long y) { return xr[x] ^ xr[y]; }
void UpdBamboo(long long v, long long x) {
  while (1) {
    long long hm = hp[v];
    if (hm == hp[x]) hm = x;
    rt.upd(tin[hm], tin[v]);
    if (hm == x) break;
    v = bp[hm][0];
  }
}
long long GetBamboo(long long v, long long x) {
  long long z = 0;
  while (1) {
    long long hm = hp[v];
    if (hm == hp[x]) hm = x;
    z = max(z, rt.get(tin[hm], tin[v]));
    if (hm == x) break;
    v = bp[hm][0];
  }
  return z;
}
void UpdPath(long long x, long long y) {
  long long z = pLCA(x, y);
  if (z != -1) UpdBamboo(x, z);
  z = pLCA(y, x);
  if (z != -1) UpdBamboo(y, z);
}
long long getPath(long long x, long long y) {
  long long z = pLCA(x, y);
  long long ans = 0;
  if (z != -1) ans = max(ans, GetBamboo(x, z));
  z = pLCA(y, x);
  if (z != -1) ans = max(ans, GetBamboo(y, z));
  return ans;
}
bool READY[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  ds.init(n);
  tout[0] = 1ll;
  for (int i = 1; i <= q; i++) cin >> a[i] >> b[i] >> c[i];
  for (int i = 1; i <= q; i++) {
    if (ds.fnd(a[i]) != ds.fnd(b[i]))
      ds.unt(a[i], b[i]), g[a[i]].push_back(make_pair(b[i], c[i])),
          g[b[i]].push_back(make_pair(a[i], c[i])), READY[i] = 1;
  }
  dfs(1, 0);
  hldfs(1, 0, 1);
  for (int i = 1; i <= q; i++) {
    if (READY[i])
      cout << "YES\n";
    else {
      long long z = pxr(a[i], b[i]);
      if (z == c[i] || getPath(a[i], b[i])) {
        cout << "NO\n";
        continue;
      }
      UpdPath(a[i], b[i]);
      cout << "YES\n";
    }
  }
}
