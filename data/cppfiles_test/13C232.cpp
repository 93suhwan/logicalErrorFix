#include <bits/stdc++.h>
using namespace std;
const int N = 2000110;
const int P = 998244353;
char mp[111][111];
bool vis[26];
vector<int> dx = {0, 1, -1, 0};
vector<int> dy = {1, 0, 0, -1};
char fdc(int sx, int sy, int ex, int ey) {
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 4; ++i) {
    int tx = sx + dx[i];
    int ty = sy + dy[i];
    if (mp[tx][ty]) vis[mp[tx][ty] - 'a'] = 1;
  }
  for (int i = 0; i < 4; ++i) {
    int tx = ex + dx[i];
    int ty = ey + dy[i];
    if (mp[tx][ty]) vis[mp[tx][ty] - 'a'] = 1;
  }
  for (int i = (0); i <= (25); ++i)
    if (!vis[i]) return i + 'a';
  return 0;
}
void pt(int x, int y, int dr) {
  if (dr == 0) {
    char c = fdc(x, y, x, y + 1);
    mp[x][y] = mp[x][y + 1] = c;
  } else {
    char c = fdc(x, y, x + 1, y);
    mp[x][y] = mp[x + 1][y] = c;
  }
}
void draw(int n, int m, int k) {
  k /= 2;
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; j += 2) {
      if (k > 0) {
        pt(i, j, 0);
        pt(i + 1, j, 0);
        --k;
      } else {
        pt(i, j, 1);
        pt(i, j + 1, 1);
      }
    }
  }
}
void out(int n, int m) {
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (m); ++j) cout << mp[i][j];
    cout << "\n";
  }
}
void solve() {
  memset(mp, 0, sizeof(mp));
  int n, m, k;
  cin >> n >> m >> k;
  int tn = n, tm = m;
  if (n % 2 == 0 && m % 2 == 0) {
    if (k % 2 == 0) {
      cout << "YES\n";
      draw(n, m, k);
      out(tn, tm);
    } else {
      cout << "NO\n";
    }
    return;
  } else {
    if (n % 2 == 1) {
      int h = m / 2;
      if (k < h) {
        cout << "NO\n";
        return;
      }
      k -= h;
      for (int i = 1; i <= m; i += 2) pt(n, i, 0);
      n--;
      if (k % 2 == 0 && n * m / 2 >= k) {
        cout << "YES\n";
        draw(n, m, k);
        out(tn, tm);
      } else {
        cout << "NO\n";
      }
      return;
    } else {
      for (int i = 1; i <= n; i += 2) pt(i, m, 1);
      m--;
      if (k % 2 == 0 && n * m / 2 >= k) {
        cout << "YES\n";
        draw(n, m, k);
        out(tn, tm);
      } else {
        cout << "NO\n";
      }
      return;
    }
  }
  cout << "NO\n";
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    solve();
  }
}
