#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using pil = pair<long long, long long>;
using pid = pair<double, double>;
long long mod = 1e9 + 7;
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res = (res * a) % mod;
    a = (a * a) % mod;
    n /= 2;
  }
  return res;
}
struct dsu {
  vector<long long> par, sze;
  void make_set(long long n) {
    par.resize(n + 1);
    sze.resize(n + 1);
    iota((par).begin(), (par).end(), 0LL);
  }
  long long get(long long x) {
    return (par[x] = (par[x] == x ? x : get(par[x])));
  }
  void unite(long long x, long long y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return;
    }
    if (sze[x] > sze[y]) {
      swap(x, y);
    }
    sze[y] += sze[x];
    par[x] = y;
  }
};
void solve() {
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu d1;
  dsu d2;
  d1.make_set(n + 1);
  d2.make_set(n + 1);
  for (long long i = 0; i < m1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    d1.unite(u, v);
  }
  for (long long i = 0; i < m2; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    d2.unite(u, v);
  }
  vector<pair<long long, long long> > v;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (d1.get(i) != d1.get(j) && d2.get(i) != d2.get(j)) {
        d1.unite(i, j);
        d2.unite(i, j);
        v.push_back({i + 1, j + 1});
      }
    }
  }
  cout << v.size() << endl;
  for (auto i : v) cout << i.first << " " << i.second << endl;
}
int32_t main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
