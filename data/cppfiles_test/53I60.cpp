#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = 2 * acos(0.0);
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int inf = 2e9;
vector<pair<int, int> > g[maxn];
bool vis[maxn];
ll dp[maxn][2];
void dfs(int i) {
  vis[i] = 1;
  for (auto child : g[i]) {
    if (!vis[child.first]) {
      dfs(child.first);
      dp[i][1] += dp[child.first][child.second];
      dp[i][0] += dp[child.first][!child.second];
    }
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
    g[i].clear();
    dp[i][0] = 1;
    dp[i][1] = 0;
  }
  vector<int> income(n);
  map<pair<int, int>, bool> ma;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    string s1;
    cin >> s1;
    if (ma.count(make_pair(u, v))) {
      if (ma[make_pair(u, v)] != (s1[0] == 'c')) {
        cout << -1 << '\n';
        return;
      }
    } else {
      ma[make_pair(u, v)] = (s1[0] == 'c');
    }
  }
  for (auto x : ma) {
    g[x.first.first].push_back(make_pair(x.first.second, x.second));
    income[x.first.second]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
    if (income[i] == 0) {
      ll cnt = max(dp[i][0], dp[i][1]);
      if (cnt == 0) {
        cout << -1 << '\n';
        return;
      }
      ans += cnt;
    }
  }
  if (ans == 0) {
    cout << -1 << '\n';
    return;
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
