#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void dfs(long long int i, long long int j, long long int l, long long int k,
         set<pair<long long int, long long int>> &s, vector<string> &a) {
  long long int n = a.size(), m = a[0].size();
  if (i < 0 || j < 0 || k < 0 || l < 0 || i >= n || l >= n || j >= m ||
      k >= m || a[i][j] != '*' || a[l][k] != '*') {
    return;
  }
  s.insert({i, j});
  s.insert({l, k});
  dfs(i - 1, j - 1, l - 1, k + 1, s, a);
}
void mkc() {
  long long int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (long long int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<long long int>> part(n, vector<long long int>(m, 0)),
      ori(n, vector<long long int>(m, 0));
  set<pair<long long int, long long int>> s;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      if (a[i][j] == '*') {
        dfs(i - 1, j - 1, i - 1, j + 1, s, a);
        if (s.size() >= 2 * k) {
          ori[i][j] = 1;
          for (auto e : s) {
            part[e.first][e.second] = 1;
          }
        }
        s.clear();
      }
    }
  }
  long long int st = 1;
  for (long long int i = 0; i < n; ++i) {
    for (long long int j = 0; j < m; ++j) {
      if (a[i][j] == '*') {
        if (!part[i][j] && !ori[i][j]) {
          st = 0;
          break;
        }
      }
      if (!st) break;
    }
    if (!st) break;
  }
  cout << ((st) ? "YES" : "NO") << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) mkc();
  return 0;
}
