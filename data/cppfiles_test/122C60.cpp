#include <bits/stdc++.h>
using namespace std;
class Dsu {
 public:
  vector<int> p, sz;
  int n;
  Dsu(int _n) {
    n = _n + 1;
    p.resize(n);
    sz.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      sz[y] += sz[x];
      return true;
    }
    return false;
  }
  inline int getSize(int x) { return sz[get(x)]; }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(n - 1);
    vector<int> y(n - 1);
    vector<int> v(n - 1);
    Dsu d(2 * n);
    for (int i = 0; i < n - 1; i++) {
      cin >> x[i] >> y[i] >> v[i];
      --x[i];
      --y[i];
      if (v[i] != -1) {
        int c = (int)__builtin_popcount(v[i]);
        if (c & 1) {
          d.unite(x[i], y[i] + n);
          d.unite(x[i] + n, y[i]);
        } else {
          d.unite(x[i], y[i]);
          d.unite(x[i] + n, y[i] + n);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      if (c & 1) {
        d.unite(a, b + n);
        d.unite(a + n, b);
      } else {
        d.unite(a, b);
        d.unite(a + n, b + n);
      }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
      flag &= (d.get(i) != d.get(i + n));
    }
    if (!flag) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    vector<int> color(n, -1);
    vector<bool> used(2 * n, false);
    for (int i = 0; i < n; i++) {
      if (!used[d.get(i)] && !used[d.get(i + n)]) {
        color[i] = 0;
        used[d.get(i)] = true;
      } else if (used[d.get(i)]) {
        color[i] = 0;
      } else if (used[d.get(i + n)]) {
        color[i] = 1;
      } else {
        assert(false);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (v[i] == -1) {
        if (color[x[i]] == color[y[i]]) {
          v[i] = 0;
        } else {
          v[i] = 1;
        }
      }
      cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << v[i] << '\n';
    }
  }
  return 0;
}
