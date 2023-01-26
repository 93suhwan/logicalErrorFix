#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<pair<int, int> > adj[502][502];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int a[502][502];
bitset<502> vis[502];
void dfs(int i, int j, bool f) {
  vis[i][j] = 1;
  if (f)
    a[i][j] = 1;
  else
    a[i][j] = 4;
  for (auto it : adj[i][j]) {
    if (!vis[it.first][it.second]) dfs(it.first, it.second, !f);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (s[i][j] == '.') continue;
      vector<pair<int, int> > v;
      for (int k = 0; k < 4; ++k) {
        if (s[i + dx[k]][j + dy[k]] == '.')
          v.emplace_back(i + dx[k], j + dy[k]);
      }
      if (v.size() & 1) {
        cout << "NO\n";
        return 0;
      }
      a[i][j] = (v.size() / 2) * 5;
      if (v.size() == 0) continue;
      for (int k = 0; k < v.size(); k += 2) {
        adj[v[k].first][v[k].second].emplace_back(v[k + 1].first,
                                                  v[k + 1].second);
        adj[v[k + 1].first][v[k + 1].second].emplace_back(v[k].first,
                                                          v[k].second);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'X') continue;
      if (!vis[i][j]) dfs(i, j, 0);
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << a[i][j] << " ";
    cout << "\n";
  }
}
