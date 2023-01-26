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
    set<array<long long, 3>> q;
    long long vis[n][m];
    memset(vis, 0, sizeof(vis));
    long long surr[n][m];
    memset(surr, 0, sizeof(surr));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == '.') {
          if (i + 1 < n && s[i + 1][j] == '.') surr[i + 1][j]++;
          if (i - 1 >= 0 && s[i - 1][j] == '.') surr[i - 1][j]++;
          if (j + 1 < m && s[i][j + 1] == '.') surr[i][j + 1]++;
          if (j - 1 >= 0 && s[i][j - 1] == '.') surr[i][j - 1]++;
        } else if (s[i][j] == '#')
          surr[i][j] = INF;
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (s[i][j] == 'L') {
          if (i + 1 < n && s[i + 1][j] == '.')
            q.insert({surr[i + 1][j], i + 1, j});
          if (i - 1 >= 0 && s[i - 1][j] == '.')
            q.insert({surr[i - 1][j], i - 1, j});
          if (j + 1 < m && s[i][j + 1] == '.')
            q.insert({surr[i][j + 1], i, j + 1});
          if (j - 1 >= 0 && s[i][j - 1] == '.')
            q.insert({surr[i][j - 1], i, j - 1});
        }
      }
    }
    while (!q.empty()) {
      auto node = q.begin();
      long long wt;
      wt = (*node)[0];
      x = (*node)[1];
      y = (*node)[2];
      vis[x][y] = 1;
      q.erase(node);
      if (wt > 1) continue;
      s[x][y] = '+';
      if (x + 1 < n && s[x + 1][y] == '.') surr[x + 1][y]--;
      if (x - 1 >= 0 && s[x - 1][y] == '.') surr[x - 1][y]--;
      if (y + 1 < m && s[x][y + 1] == '.') surr[x][y + 1]--;
      if (y - 1 >= 0 && s[x][y - 1] == '.') surr[x][y - 1]--;
      if (x + 1 < n && s[x + 1][y] == '.' && !vis[x + 1][y])
        q.insert({surr[x + 1][y], x + 1, y});
      if (x - 1 >= 0 && s[x - 1][y] == '.' && !vis[x - 1][y])
        q.insert({surr[x - 1][y], x - 1, y});
      if (y + 1 < m && s[x][y + 1] == '.' && !vis[x][y + 1])
        q.insert({surr[x][y + 1], x, y + 1});
      if (y - 1 >= 0 && s[x][y - 1] == '.' && !vis[x][y - 1])
        q.insert({surr[x][y - 1], x, y - 1});
    }
    for (long long i = 0; i < n; i++) {
      cout << s[i] << "\n";
    }
  }
}
