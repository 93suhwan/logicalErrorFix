#include <bits/stdc++.h>
using namespace std;
struct dsu {
  vector<long long> p;
  long long n;
  dsu(long long n) : n(n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline long long get(long long x) { return x == p[x] ? x : p[x] = get(p[x]); }
  inline bool unite(long long x, long long y) {
    x = get(x), y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
signed main() {
  cin.tie(0)->sync_with_stdio(false);
  long long T;
  cin >> T;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    dsu d(2 * n);
    vector<long long> x(n - 1), y(n - 1), v(n - 1);
    for (long long i = 0; i + 1 < n; ++i) {
      cin >> x[i] >> y[i] >> v[i];
      --x[i], --y[i];
      if (v[i] >= 0) {
        long long t = __builtin_popcount(v[i]) % 2;
        if (t == 0) {
          d.unite(x[i], y[i]);
          d.unite(x[i] + n, y[i] + n);
        } else {
          d.unite(x[i], y[i] + n);
          d.unite(x[i] + n, y[i]);
        }
      }
    }
    for (long long i = 0; i < m; ++i) {
      long long a, b, p;
      cin >> a >> b >> p;
      --a, --b;
      if (p == 0) {
        d.unite(a, b);
        d.unite(a + n, b + n);
      } else {
        d.unite(a, b + n);
        d.unite(a + n, b);
      }
    }
    bool ok = true;
    for (long long i = 0; i < n; ++i) {
      if (d.get(i) == d.get(i + n)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (long long i = 1; i < n; ++i) {
      if (d.get(i) == d.get(0) || d.get(i + n) == d.get(0)) {
        continue;
      }
      d.unite(0, i);
      d.unite(0 + n, i + n);
    }
    for (long long i = 0; i + 1 < n; ++i) {
      if (v[i] == -1) {
        if (d.get(x[i]) == d.get(y[i]))
          v[i] = 0;
        else
          v[i] = 1;
      }
      cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << v[i] << '\n';
    }
  }
  return 0;
}
