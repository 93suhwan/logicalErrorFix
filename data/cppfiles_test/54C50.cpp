#include <bits/stdc++.h>
using namespace std;
void _debug() { cerr << '\n'; }
template <typename A, typename... B>
void _debug(A a, B... b) {
  cerr << a << ' ', _debug(b...);
}
const int oo = 2000000000;
const int N = 2e5 + 5;
int p[2 * N], imp[2 * N], rk[2 * N], vis[2 * N];
struct DJS {
  void init(int n) {
    for (int i = 1; i <= n; i++) p[i] = i, rk[i] = 1;
  }
  int root(int x) { return x == p[x] ? x : p[x] = root(p[x]); }
  void Union(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (rk[x] > rk[y]) {
      rk[x] += rk[y];
      imp[x] += imp[y];
      p[y] = x;
    } else {
      rk[y] += rk[x];
      imp[y] += imp[x];
      p[x] = y;
    }
  }
} djs;
void solve() {
  int n, m;
  cin >> n >> m;
  djs.init(2 * n);
  fill(imp, imp + 2 * n + 1, 0);
  fill(vis, vis + 2 * n + 1, 0);
  for (int i = n + 1; i <= 2 * n; i++) imp[i] = 1;
  for (int i = 1; i <= m; i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    if (s[0] == 'c') {
      djs.Union(u, v);
      djs.Union(u + n, v + n);
    } else {
      djs.Union(u + n, v);
      djs.Union(u, v + n);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (djs.root(i) == djs.root(i + n)) {
      cout << -1 << '\n';
      return;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[djs.root(i)]) continue;
    vis[djs.root(i)] = vis[djs.root(i + n)] = 1;
    int a = imp[djs.root(i)], b = imp[djs.root(i + n)];
    ans += max(a, b);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
