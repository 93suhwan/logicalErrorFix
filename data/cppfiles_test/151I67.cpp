#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = (int)0x3f3f3f3f3f3f3f3f, ninf = (int)0xc0c0c0c0c0c0c0c0;
using ll = long long;
using ld = long double;
void solve() {
  const int N = (int)5e5 + 3;
  vector<int> p(N, -1);
  function<int(int)> root = [&](int u) -> int {
    return p[u] < 0 ? u : p[u] = root(p[u]);
  };
  function<bool(int, int)> unite = [&](int u, int v) -> bool {
    if ((u = root(u)) == (v = root(v))) return 0;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
  };
  int q;
  cin >> q;
  int id = 0;
  vector<int> prev(N), color(N);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      ++id;
      if (prev[x]) {
        unite(id, prev[x]);
      } else {
        prev[x] = id;
      }
      color[root(id)] = x;
    } else {
      int x, y;
      cin >> x >> y;
      if (!prev[x]) continue;
      if (prev[y]) {
        unite(prev[y], prev[x]);
        color[root(prev[y])] = y;
      } else {
        color[root(prev[x])] = y;
      }
      prev[x] = 0;
    }
  }
  for (int i = 1; i <= id; ++i) cout << color[root(i)] << ' ';
  cout << '\n';
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
