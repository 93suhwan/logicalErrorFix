#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, char>>> g;
vector<bool> vis;
vector<int> color;
void dfs(long long v, long long& cnt1, long long& cnt2) {
  vis[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    long long a = g[v][i].first;
    char c = g[v][i].second;
    if (color[a]) {
      if (c == 'i' && color[a] == color[v] ||
          c == 'c' && color[a] != color[v]) {
        cnt1 = cnt2 = -1;
        return;
      }
    } else {
      if (c == 'i' && color[v] == 1) color[a] = 2;
      if (c == 'i' && color[v] == 2) color[a] = 1;
      if (c == 'c') color[a] = color[v];
      if (color[a] == 1)
        ++cnt1;
      else
        ++cnt2;
    }
    if (!vis[a]) dfs(a, cnt1, cnt2);
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  g = vector<vector<pair<long long, char>>>(n + 1);
  vis = vector<bool>(n + 1, false);
  color = vector<int>(n + 1, 0);
  while (m--) {
    long long i, j;
    string c;
    cin >> i >> j >> c;
    g[i].push_back({j, c[0]});
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      long long cnt1 = 1, cnt2 = 0;
      color[i] = 1;
      dfs(i, cnt1, cnt2);
      if (cnt1 == -1) {
        cout << "-1\n";
        return;
      }
      ans += max(cnt1, cnt2);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
