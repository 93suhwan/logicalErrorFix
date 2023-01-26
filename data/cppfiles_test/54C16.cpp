#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 99;
int n, t, m, ck, a[N], col[N], d[2], mark[N];
vector<pair<int, int> > g[N];
void dfs(int x) {
  mark[x] = 1;
  d[col[x]]++;
  for (int i = 0; i < g[x].size(); i++) {
    if (!mark[g[x][i].first]) {
      col[g[x][i].first] = col[x] ^ g[x][i].second;
      dfs(g[x][i].first);
    }
    if (col[g[x][i].first] != (col[x] ^ g[x][i].second)) ck = 1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int ans = 0;
    ck = 0;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) g[i].clear(), mark[i] = 0;
    for (int i = 0; i < m; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      g[u].push_back(make_pair(v, (s[0] == 'i')));
      g[v].push_back(make_pair(u, (s[0] == 'i')));
    }
    for (int i = 1; i < n + 1; i++) {
      d[0] = d[1] = 0;
      if (!mark[i]) {
        col[i] = 0;
        dfs(i);
      }
      ans += max(d[0], d[1]);
    }
    if (ck)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
}
