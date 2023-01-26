#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int INF = 1e9;
const long long INFLL = 1e18;
mt19937 rnd(time(nullptr));
class DSU {
 public:
  vector<int> p, rang;
  int n;
  DSU(int n) : n(n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    rang.resize(n, 1);
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      rang[i] = 1;
    }
  }
  int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  bool unite(int x, int y) {
    int z = x;
    x = get(x);
    y = get(y);
    if (rang[x] < rang[y]) {
      swap(x, y);
    }
    if (x != y) {
      p[y] = x;
      rang[x] += (rang[x] == rang[y]);
      return true;
    }
    return false;
  }
};
void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  DSU G1(n), G2(n);
  for (int i = 0; i < m1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    G1.unite(x, y);
  }
  for (int i = 0; i < m2; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    G2.unite(x, y);
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (G1.get(i) != G1.get(j) && G2.get(i) != G2.get(j)) {
        ans.push_back({i, j});
        G1.unite(i, j);
        G2.unite(i, j);
      }
    }
  }
  cout << ans.size() << endl;
  for (auto& [x, y] : ans) {
    cout << x + 1 << ' ' << y + 1 << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
}
