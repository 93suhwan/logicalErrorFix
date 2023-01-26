#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char s[105][105];
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    while (1) {
      int r = n, c = m;
      int t = 0;
      if (r & 1) {
        for (int i = 1; i <= m; i += 2)
          s[n][i] = s[n][i + 1] = char(t + 'a'), t = rand() % 26;
        r--;
        k -= m / 2;
      } else if (c & 1) {
        for (int i = 1; i <= n; i += 2)
          s[i][m] = s[i + 1][m] = char(t + 'a'), t = rand() % 26;
        c--;
      }
      bool ok = k >= 0 && k <= r * c / 2 && (k % 2 == 0);
      int x = 1, y = 1;
      for (int i = 0; i < k; i += 2) {
        s[x][y] = s[x][y + 1] = char(t + 'a'), t = rand() % 26;
        s[x + 1][y] = s[x + 1][y + 1] = char(t + 'a'), t = rand() % 26;
        y += 2;
        if (y > c) y -= c, x += 2;
      }
      for (int i = 0; i < r * c / 2 - k; i += 2) {
        s[x][y] = s[x + 1][y] = char(t + 'a'), t = rand() % 26;
        s[x][y + 1] = s[x + 1][y + 1] = char(t + 'a'), t = rand() % 26;
        y += 2;
        if (y > c) y -= c, x += 2;
      }
      if (!ok) {
        cout << "NO\n";
        break;
      }
      bool ovr = true;
      for (int i = 1; i <= r; i += 2)
        for (int j = 1; j <= c; j += 2) {
          int cnt = 0;
          for (int o = 0; o < 4; o++) {
            int X = i + dx[o];
            int Y = j + dy[o];
            if (X >= 1 && X <= r && Y >= 1 && Y <= c) {
              if (s[X][Y] == s[i][j]) ++cnt;
            }
          }
          if (cnt > 1) ovr = false;
        }
      if (ovr) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) cout << s[i][j];
          cout << "\n";
        }
        break;
      }
    }
  }
}
