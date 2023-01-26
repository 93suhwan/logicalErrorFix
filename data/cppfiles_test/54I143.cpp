#include <bits/stdc++.h>
using namespace std;
void _debug() { cerr << '\n'; }
template <typename A, typename... B>
void _debug(A a, B... b) {
  cerr << a << ' ', _debug(b...);
}
const int oo = 2000000000;
const int mod = 1e9 + 7;
const int N = 3e5 + 5;
struct DJS {
  int p[N], r[N];
  void init(int n) {
    for (int i = 1; i <= 2 * n; i++) p[i] = i, r[i] = 1;
  }
  int root(int x) { return x == p[x] ? x : p[x] = root(p[x]); }
  void Union(int x, int y) {
    x = root(x), y = root(y);
    if (x == y) return;
    if (r[x] > r[y]) {
      r[x] += r[y];
      p[y] = x;
    } else {
      r[y] += r[x];
      p[x] = y;
    }
    return;
  }
} djs;
void solve() {
  int n, m;
  cin >> n >> m;
  djs.init(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;
    if (s[0] == 'c') {
      djs.Union(u, v);
      djs.Union(u + n, v + n);
      if (djs.root(u) == djs.root(u + n)) {
        cout << -1 << "\n";
        return;
      }
    } else {
      djs.Union(u, v + n);
      djs.Union(u + n, v);
      if (djs.root(u) == djs.root(u + n)) {
        cout << -1 << "\n";
        return;
      }
    }
  }
  int mx = 0, other = 0;
  vector<int> cnt(2 * n + 1);
  for (int i = n + 1; i <= 2 * n; i++) {
    if (i == djs.root(i) && djs.r[i] == 1) {
      other++;
    } else {
      cnt[djs.root(i)]++;
      mx = max(mx, cnt[djs.root(i)]);
    }
  }
  cout << mx + other << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
}
