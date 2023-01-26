#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int inf = 2e9;
int n, m, cnt, total;
vector<pair<int, int> > g[maxn];
bool vis[maxn], can;
bool color[maxn];
void dfs(int i, bool c) {
  vis[i] = 1;
  total++;
  cnt += c;
  color[i] = c;
  for (auto child : g[i]) {
    if (!vis[child.first]) {
      dfs(child.first, (child.second ? c : !c));
    } else if (color[child.first] != (child.second ? c : !c)) {
      can = 0;
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    g[i].clear();
    vis[i] = 0;
    color[i] = 0;
  }
  map<pair<int, int>, int> ma;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    string s;
    cin >> s;
    if (ma.count(make_pair(u, v)) && ma[make_pair(u, v)] != (s[0] == 'c')) {
      cout << -1 << '\n';
      return;
    }
    ma[make_pair(u, v)] = (s[0] == 'c');
  }
  for (auto x : ma) {
    g[x.first.first].push_back(make_pair(x.first.second, x.second));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cnt = 0;
      total = 0;
      can = 1;
      dfs(i, 1);
      if (can == 0) {
        cout << -1 << '\n';
        return;
      }
      ans += max(cnt, total - cnt);
    }
  }
  cout << ans << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
