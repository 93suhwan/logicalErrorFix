#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 200005;
const int inf = 1e9 + 7;
int n;
unordered_map<int, vector<int> > a;
unordered_map<int, int> pos;
unordered_map<int, bool> vertex;
unordered_map<int, bool> vis;
string st;
int ans = -1;
pair<int, int> rs;
pair<int, int> dfs(int u) {
  if (vis[u]) return {-1e9, u};
  vis[u] = true;
  pair<int, int> t1 = {-1e9, u};
  if (vertex[u]) t1 = {0, u};
  if (a[u].size()) {
    for (int i = 0; i <= a[u].size() - 1; ++i) {
      pair<int, int> cur = dfs(a[u][i]);
      if (cur.first + t1.first > ans) {
        ans = cur.first + t1.first;
        rs = {cur.second, t1.second};
      }
      t1 = max(t1, cur);
    }
  }
  return {t1.first + 1, t1.second};
}
void Solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pos[x] = i;
    vertex[x] = true;
    while (x) {
      int k = 0;
      while ((1 << k) < x) {
        k++;
      }
      int u = (1 << k) - x;
      int v = x;
      assert(u < v);
      a[u].push_back(v);
      x = u;
    }
  }
  dfs(0);
  cout << pos[rs.first] << ' ' << pos[rs.second] << ' ' << ans;
}
int32_t main() {
  if (fopen("test.inp", "r"))
    freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int Test;
  Test = 1;
  for (int iTest = 1; iTest <= Test; ++iTest) {
    Solve();
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
