#include <bits/stdc++.h>
#pragma optimize("g", on)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("03")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
using namespace std;
const long long inf = (1ll << 62ll), N = 1e5 + 5, mod = 1e9 + 7;
vector<pair<long long, long long> > dd = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
long long p1[N], p2[N];
long long get1(long long x) {
  if (p1[x] == x) return x;
  return p1[x] = get1(p1[x]);
}
long long get2(long long x) {
  if (p2[x] == x) return x;
  return p2[x] = get2(p2[x]);
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  set<pair<long long, long long> > s;
  for (long long i = 1; i <= n; i++) {
    p1[i] = i;
    p2[i] = i;
    for (long long j = i + 1; j <= n; j++) s.insert({i, j});
  }
  while (m1--) {
    long long u, v;
    cin >> u >> v;
    s.erase({min(u, v), max(u, v)});
    u = get1(u);
    v = get1(v);
    if (u != v) p1[u] = v;
  }
  while (m2--) {
    long long u, v;
    cin >> u >> v;
    s.erase({min(u, v), max(u, v)});
    u = get2(u);
    v = get2(v);
    if (u != v) p2[u] = v;
  }
  vector<pair<long long, long long> > ans;
  for (auto e : s) {
    long long u = e.first, v = e.second;
    long long u2 = get2(u), v2 = get2(v);
    u = get1(u);
    v = get1(v);
    if (u == v || u2 == v2) continue;
    ans.push_back({e.first, e.second});
    p1[u] = v;
    p2[u2] = v2;
  }
  cout << ans.size() << '\n';
  for (auto e : ans) cout << e.first << ' ' << e.second << '\n';
}
