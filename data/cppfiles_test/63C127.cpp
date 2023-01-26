#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
const long long N = 1e3 + 9;
struct DSU {
  long long connected;
  long long par[N], sz[N];
  void init(long long n) {
    for (long long i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
    connected = n;
  }
  long long getPar(long long k) {
    if (par[k] == k) return k;
    return par[k] = getPar(par[k]);
  }
  long long getSize(long long k) { return sz[getPar(k)]; }
  void unite(long long u, long long v) {
    long long par1 = getPar(u), par2 = getPar(v);
    if (par1 == par2) return;
    connected--;
    if (sz[par1] > sz[par2]) swap(par1, par2);
    sz[par2] += sz[par1];
    sz[par1] = 0;
    par[par1] = par[par2];
  }
};
void solve() {
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  DSU dsu1, dsu2;
  dsu1.init(n);
  dsu2.init(n);
  while (m1--) {
    long long u, v;
    cin >> u >> v;
    dsu1.unite(u, v);
  }
  while (m2--) {
    long long u, v;
    cin >> u >> v;
    dsu2.unite(u, v);
  }
  vector<pair<long long, long long>> v;
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (dsu1.getPar(i) != dsu1.getPar(j) &&
          dsu2.getPar(i) != dsu2.getPar(j)) {
        v.push_back({i, j});
        dsu1.unite(i, j);
        dsu2.unite(i, j);
      }
    }
  }
  cout << v.size() << "\n";
  for (auto c : v) cout << c.first << " " << c.second << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  while (t--) solve();
  return 0;
}
