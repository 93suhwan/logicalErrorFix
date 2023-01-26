#include <bits/stdc++.h>
const long long N = 2e5 + 5, INF = 1e12;
long long n, x, y, z, ans, k, q, m;
long long a[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    string s[n];
    for (long long i = 0; i < n; i++) {
      cin >> s[i];
    }
    queue<array<long long, 2>> q;
    long long vis[n][m];
    memset(vis, 0, sizeof(vis));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == 'L') {
          if (i + 1 < n && s[i + 1][j] == '.') q.push({i + 1, j});
          if (i - 1 >= 0 && s[i - 1][j] == '.') q.push({i - 1, j});
          if (j + 1 < m && s[i][j + 1] == '.') q.push({i, j + 1});
          if (j - 1 >= 0 && s[i][j - 1] == '.') q.push({i, j - 1});
        }
      }
    }
    while (!q.empty()) {
      array<long long, 2> node = q.front();
      x = node[0];
      y = node[1];
      vis[x][y] = 1;
      q.pop();
      long long ch = 0;
      if (x + 1 < n && s[x + 1][y] == '.' && !vis[x + 1][y]) ch++;
      if (x - 1 >= 0 && s[x - 1][y] == '.' && !vis[x - 1][y]) ch++;
      if (y + 1 < m && s[x][y + 1] == '.' && !vis[x][y + 1]) ch++;
      if (y - 1 >= 0 && s[x][y - 1] == '.' && !vis[x][y - 1]) ch++;
      if (ch > 1) continue;
      s[x][y] = '+';
      if (x + 1 < n && s[x + 1][y] == '.' && !vis[x + 1][y]) q.push({x + 1, y});
      if (x - 1 >= 0 && s[x - 1][y] == '.' && !vis[x - 1][y])
        q.push({x - 1, y});
      if (y + 1 < m && s[x][y + 1] == '.' && !vis[x][y + 1]) q.push({x, y + 1});
      if (y - 1 >= 0 && s[x][y - 1] == '.' && !vis[x][y - 1])
        q.push({x, y - 1});
    }
    for (long long i = 0; i < n; i++) {
      cout << s[i] << "\n";
    }
  }
}
