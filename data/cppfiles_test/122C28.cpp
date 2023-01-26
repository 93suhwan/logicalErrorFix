#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long N = 3e5 + 9;
struct DSU {
  vector<long long> par, sz, w;
  DSU(long long n) {
    par.resize(n + 1);
    sz.resize(n + 1);
    w.resize(n + 1);
    for (long long i = 1; i <= n; i++) par[i] = i, sz[i] = 1, w[i] = 0;
  }
  pair<long long, long long> find(long long u) {
    long long ans = 0;
    while (par[u] != u) {
      ans ^= w[u];
      u = par[u];
    }
    return {u, ans};
  }
  void merge(long long u, long long v, long long x) {
    auto a = find(u), b = find(v);
    long long p1 = a.first, w1 = a.second, p2 = b.first, w2 = b.second;
    if (p1 == p2) return;
    if (sz[p1] > sz[p2]) swap(p1, p2);
    par[p1] = p2;
    sz[p2] += sz[p1];
    w[p1] = (w1 ^ w2 ^ x);
  }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  DSU dsu(n);
  vector<array<long long, 3>> edge;
  for (long long i = 1; i < n; i++) {
    long long u, v, x;
    cin >> u >> v >> x;
    edge.push_back({u, v, x});
    if (x != -1) dsu.merge(u, v, x);
  }
  long long ok = 1;
  while (m--) {
    long long u, v, x;
    cin >> u >> v >> x;
    auto a = dsu.find(u), b = dsu.find(v);
    if (a.first == b.first) {
      long long tmp = __builtin_popcount(a.second ^ b.second);
      if ((tmp) % 2 != x) {
        ok = 0;
      }
    } else {
      dsu.merge(a.first, b.first, a.second ^ b.second ^ x);
    }
  }
  if (!ok) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (long long i = 0; i + 1 < n; i++) {
    long long u = edge[i][0], v = edge[i][1], x = edge[i][2];
    if (x != -1) {
      cout << u << " " << v << " " << x << "\n";
      continue;
    }
    auto a = dsu.find(u), b = dsu.find(v);
    cout << u << " " << v << " " << (a.second ^ b.second) << "\n";
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
