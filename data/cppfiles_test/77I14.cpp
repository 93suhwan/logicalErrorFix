#include <bits/stdc++.h>
using namespace std;
struct dsu {
  vector<int> p;
  int n;
  dsu(int n) { resize(n); }
  dsu() {}
  void resize(int _n) {
    n = _n;
    p = vector<int>(n, -1);
  }
  int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); }
  bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      if (p[x] < p[y]) swap(x, y);
      p[y] += p[x];
      p[x] = y;
      return true;
    }
    return false;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(n * m);
  vector<int> dx = {0, 1, 0, -1};
  vector<int> dy = {-1, 0, 1, 0};
  auto encode = [&](int x, int y) { return x * m + y; };
  cout << bitset<4>(9) << endl;
  cout << bitset<4>(14) << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int v;
      cin >> v;
      for (int p = 0; p < 4; p++) {
        if (v >> p & 1) continue;
        {
          int x = i + dx[p];
          int y = j + dy[p];
          d.unite(encode(i, j), encode(x, y));
        }
      }
    }
  }
  vector<int> a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (d.get(encode(i, j)) == encode(i, j)) {
        a.push_back(-d.p[encode(i, j)]);
      }
    }
  }
  sort(a.rbegin(), a.rend());
  for (auto& x : a) cout << x << " ";
}
