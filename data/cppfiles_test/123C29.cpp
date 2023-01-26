#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> g;
vector<long long> p;
vector<long long> lf, rf;
vector<long long> ln;
vector<long long> d;
void cntLeaves(long long u, long long p1, long long d1) {
  lf[u] = ln.size();
  p[u] = p1;
  long long cnt = 0;
  long long child = 0;
  for (long long v : g[u]) {
    if (v == p1) continue;
    child++;
    cntLeaves(v, u, d1 + 1);
  }
  if (child == 0) {
    ln.push_back(u);
    d.push_back(d1);
  }
  rf[u] = ln.size();
}
struct SegTree {
  vector<pair<long long, long long>> t;
  vector<long long> lz;
  SegTree(long long n) : t(4 * n), lz(4 * n){};
  void create(long long id, long long l, long long r,
              const vector<long long> &a) {
    if (r - l == 1) {
      t[id] = {a[l], l};
      return;
    }
    long long m = (l + r) >> 1;
    create((id << 1), l, m, a);
    create(((id << 1) + 1), m, r, a);
    t[id] = max(t[(id << 1)], t[((id << 1) + 1)]);
  }
  void push(long long id) {
    lz[(id << 1)] += lz[id];
    lz[((id << 1) + 1)] += lz[id];
    t[(id << 1)].first += lz[id];
    t[((id << 1) + 1)].first += lz[id];
    lz[id] = 0;
  }
  void update(long long id, long long l, long long r, long long l1,
              long long r1, long long del) {
    if (l1 == r1) return;
    if (l == l1 and r == r1) {
      t[id].first += del;
      lz[id] += del;
      return;
    }
    push(id);
    long long m = (l + r) >> 1;
    update((id << 1), l, m, min(l1, m), min(r1, m), del);
    update(((id << 1) + 1), m, r, max(l1, m), max(r1, m), del);
    t[id] = max(t[(id << 1)], t[((id << 1) + 1)]);
  }
};
void test() {
  long long n, k;
  cin >> n >> k;
  g.assign(n, vector<long long>());
  lf.assign(n, 0);
  rf.assign(n, 0);
  ln.clear();
  p.assign(n, 0);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cntLeaves(0ll, -1ll, 1);
  long long leaves = rf[0];
  if (k >= leaves) {
    if (n / 2 >= leaves and n / 2 <= k) {
      cout << (n / 2) * ((n + 1) / 2) << '\n';
      return;
    }
    long long res = 0;
    for (long long v : {leaves, k}) {
      res = max(res, v * (n - v));
    }
    cout << res << '\n';
    return;
  }
  SegTree seg(4 * ln.size());
  seg.create(1, 0, ln.size(), d);
  long long all = 0;
  vector<long long> visited(n);
  for (long long i = 0; i < k; i++) {
    all += seg.t[1].first;
    long long leave = ln[seg.t[1].second];
    for (long long u = leave; u != -1 and not visited[u]; u = p[u]) {
      seg.update(1, 0, ln.size(), lf[u], rf[u], -1);
      visited[u] = true;
    }
  }
  long long red = k;
  long long white = all - k;
  long long blue = n - red - white;
  long long blueAc = blue >= n / 2 ? n / 2 : blue;
  long long whiteAc = n - red - blueAc;
  cout << whiteAc * (red - blueAc) << '\n';
}
signed main() {
  iostream::sync_with_stdio(false);
  long long q = 1;
  while (q--) test();
  assert(cin);
}
