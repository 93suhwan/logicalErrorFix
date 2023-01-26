#include <bits/stdc++.h>
using namespace std;
struct segtree {
  vector<long long> v;
  long long size;
  void init(long long n) {
    size = 1;
    while (size < n) size *= 2;
    v.resize(size * 2, 0);
  }
  void set(long long x, long long val) { set(x, val, 0, 0, size); }
  void set(long long x, long long val, long long cur, long long lx,
           long long rx) {
    if (rx - lx == 1) {
      v[cur] = val;
    } else {
      long long mid = (lx + rx) / 2;
      if (x < mid) {
        set(x, val, 2 * cur + 1, lx, mid);
      } else {
        set(x, val, 2 * cur + 2, mid, rx);
      }
      v[cur] = v[2 * cur + 1] + v[2 * cur + 2];
    }
  }
  long long get(long long l, long long r) { return get(l, r, 0, 0, size); }
  long long get(long long l, long long r, long long cur, long long lx,
                long long rx) {
    if (l >= rx or r <= lx) {
      return (long long)0;
    }
    if (l <= lx and r >= rx) {
      return v[cur];
    }
    long long m = (lx + rx) / 2;
    return (get(l, r, 2 * cur + 1, lx, m) + get(l, r, 2 * cur + 2, m, rx));
  }
};
struct HLD {
  long long cnt;
  vector<long long> depth, sz, parent, tp, idx;
  segtree st;
  HLD(vector<vector<long long> > &gr, long long root) {
    long long n = gr.size();
    depth.resize(n, -1);
    st.init(n + 1);
    sz.resize(n, 0);
    parent.resize(n, 0);
    tp.resize(n, 0);
    idx.resize(n, 0);
    dfs_sz(gr, root, root);
    cnt = 0;
    dfs_hld(gr, root, root, root);
  }
  long long dfs_sz(vector<vector<long long> > &gr, long long cur,
                   long long par) {
    depth[cur] = depth[par] + 1;
    sz[cur] = 1;
    parent[cur] = par;
    for (auto x : gr[cur]) {
      if (x == par) continue;
      sz[cur] += dfs_sz(gr, x, cur);
    }
    return sz[cur];
  }
  void dfs_hld(vector<vector<long long> > &gr, long long cur, long long par,
               long long top) {
    tp[cur] = top;
    idx[cur] = cnt++;
    long long mx_sz = -1, mx_child = -1;
    for (auto x : gr[cur]) {
      if (x == par) continue;
      if (sz[x] > mx_sz) {
        mx_sz = sz[x];
        mx_child = x;
      }
    }
    if (mx_child == -1) return;
    dfs_hld(gr, mx_child, cur, top);
    for (auto x : gr[cur]) {
      if (x == par or x == mx_child) continue;
      dfs_hld(gr, x, cur, x);
    }
  }
  long long path(long long x, long long y) {
    long long ans =
        -((st.get(idx[x], idx[x] + 1) + st.get(idx[y], idx[y] + 1)) / 2ll);
    while (tp[x] != tp[y]) {
      if (depth[tp[x]] < depth[tp[y]]) swap(x, y);
      ans += st.get(idx[tp[x]], idx[x] + 1);
      x = parent[tp[x]];
    }
    if (depth[x] > depth[y]) swap(x, y);
    ans += st.get(idx[x], idx[y] + 1);
    return ans;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, q;
  cin >> n >> q;
  vector<vector<long long> > gr(n);
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  for (long long i = 0; i + 1 < n; ++i) {
    long long x, y;
    cin >> x >> y;
    --x;
    --y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  HLD h(gr, 0);
  for (long long i = 0; i < n; ++i) {
    h.st.set(h.idx[i], 2ll * abs(a[i]));
  }
  while (q--) {
    long long ch, x, y;
    cin >> ch >> x >> y;
    if (ch == 1) {
      h.st.set(h.idx[x - 1], 2ll * abs(y));
    } else {
      --x;
      --y;
      cout << h.path(x, y) << "\n";
    }
  }
  return 0;
}
