#include <bits/stdc++.h>
using namespace std;
long long n, m, r, p;
long long fa[200005];
long long dfn[200005];
long long rk[200005];
long long dep[200005];
long long size1[200005];
long long son[200005];
long long top[200005];
long long bottom[200005];
long long cnt;
vector<long long> v[200005];
void dfs1(long long now, long long fanow) {
  size1[now] = 1;
  dep[now] = dep[fanow] + 1;
  long long max1 = 0;
  long long max2 = 0;
  for (long long i = 0; i < v[now].size(); i++) {
    if (v[now][i] != fanow) {
      fa[v[now][i]] = now;
      dfs1(v[now][i], now);
      size1[now] += size1[v[now][i]];
      if (size1[v[now][i]] > max1) {
        max1 = size1[v[now][i]];
        max2 = v[now][i];
      }
    }
  }
  son[now] = max2;
  return;
}
void dfs2(long long now, long long fanow) {
  dfn[now] = ++cnt;
  rk[cnt] = now;
  top[son[now]] = top[now];
  bottom[now] = dfn[now];
  if (son[now]) {
    dfs2(son[now], now);
    bottom[now] = max(bottom[now], bottom[son[now]]);
  }
  for (long long i = 0; i < v[now].size(); i++) {
    if (v[now][i] != fanow && v[now][i] != son[now]) {
      top[v[now][i]] = v[now][i];
      dfs2(v[now][i], now);
      bottom[now] = max(bottom[now], bottom[v[now][i]]);
    }
  }
  return;
}
struct node {
  long long sum;
  long long l, r;
  long long lazy;
} node[4 * 200005];
long long a[200005];
void pushup(long long now) {
  node[now].sum = node[now * 2].sum + node[now * 2 + 1].sum;
  return;
}
void build(long long now, long long l, long long r) {
  node[now].l = l;
  node[now].r = r;
  if (l == r) {
    node[now].sum = a[rk[l]];
    return;
  }
  long long mid = (l + r) >> 1;
  build(now * 2, l, mid);
  build(now * 2 + 1, mid + 1, r);
  pushup(now);
  return;
}
void change(long long now, long long l, long long r, long long x, long long y,
            long long z) {
  if (l >= x && r <= y) {
    node[now].sum = z;
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid) change(now * 2, l, mid, x, y, z);
  if (y > mid) change(now * 2 + 1, mid + 1, r, x, y, z);
  pushup(now);
  return;
}
long long query(long long now, long long l, long long r, long long x,
                long long y) {
  if (l >= x && r <= y) {
    return node[now].sum;
  }
  long long mid = (l + r) >> 1;
  long long ans = 0;
  if (x <= mid) ans += query(now * 2, l, mid, x, y);
  if (y > mid) ans += query(now * 2 + 1, mid + 1, r, x, y);
  return ans;
}
void change(long long l, long long r, long long z) {
  while (top[l] != top[r]) {
    if (dep[top[l]] < dep[top[r]]) {
      swap(l, r);
    }
    change(1, 1, n, dfn[top[l]], dfn[l], z);
    l = fa[top[l]];
  }
  if (dep[l] < dep[r]) {
    swap(l, r);
  }
  change(1, 1, n, dfn[r], dfn[l], z);
  return;
}
long long query(long long l, long long r) {
  long long ans = 0;
  while (top[l] != top[r]) {
    if (dep[top[l]] < dep[top[r]]) {
      swap(l, r);
    }
    ans += query(1, 1, n, dfn[top[l]], dfn[l]);
    l = fa[top[l]];
  }
  if (dep[l] < dep[r]) {
    swap(l, r);
  }
  ans += query(1, 1, n, dfn[r], dfn[l]);
  return ans;
}
void change(long long now, long long z) {
  change(1, 1, n, dfn[now], bottom[now], z);
  return;
}
long long query(long long now) { return query(1, 1, n, dfn[now], bottom[now]); }
long long lca(long long l, long long r) {
  while (top[l] != top[r]) {
    if (dep[top[l]] < dep[top[r]]) {
      swap(l, r);
    }
    l = fa[top[l]];
  }
  if (dep[l] < dep[r]) return l;
  return r;
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = llabs(a[i]);
  }
  for (long long i = 1; i <= n - 1; i++) {
    long long u, v1;
    cin >> u >> v1;
    v[u].push_back(v1);
    v[v1].push_back(u);
  }
  top[1] = 1;
  dfs1(1, 0);
  dfs2(1, 0);
  build(1, 1, n);
  for (long long i = 1; i <= m; i++) {
    long long opt;
    cin >> opt;
    if (opt == 1) {
      long long u, w;
      cin >> u >> w;
      w = llabs(w);
      a[u] = w;
      change(u, u, w);
    } else {
      long long u, vv;
      cin >> u >> vv;
      long long temp1 = 2 * query(u, vv) - a[u] - a[vv];
      cout << temp1 << endl;
    }
  }
  return 0;
}
