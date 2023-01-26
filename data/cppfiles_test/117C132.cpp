#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
bool mycomp(T x, T y) {
  return (x == y);
}
bool paircomp(const pair<long long int, long long int> &x,
              const pair<long long int, long long int> &y) {
  return x.second < y.second;
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  string s[n];
  for (long long int i = 0; i < n; i++) cin >> s[i];
  long long int labx, laby;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (s[i][j] == 'L') labx = i, laby = j;
    }
  }
  bool vis[n][m];
  memset(vis, false, sizeof(vis));
  queue<pair<long long int, long long int> > qe;
  qe.push({labx, laby});
  vis[labx][laby] = true;
  while (!qe.empty()) {
    long long int x = qe.front().first, y = qe.front().second;
    qe.pop();
    if (s[x][y] != 'L') {
      long long int no = 0;
      if (x && s[x - 1][y] == '.') no++;
      if (x < n - 1 && s[x + 1][y] == '.') no++;
      if (y && s[x][y - 1] == '.') no++;
      if (y < m - 1 && s[x][y + 1] == '.') no++;
      if (no <= 1)
        s[x][y] = '+', vis[x][y] = true;
      else
        continue;
    }
    if (x && !vis[x - 1][y] && s[x - 1][y] != '#') qe.push({x - 1, y});
    if (x < n - 1 && !vis[x + 1][y] && s[x + 1][y] != '#') qe.push({x + 1, y});
    if (y && !vis[x][y - 1] && s[x][y - 1] != '#') qe.push({x, y - 1});
    if (y < m - 1 && !vis[x][y + 1] && s[x][y + 1] != '#') qe.push({x, y + 1});
  }
  for (long long int i = 0; i < n; i++) {
    cout << s[i] << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
