#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5, lg = 20;
long long int dx[2] = {0, -1};
long long int dy[2] = {-1, 0};
void runcases(long long int T) {
  long long int n, m;
  cin >> n >> m;
  vector<vector<long long int>> v(n, vector<long long int>(m, 0));
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '.') {
        v[i][j] = 1;
      }
    }
  }
  long long int a[m];
  memset(a, -1, sizeof(a));
  for (long long int j = m - 1; j >= 0; j--) {
    if (a[j] != -1) continue;
    queue<vector<long long int>> q;
    for (long long int i = 0; i < n; i++) {
      if (v[i][j] == 1) {
        q.push({i, j, j});
      }
    }
    while (q.size()) {
      long long int ns = q.size();
      while (ns--) {
        vector<long long int> ds = q.front();
        q.pop();
        v[ds[0]][ds[1]] = 2;
        a[ds[1]] = max(a[ds[1]], ds[2]);
        for (long long int k = 0; k < 2; k++) {
          long long int x = ds[0] + dx[k];
          long long int y = ds[1] + dy[k];
          if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] == 1) {
            q.push({x, y, ds[2]});
          }
        }
      }
    }
  }
  long long int qx;
  cin >> qx;
  while (qx--) {
    long long int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (a[x] < y) {
      cout << "NO\n";
    } else
      cout << "YES\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T = 1;
  for (long long int t = 1; t <= T; t++) {
    runcases(t);
  }
  return 0;
}
