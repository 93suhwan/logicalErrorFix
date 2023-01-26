#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
long long n, q;
long long deep[maxn], fa[maxn], top[maxn], siz[maxn], son[maxn], id[maxn];
vector<long long> ve[maxn];
long long cnt = 0;
long long a[maxn];
long long dfs1(long long u, long long f, long long d) {
  deep[u] = d;
  fa[u] = f;
  siz[u] = 1;
  for (auto v : ve[u]) {
    if (v == f) continue;
    dfs1(v, u, d + 1);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
  return 0;
}
long long dfs2(long long u, long long topf) {
  id[u] = ++cnt;
  top[u] = topf;
  if (!son[u]) return 0;
  dfs2(son[u], topf);
  for (auto v : ve[u]) {
    if (v == fa[u] || v == son[u]) continue;
    dfs2(v, v);
  }
  return 0;
}
const long long maxm = maxn << 2;
long long szsz[maxm];
long long update(long long x, long long y) {
  while (x < maxm) {
    szsz[x] += y;
    x += (x & (-x));
  }
  return 0;
}
long long query(long long x) {
  long long ret = 0;
  while (x) {
    ret += szsz[x];
    x -= (x & (-x));
  }
  return ret;
}
long long val[maxn];
inline long long calc(long long x, long long y) {
  return max(abs(x + y), abs(x - y));
}
long long dfs3(long long u, long long f) {
  for (auto v : ve[u]) {
    if (v == f) continue;
    val[v] = calc(a[u], a[v]);
    dfs3(v, u);
  }
  return 0;
}
long long qrange(long long x, long long y) {
  if (x == y) return 0;
  long long ans = 0;
  while (top[x] != top[y]) {
    if (deep[top[x]] < deep[top[y]]) swap(x, y);
    if (x != top[x]) {
      ans += query(id[x]) - query(id[top[x]]);
    } else {
      ans += calc(a[x], a[fa[x]]);
    }
    ans += calc(a[top[x]], a[fa[top[x]]]);
    x = fa[top[x]];
  }
  if (deep[x] > deep[y]) swap(x, y);
  ans += query(id[y]) - query(id[x]);
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    ve[u].push_back(v);
    ve[v].push_back(u);
  }
  dfs1(1, -1, 1);
  dfs2(1, 1);
  dfs3(1, -1);
  for (long long i = 1; i <= n; i++) {
    update(id[i], val[i]);
  }
  for (long long i = 1; i <= q; i++) {
    long long op, s, t;
    cin >> op >> s >> t;
    if (op == 1) {
      a[s] = t;
      if (son[s]) {
        long long val = query(id[son[s]]) - query(id[s]);
        update(id[son[s]], -val);
        update(id[son[s]], calc(a[s], a[son[s]]));
      }
      if (fa[s] != -1 && son[fa[s]] == s) {
        long long val = query(id[s]) - query(id[fa[s]]);
        update(id[s], -val);
        update(id[s], calc(a[s], a[fa[s]]));
      }
    } else {
      cout << qrange(s, t) << '\n';
    }
  }
  return 0;
}
